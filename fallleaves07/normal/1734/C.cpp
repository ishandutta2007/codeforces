#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> tag(n + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			tag[i + 1] = -1;
		} else {
			tag[i + 1] = 1;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (tag[j] == -1) {
				break;
			}
			if (tag[j] == 1) {
				ans += i;
				tag[j] = 0;
			}
		}
	}
	printf("%lld\n", ans);
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