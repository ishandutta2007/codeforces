#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t(x.size())

using namespace std;

const int MAX = 1000000000ll * 100000ll;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	set<int> kvalues;
	if (llabs(k) == 1) {
		kvalues.insert(k);
		kvalues.insert(k * k);
	} else {
		int curk = 1;
		while (llabs(curk) <= MAX) {
			kvalues.insert(curk);
			curk *= k;
		}
	}
	map<int, int> cnt;
	++cnt[0];
	int ans = 0;
	int curpref = 0;
	for (int i = 0; i < n; ++i) {
		curpref += a[i];
		++cnt[curpref];
		for (int kpow: kvalues) {
			ans += cnt[curpref - kpow];
		}
	}
	cout << ans << "\n";
	return 0;	
}