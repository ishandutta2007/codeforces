#include<bits/stdc++.h>
const int mod=1000000007;
using namespace std;
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int n,k,s,t,jc[200005]={1},ny[200005]={1};
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),s=(s+x)%mod;
	if(n==1)return cout<<s,0;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2),s=s;
	for(int i=n-1;i>=1;i--)ny[i]=1ll*(i+1)*ny[i+1]%mod;
	for(int i=0,f=1;i<k;i++,f=mod-f){
		t=(t+1ll*f*Power(k-i,n-1)%mod*ny[i]%mod*ny[k-i-1])%mod;
		t=(t+1ll*f*Power(k-i,n-2)%mod*(n-1)%mod*ny[i]%mod*ny[k-i-1])%mod;
	}
	cout<<1ll*s*t%mod;
	return 0;
}