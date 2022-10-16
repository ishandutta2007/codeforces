#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k, x;
	cin >> n >> k >> x;
	int cnt = 0;	
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (i >= n-k) {
			cnt += min(x,t);
		} else {
			cnt += t;
		}
	}
	cout << cnt;
	return 0;
}