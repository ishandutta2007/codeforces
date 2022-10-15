#include <bits/stdc++.h>
using namespace std;

#define MAXLEN 200005
int len;

string transform(string s) {
	int sz = s.size();
	if (sz % 2 == 1) return s;
	string a = transform(s.substr(0, sz / 2));
	string b = transform(s.substr(sz / 2, sz / 2));
	if (a > b) swap(a, b);
	return a + b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("B.in", "r", stdin);
	// freopen("B.out", "w", stdout);

	string x, y;
	cin >> x >> y;

	bool ans = transform(x) == transform(y);

	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}