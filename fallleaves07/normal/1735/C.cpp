#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> nxt(26, -1);
	vector<bool> vis(26, false);
	auto check = [&]() {
		vector<bool> inc(26, false);
		vector<int> deg(26);
		for (int i = 0; i < 26; i++) {
			if (nxt[i] != -1) {
				++deg[nxt[i]];
			}
		}
		for (int i = 0; i < 26; i++) {
			if (deg[i] == 0 && !inc[i]) {
				for (int v = i; v != -1; v = nxt[v]) {
					inc[v] = true;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			if (deg[i] == 1 && !inc[i]) {
				int len = 0;
				for (int v = i; !inc[v]; v = nxt[v]) {
					inc[v] = true, ++len;
				}
				if (len != 26) {
					return false;
				}
			}
		}
		return true;
	};
	for (int i = 0; i < n; i++) {
		if (nxt[s[i] - 'a'] == -1) {
			for (int j = 0; j < 26; j++) {
				if (!vis[j]) {
					nxt[s[i] - 'a'] = j;
					if (check()) {
						vis[j] = true;
						break;
					}
				}
			}
		}
		putchar(nxt[s[i] - 'a'] + 'a');
	}
	puts("");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}