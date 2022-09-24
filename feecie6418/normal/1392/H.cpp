#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,jc[4000005],ny[4000005],f[4000005],s[4000005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Ci(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*ny[x]*jc[y]%mod*jc[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n>>m,jc[0]=ny[0]=1;
	for(int i=1;i<=n+m;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n+m]=Power(jc[n+m],mod-2);
	for(int i=n+m-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int u=0;
	for(int i=1;i<=n+1;i++){
		int p=1ll*Ci(n+m,m)*C(n+m-i,m-1)%mod;
		u=(u+1ll*p*i)%mod;
	}
	for(int x=n-1,p=0;x>=0;x--){
		int sum=p,coef=1,o=1ll*C(n+m,x)*Ci(n,x)%mod*Ci(n+m,m)%mod;
		sum=1ll*sum*o%mod;
		sum=(sum+u)%mod;
		coef=(1-1ll*o*C(n-x+m-1,m-1)%mod+mod)%mod;
		f[x]=1ll*sum*Power(coef,mod-2)%mod;
		p=(p+1ll*C(n-x+m-1,m-1)*f[x])%mod;
	}
	cout<<f[0];
}