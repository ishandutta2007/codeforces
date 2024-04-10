#include <bits/stdc++.h>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[2000005];;
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[2000005],R[2000005];
void make(){
	F[0] = 1;
	for(int i=1;i<2000005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<2000005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int n,k;
int main(){
	//make();
	scanf("%d%d",&n,&k);
	k = min(k,n);
	make();
	ll sum = 0;
	ll ret = 0;
	for(int i=k+1;i<=n;i++){
		dp[i] = F[i-1];
		if(i-k-1 >= k+1){
			sum = (sum+dp[i-k-1]*R[i-k-1]%mod)%mod;
		}
		dp[i] = (dp[i]-F[i-1]%mod*sum%mod+mod)%mod;
		if(i<n) ret = (ret+C(n-1,i)*dp[i]%mod*F[n-i]%mod)%mod;
	//	cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<(ret%mod+mod)%mod<<endl;
}