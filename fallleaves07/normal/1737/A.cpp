#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> cnt(26, 0), tot(k), ch(k, -1);
	for (int i = 0; i < n; i++) {
		++cnt[s[i] - 'a'];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 25 && tot[i] < n / k; j++) {
			if (cnt[j] > 0) {
				++tot[i], --cnt[j];
				ch[i] = j + 1;
			} else {
				ch[i] = j;
				break;
			}
		}
		if (ch[i] == -1) {
			ch[i] = 25;
		}
		putchar(ch[i] + 'a');
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