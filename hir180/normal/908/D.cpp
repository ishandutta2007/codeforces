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
int k;
ll dp[1005][1005][2],pa,pb;
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
int main(){
	cin>>k>>pa>>pb;
	dp[0][0][1] = 1;
	ll R = modpow(pa+pb,mod-2);
	dp[1][0][0] = pa*R%mod;
	for(int i=1;i<k;i++){
		for(int j=0;j<k;j++){
			for(int x=0;x<2;x++){
				if(dp[i][j][x] == 0) continue;
				dp[i+1][j][0] = (dp[i+1][j][0]+dp[i][j][x]*pa%mod*R%mod)%mod;
				if(j+i<k){
					dp[i][j+i][1] = (dp[i][j+i][1]+dp[i][j][x]*pb%mod*R%mod)%mod;
				}
			}
		}
	}
	ll ret = 0;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			ll cur = dp[i][j][1]*modpow(pa*R%mod,mod-2)%mod;
			ll need = max(0,k-j-i);
			ll A = pa*R%mod;
			ll B = pb*R%mod;
			ll C = i+j;
			ll S = (modpow(A,need+1)*modpow(B,mod-2)%mod+modpow(A,need)*(C+need)%mod)%mod;
			ret = (ret+cur*S%mod);
		}
	}
	cout<<ret%mod<<endl;
}