#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,mod=998244353,N=300000;
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
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,prime[300005],tot,vis[300005],a[300005],f[300005],g[300005];
void FMT(int*f,int n){
	for(int i=1;i<=tot;++i){
		for(int j=(n/prime[i])*prime[i];j;j-=prime[i]){
			Add(f[j/prime[i]],f[j]);
		}
	}
}
void IFMT(int*f,int n){
	for(int i=1;i<=tot;++i){
		for(int j=prime[i];j<=N;j+=prime[i]){
			Add(f[j/prime[i]],mod-f[j]);
		}
	}
}
bool check(int x){
	for(int i=1;i<=N;++i)g[i]=ksm(f[i],x);
	IFMT(g,N);return g[1];
}
int main(){
	for(int i=2;i<=N;++i){
		if(!vis[i]){
			prime[++tot]=i;
		}
		for(int j=1;j<=tot;++j){
			if(i*prime[j]>N)break;
			vis[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	n=read();int tmp=0;
	for(int i=1;i<=n;++i){
		a[i]=read();++f[a[i]];
		tmp=gcd(tmp,a[i]);
	}
	if(tmp!=1){puts("-1");return 0;}
	FMT(f,N);int l=1,r=min(n,10);
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<r+1<<"\n";
	return 0;
}