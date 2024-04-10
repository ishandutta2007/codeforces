#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector <int> a(s.size());
	for (int i = 0; i < s.size(); i++)
		a[i] = s[i] - '0';
	if (s.size() < 7) {
		cout << "NO";
		return 0;
	}
	vector <int> b(s.size() - 6);
	b[0] = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
	for (int i = 1; i < b.size(); i++)
		b[i] = b[i - 1] - a[i - 1] + a[i + 6];
	bool tf = false;
	for (int i = 0; i < b.size(); i++)
		if (b[i] == 7 || b[i] == 0)
			tf = true;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}