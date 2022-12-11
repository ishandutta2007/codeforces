#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;
int a[13][2002];

int dp[1 << 4][111];

int ans[1 << 4][111];

void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= m; j++) dp[i][j] = 0;

	for (int j = 0; j < m; j++){
		for (int dd = 0; dd < n; dd++){
			for (int mask = 0; mask < (1 << n); mask++){
				int now = 0;
				for (int i = 0; i < n; i++) if ((mask >> i) & 1) now += a[i][j];
				dp[mask][j] = max(dp[mask][j], now);
			}
			int save = a[0][j];
			for (int i = 0; i - 1 < n; i++) a[i][j] = a[i + 1][j];
			a[n - 1][j] = save;
		}
	}

	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= m; j++) ans[i][j] = -1;

	ans[0][0] = 0;

	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << n); mask++){
			int cur_mask = mask;
			while(1){
				if (ans[cur_mask][i] != -1) ans[mask][i + 1] = max(ans[mask][i + 1], ans[cur_mask][i] + dp[mask ^ cur_mask][i]);
				if (cur_mask == 0) break;
				cur_mask = (cur_mask - 1) & mask;
			}
		}
	}

	//cout << ans[1][1] << endl;

	cout << ans[(1 << n) - 1][m] << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}

}