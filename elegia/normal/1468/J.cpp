//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
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
#define maxn 200005
int fa[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]); 
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<pair<int, pi> >s;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			s.pb(mp(w, mp(u, v))); 
		} 
		for (int i = 1; i <= n; i++)
			fa[i] = i; 
		sort(s.begin(), s.end());
		int tot = n; 
		ll ans = 1e18;
		ll cur = 0;
		int mx = 0; 
		for (auto v : s) {
			mx = max(mx, v.fi);
			if (gfa(v.se.fi) != gfa(v.se.se)) { 
				fa[gfa(v.se.fi)] = gfa(v.se.se), 
				tot--; 
				if (v.fi > k) 
					cur += v.fi - k; 	
			} 
			if (tot == 1) {
				if (v.fi <= k) { 
					chkmin(ans, cur + k - mx);
					for (auto q : s) 
						chkmin(ans, abs((ll)q.fi - k));
					break;
				} 
				else
					chkmin(ans, cur); 
			} 
		} 
		cout << ans << endl; 
	} 
	return 0; 
}