#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll has(ll a) {
	return a * a * 231237 + a * 1023119 + 3213117;
}
int n;
vi eg[maxn];
ll dp[maxn]; // a 
ll fr[maxn];
int dfn[maxn], sz[maxn];
int dfcnt = 0;
const ll dd = 307;
void dfs1(int a, int fa) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs1(v, a);
		sz[a] += sz[v];
		dp[a] += has(dp[v]);
	}
	dp[a] += dd;
}
void dfs2(int a, int fa) {
	if (fa) {
		fr[a] = dp[fa] - has(dp[a]);
		if (fa != 1) fr[a] += has(fr[fa]);
	}
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs2(v, a);
	}
}
int d[maxn];
void act(int l, int r) {
	if (l > r) return ;
	d[l]++, d[r + 1]--;
}
void upd(vector<pi> cur) {
	sort(cur.begin(), cur.end());
	int mx = 0;
	for (int i = 0; i < cur.size(); i++) {
		if (cur[i].fi > cur[i].se) continue;
		act(max(mx + 1, cur[i].fi), cur[i].se), 
		mx = max(mx, cur[i].se);
	}
}
vector<pair<ll, int> > chk;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
//	cout << fr[2] << endl;
	for (int i = 1; i <= n; i++)
		chk.pb(mp(dp[i], i));//, cout << i << ' ' << dp[i] << endl;
	for (int i = 2; i <= n; i++)
		chk.pb(mp(fr[i], -i));
	sort(chk.begin(), chk.end());
//	cout << "AF" << endl;
	for (int i = 0; i < chk.size(); ) {
	//	cout << i << ' ' << chk[i].fi << endl;
//	cout << "???" << i << endl;
		int j = i;
		while (j < chk.size() && chk[j].fi == chk[i].fi) j++;
		vector<pi> cur;
		for (int k = i; k < j; k++) {
			int id = chk[k].se;
		//	cout << id << ' ';
			if (id > 0)
				cur.pb(mp(1, dfn[id] - 1)), 
				cur.pb(mp(dfn[id] + sz[id], n));
			else 
				id = -id, 
				cur.pb(mp(dfn[id], dfn[id] + sz[id] - 1));
		}		
		upd(cur);
	//	cout << endl;
		i = j;
	}
	for (int i = 1; i <= n; i++)
		d[i] += d[i - 1];
	int ea = -1, epl = 0;
	for (int i = 1; i <= n; i++) {
		int na = d[dfn[i]];
		if (na > ea) ea = na, epl = i;
	}
//	cout << ea << endl;
	cout << epl << endl;
	return 0;
}