#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10, INF = 2 * 1e4;
int t,n,k,z;
int a[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k >> z;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int ans = a[1], best = -INF, sum = a[1];
		for(int i = 2; i <= k + 1; ++i) {
			sum += a[i];
			int lft = k - (i - 1);
			if(lft % 2 == 0) {
				ans = max(ans, sum + a[i] * min(z, lft/2) + a[i-1] * min(lft/2,z));
			} else {
				if(lft / 2 < z) {
					ans = max(ans, sum + (a[i] + a[i-1])*(lft/2) + a[i-1]);
				} else {
					ans = max(ans, sum + (a[i] + a[i-1]) * z);
				}
			}
			ans = max(ans, sum + min(z, lft/2) * best);
			best = max(best, a[i] + a[i-1]);
		}
		cout << ans << "\n";
	}
	
}