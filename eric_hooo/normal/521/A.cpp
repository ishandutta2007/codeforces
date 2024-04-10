#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int cnt[4];

int main () {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		int x = s[i] == 'A' ? 0 : s[i] == 'G' ? 1 : s[i] == 'T' ? 2 : 3;
		cnt[x]++;
	}
	int maxj = max(max(cnt[0], cnt[1]), max(cnt[2], cnt[3]));
	int tot = (cnt[0] == maxj) + (cnt[1] == maxj) + (cnt[2] == maxj) + (cnt[3] == maxj);
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans = ans * tot % mod;
	}
	cout << ans << endl;
	return 0;
}