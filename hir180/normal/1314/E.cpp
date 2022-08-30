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
int n,k;
int cnt;
vector<int>vec;
void rec(int sum){
    if(true) {
        vector<int>zip = vec;
    	vector<int>vv;
    	rep(r,k){
    		int len = 0;
    		int num = 0;
    		rep(x,vec.size()){
    		    len += vec[x] ;
    		    if(r == k-2) num += vec[x] * (x+1);
    		}
    		int super = 0, L = len;
    		rep(x,vec.size()){
    		    super += (L+(L-vec[x]+1))*vec[x]/2*(x+1);
    		    L -= vec[x];
    		}
    		if(num > n || len > n || (r<k-2&&super > n)) break;
    		else if(r <= k-3 && len > 65) break;
    		else if(r <= k-5 && len > 10) break;
    		else if(r == k-2){
    		    cnt++; break;
    		}
    		vv.resize(len);
    		rep(x,vec.size()){
    			for(int y=1;y<=vec[x];y++) vv[--len] = x+1;
    		}
    		assert(len == 0);
    		swap(vv,vec);
    	}
    	vec = zip;
    }
	int las = vec.back();
	for(int x=las;x>0;x--){
	    if(sum+x > 64 || x*(vec.size()+1) > 2020) continue;
		vec.push_back(x);
		rec(sum+x);
		vec.pop_back();
	}
}
const ll mod = 998244353;
ll dp[2][2025];
int t[2][2025][2025];
int main(){
	scanf("%d%d",&n,&k);
	if(k >= 3){
		repn(i,64){
		    vec.pb(i);
		    rec(i);
		    vec.pop_back();
		}
		cout << cnt << endl;
	}
	else if(k == 1){
		dp[0][0] = 1;
		int cur = 0, nxt = 1;
		for(int i=1;i<=2020;i++){
			rep(x,2025) dp[nxt][x] = 0;
			for(int j=0;j<=2020;j++){
				dp[nxt][j] = dp[cur][j];
				if(j >= i) dp[nxt][j] += dp[nxt][j-i];
			}
			swap(cur,nxt);
			rep(x,2025) dp[cur][x]%=mod;
		}
		ll ans = 0;
		repn(x,n) ans += dp[cur][x];
		cout << (ans%mod+mod)%mod << endl;
	}
	else if(k == 2){
	    int cur = 0, nxt = 1;
		for(int x=65;x>=1;x--){
		    rep(a,2020/x+1) rep(b,2021) t[nxt][a][b] = 0;
			for(int y=1;y<=2020/(x+1);y++){
				for(int z=1;z<=2020;z++){
					if(t[cur][y][z] == 0) continue;
					for(int nxtt=y;x*nxtt+z<=2020;nxtt++){
					    t[nxt][nxtt][x*nxtt+z] += t[cur][y][z];
					    if(t[nxt][nxtt][x*nxtt+z] >= mod) t[nxt][nxtt][x*nxtt+z] -= mod;
					}
				}
			}
			swap(cur,nxt);
			for(int a=1;a*x<=2020;a++) t[cur][a][a*x] += 1;
		}
		ll ans = 0;
		repn(i,2020) repn(b,n) ans += t[cur][i][b];
		cout << (ans%mod+mod)%mod << endl;
	}
}