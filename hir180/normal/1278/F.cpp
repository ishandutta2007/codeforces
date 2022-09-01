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
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll n,m,k;
ll kth[10005],C[5005][5005];
ll R[5005];
int main(){
	cin >> n >> m >> k;
	rep(i,5005)rep(j,i+1){
		if(j==0||j==i)C[i][j]=1;
		else{
			C[i][j] = C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod)C[i][j]-=mod;
		}
	}
	ll ans = 0;
	for(int i=0;i<10005;i++) kth[i] = modpow(1LL*i,k);
	for(int i=0;i<5005;i++) R[i] = modpow(1LL*i,mod-2);
	for(int i=1;i<=k;i++){
		if(n < i) continue;
		ll coef = modpow(modpow(m,i),mod-2);
		for(ll x=n;x>=n-i+1;x--) coef = coef*x%mod;
		repn(j,i) coef = coef*R[j]%mod;
		
		ll num = 0;
		for(int j=0;j<i;j++){
			ll val = C[i][j]*kth[i-j]%mod;
			if(j%2==0)num+=val; else num-=val;
		}
		num%=mod;
		ans += coef*num%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}