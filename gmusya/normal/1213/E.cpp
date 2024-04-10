#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector <char> c;
	c.push_back('a'), c.push_back('b'), c.push_back('c');
	bool tf = false;
	string prob;
	cout << "YES\n";
	do {
		bool cor = true;
		c.push_back(c[0]);
		for (int i = 0; i < 3; i++) {
			string s;
			s += c[i];
			s += c[i + 1];
			if (s == s1 || s == s2) {
				cor = false;
				break;
			}
		}
		if (cor) {
			tf = true;
			prob += c[0];
			prob += c[1];
			prob += c[2];
			break;
		}
		c.pop_back();
	} while (next_permutation(c.begin(), c.end()));
	if (tf) {
		for (int i = 0; i < n; i++)
			cout << prob;
		return 0;
	}
	if (s1[1] == s2[1]) {
		char k0 = s1[0];
		char k1 = s1[1];
		char k2 = 3 - ((k0 - 'a') + (k1 - 'a')) + 'a';
		for (int i = 0; i < n; i++)
			cout << k1;
		for (int i = 0; i < n; i++)
			cout << k2;
		for (int i = 0; i < n; i++)
			cout << k0;
		return 0;
	}
	if (s1[0] == s2[0]) {
		char k0 = s1[0];
		char k1 = s1[1];
		char k2 = 3 - ((k0 - 'a') + (k1 - 'a')) + 'a';
		for (int i = 0; i < n; i++)
			cout << k1;
		for (int i = 0; i < n; i++)
			cout << k2;
		for (int i = 0; i < n; i++)
			cout << k0;
		return 0;
	}
	char k0 = s1[0];
	char k1 = s1[1];
	char k2 = 3 - ((k0 - 'a') + (k1 - 'a')) + 'a';
	for (int i = 0; i < n; i++)
		cout << k0;
	for (int i = 0; i < n; i++)
		cout << k2;
	for (int i = 0; i < n; i++)
		cout << k1;
	return 0;
}