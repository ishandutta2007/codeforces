/*input
0
1
1
0
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

bool f1(bool a, bool b){
	return a xor b;
}

bool f2(bool a, bool b){
	return a && b;
}

bool f3(bool a, bool b){
	return a || b;
}

int main () {
	bool a,b,c,d;
	cin >> a >> b >> c >> d;

	cout << f1(f2(f1(a,b),f3(c,d)),f3(f2(b,c),f1(a,d)));

	return 0;
}