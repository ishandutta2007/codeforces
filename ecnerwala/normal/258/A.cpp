/*
ID: he.andr1
PROG: PrA
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void io(istream &in, ostream &out) {
	bool found0 = false;
	char next;
	in.get(next);
	while(next != '\n') {
		char cur = next;
		in.get(next);
		if(found0) {
			out.put(cur);
		} else if (cur == '0') {
			found0 = true;
		} else if (next != '\n') {
			out.put(cur);
		}
	}
	out.put('\n');
}

int main(){
//	ifstream fin ("PrA.in");
//	if(fin.good()) {
//		ofstream fout ("PrA.out");
//		io(fin, fout);
//		fout.close();
//	} else 
		io(cin, cout);
	return 0;
}