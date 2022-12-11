#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> t[300007];
int dp[300007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		static const int INF = 1e9;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i], t[a[i]].pb(i);
		for (int i = 1; i <= n; ++i) dp[i] = INF;

		for (int i = 1; i <= n; ++i) if (t[i].size() > 0) {
			sort(all(t[i]));
			int ma = max(t[i][0], n - t[i].back() - 1);
			for (int j = 1; j < t[i].size(); ++j) {
				ma = max(ma, t[i][j] - t[i][j - 1] - 1);
			}
			++ma;
			dp[ma] = min(dp[ma], i);
		}

		for (int i = 0; i <= n; ++i) t[i].clear();
		int mi = dp[1];
		for (int i = 1; i <= n; ++i) {
			mi = min(mi, dp[i]);
			if (mi == INF) cout << "-1 "; else 
			cout << mi << ' ';
		}
		cout << "\n";
	}
}