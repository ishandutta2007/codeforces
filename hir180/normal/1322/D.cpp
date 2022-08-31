//Let's join Kaede Takagaki Fun Club !!
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
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n,m,a[2005],s[2005],c[4005],poss[2005];
ll dp[2][2005][4005];
vector<int>pos[4005];
ll best[4005];
mt19937 mt(614);
int bin[4005];
int main(){
    bin[0] = 1;
    for(int i=1;i<4005;i++) bin[i] = min(bin[i-1]*2,100000);
    
	ios::sync_with_stdio(false);
	g(n); g(m);
	repn(i,n){
		g(a[i]);
		for(int j=a[i];j<=2020;j++) pos[j].pb(i);
	}
	repn(i,n) g(s[i]);
	repn(i,n+m) g(c[i]);
	
	rep(a,2) rep(i,2005) rep(j,4005) dp[a][i][j] = -1e18;
	
	ll ans = 0;
	for(int i=1;i<=n+m;i++){
		reverse(all(pos[i]));
		if(pos[i].empty()) continue;
		rep(x,4005) best[x] = -1e18;
		rep(j,pos[i].size()){
			int id = pos[i][j];
			int v = (i==a[id]?4000:2020 / bin[i-a[id]-1]);
			rep(x,v+1) dp[poss[id]^1][id][x] = -1e18;
			
			rep(x,v+1){
				if(dp[poss[id]][id][x] >= -5e17){
				    chmax(dp[poss[id]^1][id][x/2], dp[poss[id]][id][x]+1LL*c[i]*(x/2));
				}
				if(a[id] == i) chmax(dp[poss[id]^1][id][x+1], best[x]+1LL*c[i]-s[id]);
			}
			if(a[id] == i) chmax(dp[poss[id]^1][id][1], 1LL*c[i]-s[id]);
			
			rep(x,v+1){
				chmax(best[x], dp[poss[id]^1][id][x]);
			}
			poss[id] ^= 1;
		}
		ans = max(ans,best[0]);
	}
	o(ans);
}