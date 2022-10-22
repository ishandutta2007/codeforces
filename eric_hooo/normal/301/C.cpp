#include <bits/stdc++.h>
using namespace std;
int main() {
	string s = (string)"\
9??" + (string)">>??" + (string)"0\n\
0??" + (string)"<>1\n\
1??" + (string)"<>2\n\
2??" + (string)"<>3\n\
3??" + (string)"<>4\n\
4??" + (string)"<>5\n\
5??" + (string)"<>6\n\
6??" + (string)"<>7\n\
7??" + (string)"<>8\n\
8??" + (string)"<>9\n\
??" + (string)"<>1\n\
?0>>0?\n\
?1>>1?\n\
?2>>2?\n\
?3>>3?\n\
?4>>4?\n\
?5>>5?\n\
?6>>6?\n\
?7>>7?\n\
?8>>8?\n\
?9>>9?\n\
?>>??" + (string)"\n\
>>?\
";
	cout << s << endl;
/* // my code
	for (int i = 0; i < 10; i++) {
		cout << "?" << i << ">>" << i << "?" << endl;
	}
	for (int i = 0; i < 8; i++) {
		cout << i << "9?>>" << i + 1 << "??" << endl;
	}
	cout << "89??" << ">>" << "90??" << endl;
	cout << "89?<>" << "90" << endl;
	cout << "9?>>??" << endl;
	for (int i = 0; i < 9; i++) {
		cout << i << "???" << ">>" << i << "0??" << endl;
	}
	for (int i = 0; i < 9; i++) {
		cout << i << "??" << "<>" << i << "0" << endl;
	}
	cout << "??" << ">>1??" << endl;
	for (int i = 0; i < 9; i++) {
		cout << i << "?<>" << i + 1 << endl;
	}
	printf(">>?\n");
*/
	return 0;
}