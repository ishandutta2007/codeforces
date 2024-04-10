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
 
int n,d;
ll mod;
ll dp[1005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
 
int main(){
	cin >> n >> d >> mod;
	
	if(n <= 2){
		puts("1"); return 0;
	}
	if((n-2)%(d-1) != 0){
		puts("0"); return 0;
	}
	int x = (n-2)/(d-1);
	
	
	ll t[11][1005]={};
	t[0][1] = 1;
	dp[1] = 1;
	
	ll ans = 0;
	for(int nw=1;nw<=x/2;nw++){
		ll coef[12]={};
		coef[0] = 1;
		for(int k=1;k<=d;k++){
			//k+dp[nw]-1 choose k
			coef[k] = coef[k-1] * (k+dp[nw]-1) % mod * modpow(k,mod-2) % mod;
		}
		
		if(x%2 == 0 && nw == x/2){
			ans += coef[2];
			break;
		}
		for(int j=d;j>=0;j--){
			for(int k=1;j+k<=d;k++){
				rep(xx,x+1-k*nw){
				    t[j+k][xx+k*nw] += t[j][xx] * coef[k] % mod;
					t[j+k][xx+k*nw] %= mod;
				}
			}
		}
		for(int k=0;k<d;k++) dp[nw+1] = (dp[nw+1]+t[k][nw+1])%mod;
	}
	
	rep(k,d+1) ans += t[k][x];
	
	cout << (ans%mod+mod)%mod << endl;
}