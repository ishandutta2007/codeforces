#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int A, B;

int main() {
	cin >> A >> B;
	if (B == A+1)
		cout << A << " " << B;
	else if (B == A)
		cout << A << "0 " << B << "1 ";
	else if (B == 1 && A == 9)
		cout << "9 10";
	else
		cout << "-1";
	cout << endl;
}