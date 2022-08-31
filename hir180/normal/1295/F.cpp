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

const ll mod = 998244353;
int n;
ll a[55],b[55];
vector<ll>za;
ll dp[55][105][55];
ll F[55],R[55];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
void make(){
	F[0] = 1;
	for(int i=1;i<55;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<55;i++) R[i] = modpow(F[i],mod-2);
}
ll RR[105][105];
int main(){
	cin >> n;
	make();
	repn(i,n){
		cin >> a[i] >> b[i];
		za.pb(a[i]); za.pb(b[i]+1);
	}
	SORT(za); ERASE(za);
	rep(i,za.size()-1){
	    ll len = za[i+1]-za[i];
	    RR[i][0] = 1;
	    repn(j,n){
	        RR[i][j] = RR[i][j-1] * modpow(len,mod-2) % mod * (len+j-1) % mod * modpow(j,mod-2) % mod;
	    }
	}
	int L = POSL(za,a[1]);
	int Rr = POSL(za,b[1]+1)-1;
	for(int i=L;i<=Rr;i++){
		dp[1][i][1] = modpow(b[1]-a[1]+1,mod-2) * (za[i+1]-za[i]) % mod;
	}
	for(int i=1;i<n;i++){
		int L = POSL(za,a[i+1]);
		int Rr = POSL(za,b[i+1]+1)-1;
		rep(j,za.size()){
			repn(k,i){
				if(dp[i][j][k] ==  0) continue;
				for(int aa=L;aa<=Rr;aa++){
					if(aa > j) continue;
					ll coef = modpow(b[i+1]-a[i+1]+1,mod-2) * (za[aa+1]-za[aa]) % mod;
					
					if(aa == j){
						dp[i+1][j][k+1] += dp[i][j][k]%mod * coef % mod;
					}
					else{
						dp[i+1][aa][1] += dp[i][j][k]%mod * RR[j][k] % mod * coef % mod;
					}
				}
			}
		}
	}
	
	ll ans = 0;
	rep(j,za.size()) repn(k,n) ans += dp[n][j][k] % mod * RR[j][k] % mod;
	cout << (ans%mod+mod)%mod << endl;
}