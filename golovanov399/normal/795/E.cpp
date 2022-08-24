#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	int m = nxt();

	vector<int> pref(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = (pref[i] * 10 + s[i] - '0') % m;
	}
	vector<int> deg(n + 1);
	deg[0] = 1;
	for (itn i = 1; i <= n; ++i) {
		deg[i] = deg[i - 1] * 10 % m;
	}
	vector<int> suf(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = (suf[i + 1] + (s[i] - '0') * deg[n - 1 - i]) % m;
	}

	int ans = m;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			continue;
		}
		ans = min(ans, (int)((1ll * suf[i] * deg[i] + pref[i]) % m));
	}

	printf("%d\n", ans);

	return 0;
}