#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

const int MAXN = 301;
const int INF = 1e9 + 7;
const int BASE = 129;
const int MOD = 1000 * 1000 * 1000 + 7;

string a[MAXN];
int h[MAXN];

int mod(int n) {
	return (n % MOD + MOD) % MOD;
}
 
bool check(int l1, int l2, int len) {
	for (int i = 0; i < len; ++i) {
		if (h[l1 + i] != h[l2 + i]) return 0;
	}
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	for (int i = 0; i < n; ++i) {
	    for (char c : a[i]) {
			h[i] = mod(h[i] * BASE + c);
	    }
	}
	 	
	int all = 0;
	for (int i = 0; i < n; ++i) {
		all += a[i].size();
	}

	int ans = all + n - 1;
	for (int l = 0; l < n; ++l) {
	 	for (int r = l; r < n; ++r) {
	 	 	int len = r - l + 1;
			
			int u = r + 1;
			int k = 1;
			while (u + len - 1 < n) {
				if (check(l, u, len)) {
					u += len;
					++k;				 	
				}
				else {
				 	++u;
				}
			}

			if (k == 1) continue;

			int sum = 0;
			for (int i = l; i <= r; ++i) {
				sum += a[i].size();
			}

			int nn = n - len * k + k;
			ans = min(ans, (nn - 1) + (all - sum * k + len * k));
	 	}
	}
	
	cout << ans << '\n';
    return 0;
}