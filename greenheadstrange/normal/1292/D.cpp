//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int mx[maxn], bpr[maxn];
int ncnt = 0;
vector<pi> eg[maxn];
int w[maxn];
int f[maxn], e[maxn];

ll ans[maxn];
ll in[maxn], s[maxn];
void dfs1(int a) {
	in[a] = ans[a] = s[a] = 0;
	s[a] = w[a];
	for (auto v : eg[a]) {
		dfs1(v.fi);
		s[a] += s[v.fi];
		in[a] += in[v.fi] + v.se * s[v.fi];
	}
//	cout << a << ' ' << in[a] << endl;
}
ll tot;
vi nx[maxn];
void dfs2(int a) {
	for (auto v : eg[a]) {
		ans[v.fi] = ans[a] + v.se * (tot - 2 * s[v.fi]);
		dfs2(v.fi); 
	}
}

void ade(int u, int v, int w) {
//	cout << "ADE" << u << ' ' << v << ' ' << w << endl;
	eg[u].pb(mp(v, w));
}
int cal(int u, int v) {
	int ans = 0;
	while (u % v == 0) u /= v, ans++;
	return ans;
}
int d[maxn];
int lb(int x) {
	return x & -x;
}
void upd(int a, int b) {
	while (a < maxn)
		d[a] += b, 
		a += lb(a);
}
int q(int a) {
	int ans = 0;
	while (a)
		ans += d[a], 
		a -= lb(a);
	return ans;
}
int ur[maxn], pr[maxn]; 
int dep[maxn];
int cnt; 
int st[maxn];
int main() {
	for (int i = 0; i < maxn; i++) bpr[i] = 1;
	for (int i = 2; i < maxn; i++)
		if (bpr[i]) {
			for (int j = 1; j * i < maxn; j++)
				bpr[j * i] = 0, 
				mx[j * i] = i, 
				nx[i * j].pb(i);
		}
	for (int i = 2; i < maxn; i++) {
		int cd = q(mx[i] - 1);
		ur[i] = 0;
		for (auto v : nx[i])
			ur[i] += cal(i, v);
		pr[i] = pr[i - 1] + ur[i];
		f[i] = cd + ur[i];
		for (auto v : nx[i]) {
			int tt = cal(i, v);
			upd(v, tt);
		}
	}
	int m = 5000;
//	while(scanf("%d", &m) != EOF) {
//		for (int i = 1; i <= m; i++)
//			scanf("%d", &w[i]);
	int n;
	cin >> n;
	while (n--) {
		int k;
		scanf("%d", &k);
		k = max(k, 1);
		w[k]++;
	} 
		for (int i = 1; i <= 2 * m; i++)
			eg[i].clear();
		cnt = m + 1;
		int top = 0;
		for (int i = 1; i <= m; i++) {
			dep[i] = pr[i];
		//	cout << i << ' ' <<dep[i] << endl;
			if (i == 1) st[top++] = i;
			else {	
				int lc = cnt++;
				dep[lc] = dep[i] - f[i];
			//	cout << lc << ' ' << dep[lc] << endl;
				vi cur;
				while (dep[st[top - 1]] > dep[lc]) 
					cur.pb(st[top - 1]), 
					top--;
				cur.pb(lc);
				for (int i = cur.size() - 1; i >= 1; i--)
					ade(cur[i], cur[i - 1], dep[cur[i - 1]] - dep[cur[i]]);
				st[top++] = lc;
				st[top++] = i;
			}
		}
		while (top >= 2)
			ade(st[top - 2], st[top - 1], dep[st[top - 1]] - dep[st[top - 2]]), 
			top--;
		dfs1(1);
		tot = 0;
		for (int i = 1; i <= m; i++)
			tot += w[i];
		ans[1] = in[1];
		dfs2(1);
		ll res = 1e18;
		for (int i = 1; i < cnt; i++)
			chkmin(res, ans[i]);//, cout << i << ' ' << ans[i] << endl;
		printf("%lld\n", res);
//	}
	return 0;
}