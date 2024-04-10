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
typedef unsigned long long ull;
typedef bitset<128> Q;
unordered_map<Q, int>S[8];
//vector<Q>vec[8];
int go[8][30500][128];
const ll mod = 1000000007;
ll dp[8][30500];
ll a[7][7],prob[7][128];
int n;
ll modpow(ll a,ll n){
    ll ret = 1;
    while(n){
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}
vector<int>M[8];
int main(){
	cin >> n;
	rep(i,(1<<n)) M[__builtin_popcount(i)].pb(i);
	Q q = Q();
	q[0] = 1;
	S[0][q] = 0;
	rep(i,n){
		int sz = 0;
		for(auto vv:S[i]){
			auto v = vv.fi;
		    rep(j,(1<<n)){
		        Q q = Q();
		        for(auto c:M[i]){
		            if(v[c] == 0) continue;
    				rep(k,n){
    					if(!((j>>k)&1)) continue;
    					if(((c>>k)&1)) continue;
    					int nw = c^(1<<k);
    					q[nw] = 1;
    				}
    			}
    			if(S[i+1].find(q) == S[i+1].end()){
    				S[i+1][q] = sz++;
    			}
    			go[i][vv.sc][j] = S[i+1][q];
		    }
		}
	}
	rep(i,n) rep(j,n) cin >> a[i][j];
	ll rev = modpow(100ll,mod-2);
	rep(i,n){
	    rep(j,(1<<n)){
	        prob[i][j] = 1;
	        rep(k,n){
	            if(((j>>k)&1)) prob[i][j]=prob[i][j]*a[i][k]%mod*rev%mod;
	            else prob[i][j]=prob[i][j]*(100-a[i][k])%mod*rev%mod;
	        }
	    }
	}
	dp[0][0] = 1;
	rep(i,n){
	    rep(j,S[i].size()){
	        rep(k,(1<<n)){
	            dp[i+1][go[i][j][k]] += dp[i][j]*prob[i][k]%mod;
	        }
	    }
	    rep(j,30500) dp[i+1][j]%=mod;
	}
	ll ans = 0;
	for(auto att:S[n]){
	    auto at = att.fi;
	    int check = (1<<n)-1;
	    if(at[check] == 0) continue;
	    ans += dp[n][att.sc];
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}