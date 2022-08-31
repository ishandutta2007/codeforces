#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	int n = nxt();
	cin >> s;
	string t = "";
	int l = 0, r = n;
	while (l < n && s[l] == '0') {
		t += '0';
		++l;
	}
	while (r > 0 && s[r - 1] == '1') {
		t += '1';
		--r;
	}
	if (l < r) {
		t = '0' + t;
	}
	cout << t << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}