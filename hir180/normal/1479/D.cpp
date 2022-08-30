//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
template<class t> using vc=vector<t>;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

#define sz 7500005
#define pr 5
int le[sz], ri[sz];
unsigned int seg[1][sz], hsh[1<<19];
int a[300005], root[300005], nxt = (1<<20)-1;
vc<int>edge[300005];
int up[20][300005], dep[300005];

int put(int a, int k, int l, int r, int dep){
	if(l == r){
		rep(i, 1){
			seg[i][nxt] = seg[i][k] ^ hsh[l];
		}
		return nxt ++;
	}
	int xl = le[k], xr = ri[k];
	if(l <= a and a <= (l+r)/2){
		xl = put(a, xl, l, (l+r)/2, dep-1);
	}
	else xr = put(a, xr, (l+r)/2+1, r, dep-1);
	
	le[nxt] = xl;
	ri[nxt] = xr;
	rep(i, 1){
		seg[i][nxt] = seg[i][xl] ^ seg[i][xr];
	}
	return nxt ++;
}
void dfs(int v, int u){
	root[v] = put(a[v], root[u], 0, (1<<19)-1, 19);
	up[0][v] = u;
	if(u) dep[v] = dep[u]+1; else dep[v] = 0;
	for(auto a:edge[v]){
		if(a == u) continue;
		dfs(a, v);
	}
}
int lca(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	int d = dep[v] - dep[u];
	rep(j,20) if(((d>>j)&1)) v = up[j][v];
	if(u == v) return u;
	for(int j=19;j>=0;j--){
		if(up[j][v] != up[j][u]){
			u = up[j][u];
			v = up[j][v];
		}
	}
	return up[0][u];
}
int sol(int r0, int r1, int lb, int ub, int l, int r, int f){
	if(ub < l or r < lb) return -1;
	int va = 0;
	if(l <= f and f <= r) va = hsh[f];
	rep(i, 1) if((seg[i][r0]^va) != seg[i][r1]) goto nxt;
	return -1;
	nxt:;
	
	if(l == r) return l;
	int v = sol(le[r0], le[r1], lb, ub, l, (l+r)/2, f);
	if(v != -1) return v;
	return sol(ri[r0], ri[r1], lb, ub, (l+r)/2+1, r, f);
}
signed main(){
    cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
    rep(i, (1<<19)) hsh[i] = mt();
	int n, q; cin >> n >> q;
	repn(i, n) cin >> a[i];
	rep(i, n-1){
		int u, v; cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	rep(i, (1<<19)-2){
		le[i] = i * 2 + 1;
		ri[i] = i * 2 + 2;
	}
	root[0] = 0;
	dfs(1, 0);
	rep(j, 19){
		repn(i, n){
			if(up[j][i] == 0) up[j+1][i] = 0;
			else up[j+1][i] = up[j][up[j][i]];
		}
	}
	rep(i, q){
		int u, v, lb, ub; cin >> u >> v >> lb >> ub;
		int w = lca(u, v);
		int ans = sol(root[u], root[v], lb, ub, 0, (1<<19)-1, a[w]);
		cout << ans << '\n';
	}
}