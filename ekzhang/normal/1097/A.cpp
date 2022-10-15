#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

bool chk(string a) {
	string b;
	cin >> b;
	return a[0] == b[0] || a[1] == b[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	string s;
	cin >> s;
	bool b = chk(s) || chk(s) || chk(s) || chk(s) || chk(s);
	cout << (b ? "YES" : "NO") << endl;

	cout.flush();
	return 0;
}