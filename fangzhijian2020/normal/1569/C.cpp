#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000,N=200000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int T,n,a[200005],fac[200005];
int main(){
	fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%mod;
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		if(a[n]==a[n-1]){
			cout<<fac[n]<<"\n";
		}
		else if(a[n]>a[n-1]+1){
			puts("0");
		}
		else{
			int tp=0;
			for(int j=n-1;j;--j){
				if(a[j]==a[n-1])++tp;
			}
			cout<<1ll*fac[n]*(1-ksm(tp+1,mod-2)+mod)%mod<<"\n";
		}
	}
	return 0;
}