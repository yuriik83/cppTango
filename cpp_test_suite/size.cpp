/* 
 * Check size of user classes/structure (For compatibility prurpose)
 *
 * This test suite has to be run on a redhate4 host
 * Otherwise, you have to change the classes/structures size
 *
 */

#include <tango.h>

void check_size(const char *,long,long);

#define	coutv	if (verbose == true) cout

bool verbose = false;

using namespace Tango;
using namespace std;

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		if (strcmp(argv[1],"-v") == 0)
			verbose = true;
	}

	check_size("Attr",sizeof(Attr),56);  // Was 52 in V4
	check_size("SpectrumAttr",sizeof(SpectrumAttr),64);	// Was 60 in V4	
	check_size("ImageAttr",sizeof(ImageAttr),72);	// Was 68 in V4
		
	check_size("DeviceImpl",sizeof(DeviceImpl),296);
	check_size("Device_2Impl",sizeof(Device_2Impl),304);
	
	check_size("DeviceClass",sizeof(DeviceClass),88);  	// Was 48 in V4
	check_size("Util",sizeof(Util),72);	// Was 68 in V4

	check_size("Attribute",sizeof(Attribute),332);		// Was 208 in V4
	check_size("WAttribute",sizeof(WAttribute),616);	// Was 252 in V4
	check_size("MultiAttribute",sizeof(MultiAttribute),40);
	
	check_size("Command",sizeof(Command),32);
	check_size("TemplCommand",sizeof(TemplCommand),52);
	check_size("TemplCommandIn",sizeof(TemplCommandIn<int>),64);
	check_size("TemplCommandOut",sizeof(TemplCommandOut<void>),64);
	check_size("TemplCommandInOut",sizeof(TemplCommandInOut<int,int>),64);

	check_size("DeviceProxy",sizeof(DeviceProxy),164);	// Was 100 in V4
	check_size("DeviceData",sizeof(DeviceData),12);
	check_size("DeviceDataHistory",sizeof(DeviceDataHistory),44);
	check_size("DeviceAttribute",sizeof(DeviceAttribute),80);	// Was 52 in V4
	check_size("DeviceAttributeHistory",sizeof(DeviceAttributeHistory),104);   // Was 76 in V4

	check_size("ApiUtil",sizeof(ApiUtil),144);				
	check_size("Database",sizeof(Database),180);    // Was 108 in V4
	check_size("DbDevice",sizeof(DbDevice),20);
	check_size("DbClass",sizeof(DbClass),20);
	check_size("DbServer",sizeof(DbServer),20);
	check_size("DbDatum",sizeof(DbDatum),32);
	check_size("DbData",sizeof(DbData),12);
	
	check_size("CmdDoneEvent",sizeof(CmdDoneEvent),24);
	check_size("AttrReadEvent",sizeof(AttrReadEvent),24);
	check_size("AttrWrittenEvent",sizeof(AttrWrittenEvent),20);
	check_size("CallBack",sizeof(CallBack),8);

	check_size("EncodedAttribute",sizeof(EncodedAttribute),32);

	check_size("Group",sizeof(Group),2);

	check_size("MultiAttrProp<T>",sizeof(MultiAttrProp<DevShort>),284);
	check_size("AttrProp<T>",sizeof(AttrProp<DevShort>),16);
	check_size("DoubleAttrProp<T>",sizeof(DoubleAttrProp<DevShort>),24);
}

void check_size(const char *class_name,long class_size,long std_size)
{
	coutv << "Size of " << class_name << " = " << class_size << endl;
	if (std_size == class_size)
		cout << "   Size of " << class_name << " --> OK" << endl;
	else
		cout << "   Size of " << class_name << " should be " << std_size << " and is " << class_size << " --> NOK !!!!!!!!!!!" << endl;
}


