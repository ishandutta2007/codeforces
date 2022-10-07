#include<iostream>
#include<string>
using namespace std;
int main() {
	string a, b;
	int n;
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << a << " " << b << endl;
		string p, q;
		cin >> p >> q;
		if (a == p)a = q;
		else b = q;
	}
	cout << a << " " << b << endl;
	return 0;
}