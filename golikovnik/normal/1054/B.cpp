#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int max_prev = -1;
	for (int i = 0; i < n; ++i) {
		int mex = a[i];
		if (mex > max_prev + 1) {
			cout << i + 1 << "\n";
			return 0l;
		}
		max_prev = max(max_prev, mex);
	}	
	cout << "-1\n";
	return 0;
}