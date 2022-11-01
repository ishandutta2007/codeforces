#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector <vector <int>> a(n + 1, vector <int>(26));
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1];
		a[i][s[i - 1] - 'a']++;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		bool tf = false;
		if (l == r)
			tf = true;
		if (s[l - 1] != s[r - 1])
			tf = true;
		int cnt = 0;
		for (int j = 0; j < 26; j++)
			cnt += (a[l - 1][j] != a[r][j]);
		if (cnt >= 3)
			tf = true;
		if (tf)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}