#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 110, INF = 1e9;
int n;
int a[nax], b[nax];
double dp[2][nax * nax][nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> b[i] >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int s = 0; s <= 100 * n; ++s) {
			dp[0][s][i] = -INF;
			if(s != 0) dp[0][s][0] = -INF;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int s = 0; s <= 100 * n; ++s) {
			for(int ile = 0; ile <= n; ++ile) {
				dp[i & 1][s][ile] = dp[1 - (i & 1)][s][ile] + (double)a[i]/2.0;
				if(s >= b[i] && ile > 0) {
					dp[i & 1][s][ile] = max(dp[i&1][s][ile], dp[1-(i&1)][s - b[i]][ile - 1] + a[i]);
				}
				//if(ile == 1 && s <= 10) {
					//cout << i << " " << s << " " << dp[i&1][s][ile] << "\n";
				//}
			}
		}
	}
	cout << setprecision(10);
	cout << fixed;
	for(int k = 1; k <= n; ++k) {
		double ans = 0.0;
		for(int s = 0; s <= 100 * n; ++s) {
			//if(s <= 10) {
				//cout << s <<" " << k << " " << dp[n&1][s][k] << "\n";
			//}
			ans = max(ans, min((double)s, dp[n &1][s][k]));
		}
		cout << ans << " ";
	}
	
}