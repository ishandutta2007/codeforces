#include <bits/stdc++.h>
#define ll long long
#define maxn 2035 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int dp[maxn];
ll fr[maxn];
int n, k;
int a[maxn];
vector<vi> g;
bool check(vi a) {
	vi b;
	sort(a.begin(), a.end());
	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) {
			b.pb(a.size() - i);
			if (b.size() > 100) return 0;
		}
	} 
	sort(b.begin(), b.end());
//	ll ans = 0;
	ll ans = 0;
	for (int i = b.size() - 1; i >= 0; i--) 
		ans += (b.size() - i) * b[i];
	if (ans <= n) return 1;
	return 0;
} 
bool dfs(int pl, int s) {
	if (pl >= 2) {
		vi cur;
		for (int j = 1; j < pl; j++)
			cur.pb(a[j]);
		if (!check(cur)) return 0;
		g.pb(cur);
	}
	int l = a[pl - 1];
	for (int m = 1; m <= l && m <= 70 - s; m++) {
		a[pl] = m;
		if (!dfs(pl + 1, s + m)) break;
	}
	return 1;
}
vector<vi> s; 
/*
const ll md = 19260817 * mod;
int base = maxn;
ll has(vi g) {
	for (int i = 0; i < g.size(); i++)
}
*/
map<vi, int> u;
vi gt(vi x) {
	sort(x.begin(), x.end());
	vi fn;
	for (int i = 0; i < x.size(); ) {
		int j = i;
		while (j < x.size() && x[j] == x[i]) j++;
		fn.pb(j - i);
		i = j;
	}
	sort(fn.begin(), fn.end());
	return fn;
}
ll dd[maxn][maxn], ed[maxn][maxn];
int main() {
	cin >> n >> k;
	if (k >= 20) cout << 1 << endl;
	else {
		if (k == 1) {
			dp[0] = 1;
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					fr[k] = dp[k];
					if (k >= j) fr[k] += fr[k - j];
				}
				for (int k = 0; k <= n; k++)
					dp[k] = fr[k] % mod;
			}
			ll ans = 0;
			for (int j = 1; j <= n; j++)
				ans += dp[j];
			ans %= mod;
			cout << ans << endl;
			return 0;
		}
		if (k == 2) {
			for (int j = 0; j <= 100; j++) {
				if (j == 0) {
					for (int j = 0; j <= n; j++)
						dd[0][j] = 1;
				}
				else {
					int ls = n;
					if (j) ls = n / (j - 1);
					for (int s = n; s >= 0; s--) 
						for (int l = 0; l <= s / j; l++) {
							if (l * (j - 1) > s - l * j) ed[s][l] = 0;
							else ed[s][l] = dd[s - l * j][l];
						}
				//	if (j == 2) cout << ed[4][2] << ' ' << dd[0][2] << endl;
					for (int s = n; s >= 0; s--) {
						dd[s][s / j + 1] = 0;
						for (int l = s / j; l >= 0; l--)
							dd[s][l] = dd[s][l + 1] + ed[s][l], 
							dd[s][l] %= mod;
					}
				}
			/*	if (j)
				for (int s = 0; s <= n; s++)
					for (int l = 0; l <= s / j; l++)
						cout << s << ' ' << l << ' ' << dd[s][l] << endl;
			*/}
			ll ans = 0;
			for (int j = 1; j <= n; j++)
				ans += dd[j][0];
			ans %= mod;
			cout << ans << endl;
		} 
		else {
			a[0] = n;
			dfs(1, 0);
		//	cout << "AF" << endl;
			int ans = 0;
			for (auto v : g) {
				sort(v.begin(), v.end());
				for (int i = 0; i < k - 3; i++)
					v = gt(v);
			//	cout << "AF" << endl;
				if (!u[v]) u[v] = 1, ans++;
	 		}
	 		cout << ans << endl;
	 	}
	}
	return 0;
}
/*
CHHOCH
*/