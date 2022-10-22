#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <assert.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int s13, s12, s23;
	cout << "? 1 3\n";
	cout.flush();
	cin >> s13;
	cout << "? 1 2\n";
	cout.flush();
	cin >> s12;
	cout << "? 2 3\n";
	cout.flush();
	cin >> s23;
	vector <int> v = { s13 - s23, s12 + s23 - s13, s13 - s12 };
	for (int i = 4; i <= n; i++) {
		cout << "? " << i - 1 << ' ' << i << '\n';
		cout.flush();
		int x;
		cin >> x;
		v.push_back(x - v.back());
	}
	cout << "! ";
	for (auto i : v)
		cout << i << ' ';
	cout << '\n';
	return 0;
}