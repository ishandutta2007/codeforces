#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int mod=31607;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return r;
}
int n,f[2100005],tmp[2100005],g[21][2100005],a[21][21],must[21];
int F(int x){
    if(x>=mod)x-=mod;
    return x;
}
void And1(int a[],int n){
	for(int l=2,k=1;l<=(1<<n);l<<=1,k<<=1)for(int i=0;i<(1<<n);i+=l)for(int j=0;j<k;j++)a[i+j]=F(a[i+j]+a[i+j+k]);
}
void And2(int a[],int n){
	for(int l=2,k=1;l<=(1<<n);l<<=1,k<<=1)for(int i=0;i<(1<<n);i+=l)for(int j=0;j<k;j++)a[i+j]=F(a[i+j]-a[i+j+k]+mod);
}
int Calc(){
	for(int i=0;i<(1<<n);i++)f[i]=g[0][i];
	for(int i=0;i<(1<<n);i++)if(((i&must[0])!=must[0])||(i==(1<<n)-1))f[i]=0;
	And1(f,n);
	for(int k=1;k<n;k++){
		for(int i=0;i<(1<<n);i++)tmp[i]=g[k][i];
		for(int i=0;i<(1<<n);i++)if(((i&must[k])!=must[k])||(i==(1<<n)-1))tmp[i]=0;
		And1(tmp,n);
		for(int i=0;i<(1<<n);i++)f[i]=1ll*f[i]*tmp[i]%mod;
	}
	And2(f,n);
	return f[0];
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j],a[i][j]=a[i][j]*Power(10000,mod-2)%mod;
	//-//
	////=/-/-/+
	for(int k=0;k<n;k++){
		for(int i=0;i<(1<<n);i++){
			g[k][i]=1;
			for(int j=0;j<n;j++)if(i&(1<<j))g[k][i]=g[k][i]*a[k][j]%mod;else g[k][i]=g[k][i]*(1-a[k][j]+mod)%mod;
		}
	}
	int ans=Calc();
	for(int i=0;i<n;i++)must[i]=1<<i;
	cerr<<"PP\n";
	ans=(ans-Calc()+mod)%mod;
	cerr<<"PP\n";
	for(int i=0;i<n;i++)must[i]=1<<(n-i-1);
	ans=(ans-Calc()+mod)%mod;
	cerr<<"PP\n";
	for(int i=0;i<n;i++)must[i]=((1<<i)|(1<<(n-i-1)));
	ans=(ans+Calc())%mod;
	cerr<<"PP\n";
	cout<<(1-ans+mod)%mod;
}