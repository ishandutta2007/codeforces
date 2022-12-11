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
int b[13][2002];
int a[13][22];
 
int dp[15][1 << 12];
 
int ans[15][1 << 12];

vector<pair<int, int> > was[100007];
 
void solve2(){
	cin >> n >> m;
	for (int i = 0; i < 100007; i++) was[i].clear();
	vector<pair<int, pair<int, int> > > t;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j], was[b[i][j]].pb({i, j});
	
	set<int> se;
	for (int i = 100000; i >= 0; i--){
		for (auto&& c : was[i]){
			se.insert(c.y);
			if (se.size() == n) break;
		}
		if (se.size() == n) break;
	}

	m = se.size();

	int dd = 0;
	for (int x : se){
		for (int i = 0; i < n; i++){
			a[i][dd] = b[i][x];
		}
		dd++;
	}

}

void solve(){
	solve2();

	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= m; j++) dp[j][i] = 0;

	for (int j = 0; j < m; j++){
		for (int dd = 0; dd < n; dd++){
			for (int mask = 0; mask < (1 << n); mask++){
				int now = 0;
				for (int i = 0; i < n; i++) if ((mask >> i) & 1) now += a[i][j];
				dp[j][mask] = max(dp[j][mask], now);
			}
			int save = a[0][j];
			for (int i = 0; i - 1 < n; i++) a[i][j] = a[i + 1][j];
			a[n - 1][j] = save;
		}
	}

 
	for (int i = 0; i < (1 << n); i++) for (int j = 0; j <= m; j++) ans[j][i] = -1;
 
	ans[0][0] = 0;
 
	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << n); mask++){
			int cur_mask = mask;
			while(1){
				if (ans[i][cur_mask] != -1) ans[i + 1][mask] = max(ans[i + 1][mask], ans[i][cur_mask] + dp[i][mask ^ cur_mask]);
				if (cur_mask == 0) break;
				cur_mask = (cur_mask - 1) & mask;
			}
		}
	}
 
	//cout << ans[1][1] << endl;
 
	cout << ans[m][(1 << n) - 1] << "\n";
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