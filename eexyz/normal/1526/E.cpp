#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define N 500005
ll jc[N],a[N],f1,f2,u,n,k,i,pos[N];
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i],++a[i],pos[a[i]]=i;
	for(i=1;i<=n;++i)swap(a[i],pos[i]);
	a[n+1]=-1;
	for(i=2;i<=n;++i){
		f1=pos[i-1],f2=pos[i];
		if(a[f1+1]>a[f2+1])++u;
	}
	for(i=jc[0]=1;i<N;++i)jc[i]=jc[i-1]*i%mod;
	if(u>=k)cout<<0;
	else cout<<jc[k+n-u-1]*ksm(jc[n],mod-2)%mod*ksm(jc[k-u-1],mod-2)%mod;
}