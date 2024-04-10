#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> g[26];
int a[26][26];
bool was[26];

vector<int> d;
void dfs(int v) {
	was[v] = 1;
	d.pb(v);
	for (int to : g[v]) if (!was[to]) dfs(to);
}

bool dp[1 << 20];
int to[26];
int ma[26];
int calc(vector<int>& d) {
	int ans = 0;
	for (int i = 0; i < (1 << d.size()); ++i) dp[i] = 0;
	dp[0] = 1;
	
	for (int i = 0; i < 26; ++i) to[i] = -1;
	for (int i = 0; i < d.size(); ++i) to[d[i]] = i;

	for (int v = 0; v < d.size(); ++v) {
		ma[v] = 0;
		for (int i = 0; i < 26; ++i) {
			if (a[d[v]][i] && to[i] != -1) {
				ma[v] ^= 1 << to[i];
			}
		}
	}

	for (int mask = 1; mask < (1 << d.size()); ++mask) {
		dp[mask] = 0;
		for (int v = 0; v < d.size(); ++v) if ((mask >> v) & 1) {
			if (dp[mask ^ (1 << v)] && (mask & ma[v]) == 0) {
				dp[mask] = 1;
				break;
			}
		}
	//	cout << dp[mask] << ' ' << mask << endl;
		if (dp[mask])
		ans = max(ans, __builtin_popcount(mask));
	}


//	cout << ans << ": ";
//	for (int v : d) cout << v << ' ';
//	cout << endl;

	return ans;
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s1, s2;
		cin >> s1 >> s1 >> s2;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				a[i][j] = 0;
			}
			g[i].clear();
			was[i] = false;
		}
		for (int i = 0; i < s1.size(); ++i) if (s1[i] != s2[i]) {
			a[s1[i] - 'a'][s2[i] - 'a'] = 1;
			g[s1[i] - 'a'].pb(s2[i] - 'a');
			g[s2[i] - 'a'].pb(s1[i] - 'a');
		}

		int ans = 0;

		for (int i = 0; i < 26; ++i) {
			d.clear();
			if (was[i]) continue;
			dfs(i);
			ans += d.size() * 2 - 1 - calc(d);
		}

		cout << ans << "\n";
	}

}