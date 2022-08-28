#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];
bool f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		cin >> s;
		m = min(n, m);
		while (m--) {
			memset(f, 0, sizeof(f));
			for (int i = 0; i != n; ++i) if (s[i] == '1') {
				if (i) f[i - 1] ^= 1;
				f[i + 1] ^= 1;
			}
			for (int i = 0; i != n; ++i) if (f[i])
				s[i] = '1';
		}
		cout << s << '\n';
	}
	return 0;
}