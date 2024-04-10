#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,N=200000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p1=(p2=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
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
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,m,x,ans,fac[200005],ifac[200006],h[200005],t[200005],f[200005],a[200005];
void add(int x,int v){
	for(;x<=N;x+=x&-x)a[x]+=v;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=a[x];
	return ans;
}
int main(){
	n=read();m=read();
	fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N]=ksm(fac[N],mod-2);for(int i=N;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i){
		x=read();++h[x];add(x,1);
	}
	int tmp=1;
	for(int i=1;i<=N;++i){
		tmp=1ll*tmp*ifac[h[i]]%mod;
	}
	for(int i=1;i<=m;++i)t[i]=read();
	f[0]=1;
	for(int i=1;i<=min(n,m);++i){
		Add(ans,1ll*f[i-1]*ask(t[i]-1)%mod*fac[n-i]%mod);
		f[i]=1ll*f[i-1]*h[t[i]]%mod;
		if(!h[t[i]])break;--h[t[i]];add(t[i],-1);
	}
	if(n<m)Add(ans,f[n]);
	cout<<1ll*ans*tmp%mod<<"\n";
	return 0;
}