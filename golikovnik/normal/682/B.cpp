#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	vector<int> a(n); for (int &x: a) cin >> x;
	sort(all(a));
	int mex = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= mex) ++mex;
	}
	cout << mex << "\n";
	return 0;
}