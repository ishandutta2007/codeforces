#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(all(a));	
	int max_neg = LLONG_MIN / 2 , min_pos = LLONG_MAX / 2;
	int spos = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) spos += a[i];
		if (llabs(a[i]) % 2 == 1) {
			if (a[i] < 0) {
				max_neg = max(max_neg, a[i]);
			} else {
				min_pos = min(min_pos, a[i]);
			}
		}
	}
	if (llabs(spos) % 2 == 1) {
		cout << spos;
	} else {
		cout << max(spos + max_neg, spos - min_pos);
	}
	return 0;	
}