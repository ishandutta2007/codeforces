#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>
#define LL long long
#define ULL unsigned long long


using namespace std;

int main (){

	string s;
	getline (cin, s);
	int t1=0, t2=0, t3=0, t4=0;
	if (s.size()>=5) t1 = 1;
	for (int i=0; i<s.size(); i++){
		if (s[i] >='a' && s[i] <='z') t2 =1;
		if (s[i] >='A' && s[i] <='Z') t3 =1;
		if (s[i] >='0' && s[i] <='9') t4 =1;

	}
	if (t1+t2+t3+t4==4) cout << "Correct";
	else cout << "Too weak";
	return 0;
}