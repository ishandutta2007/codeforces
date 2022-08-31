#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll mod = 1000000007;
vector<int>dp[61];
vector<int>C;
ll F[65],p[65][65],c[65][65];

ll solve(int m, vector<ll>M){
	int n = M.size();
	if(m == 0 || n == 0) return 1;
	rep(i,m+1){
	    dp[i].clear();
		dp[i].resize((1<<n), 0);
	}
	int has[61]={};
	rep(i,n){
		rep(j,m) if(((M[i]>>j)&1)) has[j] |= (1<<i);
	}
	C.clear();
	C.resize((1<<n), 0);
	for(int i=0;i<(1<<n);i++){
		rep(j,m) if( (has[j] & i) > 0 ) C[i] ++;
	}
	dp[0][0] = 1;
	rep(mask,(1<<n)){
		rep(i,m+1) if(dp[i][mask]) goto nxt;
		continue; nxt:;
		
		rep(x,m){
			if( (mask & has[x]) == has[x] ) continue;
			if( mask && (mask & has[x]) == 0 ) continue;
			//go to (mask | has[x])
			rep(j,m+1){
				if(dp[j][mask] == 0) continue;
				//dp[j][mask] -> dp[j+1+a][mask|has[x]]
				int cnt = m - C[(1<<n)-1-mask];
				//cnt-j P a
				for(int a=0;a<=m-j-1;a++){
				    if(cnt-j < a) break;
					dp[j+1+a][mask | has[x]] += p[cnt-j][a] * dp[j][mask] % mod ;
					if(dp[j+1+a][mask | has[x]] >= mod) dp[j+1+a][mask | has[x]] -= mod;
				}
			}
		}
	}
	ll ret = 0;
	rep(i,m+1){
		ret += 1LL * dp[i][(1<<n)-1] * F[m-i] % mod;
	}
	return ret%mod;
}
int n,a[65];
vector<int>id[65];
int par[65],ran[65];
void init(){ for(int i=0;i<65;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	init();
	rep(i,n){
		rep(j,i){
			if(a[i]%a[j] == 0 || a[j]%a[i] == 0){
				unite(i,j); //cout << i << " " << j << endl;
			}
		}
	}
	rep(i,n) id[find(i)].pb(i);
	ll ans = 1;
	F[0] = 1;
	for(int i=1;i<65;i++) F[i] = F[i-1] * 1LL * i % mod;
	rep(i,64)rep(j,i+1){
		if(j == 0 || j == i) p[i][j] = 1;
		else p[i][j] = (p[i-1][j-1] + p[i-1][j]) % mod;
	}
	rep(i,65)rep(j,65) c[i][j] = p[i][j];
	rep(i,65)rep(j,65) p[i][j] = p[i][j] * F[j] % mod;
	int pre = 0;
	rep(i,n){
		if(id[i].empty()) continue;
		vector<int>L,R;
		rep(x,id[i].size()){
			rep(y,id[i].size()){
				if(x != y && a[id[i][x]] % a[id[i][y]] == 0){
					R.pb(x); goto nxt;
				}
			}
			L.pb(x); nxt:; 
		}
		//not prove XD
		assert(L.size() <= 12);
		vector<ll>mask; mask.resize(L.size(),0);
		rep(aa,L.size()){
			rep(b,R.size()){
				if(a[id[i][R[b]]] % a[id[i][L[aa]]] == 0) mask[aa] |= (1LL<<b);
			}
		}
		if(id[i].size() >= 3){
    		//cout << L.size() << " " << R.size() << endl;
    		//for(auto a:mask) cout << a << " "; cout << endl;
    		//cout << solve(R.size(),mask) << endl;
    		ans = ans * solve(R.size(),mask) % mod * c[pre + R.size()-1][pre] % mod;
    		pre += R.size()-1;
		}
		
	}
	cout << ans << endl;
	return 0;
}