#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=500000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=1e9+7,N=1e7;
int n,f[10000002],pw[500002],a[500002],ans,d[10000002],s[10000002],dd[10000002],pri[10002],cnt;
long long g[10000002];
bool v[10000002];
int main(){
	n=read();
	for(re int i=2;i<=N;++i){
		if(!v[i]){
			if(i<=10000){
				for(re int j=i*i;j<=N;j+=i)v[j]=1,d[j]?0:(d[j]=i);	
			}
			s[i]=1,d[i]=i;
		}
		else s[i]=-s[i/d[i]];
	}
	for(re int i=pw[0]=1;i<=n;++i){
		pw[i]=(pw[i-1]+pw[i-1])%M,a[i]=read();
		re int x=a[i];cnt=0;
		while(x^1)pri[++cnt]=d[x],x/=d[x];
	//	sort(pri+1,pri+cnt+1);
		x=pri[1];
		for(re int j=2;j<=cnt;++j)if(pri[j]!=pri[j-1])x*=pri[j];
		++f[a[i]=x];
	}
	for(re int i=1;i<=N;++i){
		for(re int j=i;j<=N;j+=i)g[i]+=f[j];
		f[i]=0;
	}
	for(re int i=N;i>=2;--i){
		dd[i]=g[i],g[i]=pw[g[i]]-1;
		re int x=g[i];
		if(s[i]>0)for(re int j=i;j<=N;j+=i)f[j]+=dd[i],g[i]-=g[j];
		else for(re int j=i;j<=N;j+=i)f[j]-=dd[i],g[i]-=g[j];
		g[i]+=x;
	}
	for(re int i=2;i<=N;++i)ans=(g[i]%M*(n-f[i])+ans)%M;
	printf("%d",(ans+M)%M);
}