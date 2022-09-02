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
ll val[100005][105];
int n,m;
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
ll F[100005],R[100005];
void make(){
	F[0] = 1;
	for(int i=1;i<100005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<100005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m; make();
	repn(i,n)cin>>val[i][0];
	rep(i,m){
		int l,r,k;cin>>l>>r>>k; int a=r-l;
		if(k<=a){
			for(int i=1;i<=k;i++){
				val[l+i-1][i] = (val[l+i-1][i]+C(k,k+1-i))%mod;
				val[l+a+1][i] = (val[l+a+1][i]-C(k+a+1-i,k+1-i)+mod)%mod;
			}
			val[k+l][k+1] ++;
			val[l+a+1][k+1] --; 
			//for(int i=1;i<=n;i++)cout<<val[i][1]<<" " << val[i][2]<<endl;
		}
		else{
			for(int i=1;i<=a;i++){
				val[l+i-1][i] = (val[l+i-1][i]+C(k,k+1-i))%mod;
				val[l+a+1][i] = (val[l+a+1][i]-C(k+a+1-i,k+1-i)+mod)%mod;
			}
			val[l+a][a]+=C(k,a);
		}
	}
	for(int j=101;j>=1;j--){
		for(int i=2;i<=n;i++) val[i][j] = (val[i][j]+val[i-1][j])%mod;
		for(int i=1;i<=n;i++) val[i][j-1] = (val[i][j-1]+val[i][j])%mod;
	}
	for(int i=1;i<=n;i++) printf("%lld\n",(val[i][0]+mod)%mod);
}