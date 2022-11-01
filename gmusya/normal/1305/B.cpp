#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector <int> o, c;
	int l = 0, r = s.size() - 1;
	while (l < r) {
		while (l < s.size() && s[l] == ')')
			l++;
		while (r >= 0 && s[r] == '(')
			r--;
		if (l < s.size() && r >= 0 && l < r) {
			o.push_back(l + 1);
			c.push_back(r + 1);
			l++;
			r--;
		}
	}
	if (o.size() == 0) {
		cout << "0";
		return 0;
	}
	cout << 1 << endl;
	cout << 2 * o.size() << endl;
	for (int i = 0; i < o.size(); i++)
		cout << o[i] << " ";
	for (int i = c.size() - 1; i >= 0; i--)
		cout << c[i] << " ";
	return 0;
}