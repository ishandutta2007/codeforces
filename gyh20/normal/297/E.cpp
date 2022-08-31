#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=200000;
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
int n,m,c[200002],p[100002],X[100002],Y[100002],L[100002],R[100002];
long long ans,s;
inline void add(re int x){for(;x<=n+n;x+=x&(-x))++c[x];}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
inline bool cmp1(re int x,re int y){return X[x]<X[y];}
inline bool cmp2(re int x,re int y){return Y[x]<Y[y];}
int main(){
	n=read();
	for(re int i=1;i<=n;++i){
		X[i]=read(),Y[i]=read(),p[i]=i;	
		if(X[i]>Y[i])swap(X[i],Y[i]);
	}
	sort(p+1,p+n+1,cmp1);
	for(re int i=n;i;--i)add(Y[p[i]]),R[p[i]]=ask(Y[p[i]]-1);
	memset(c,0,sizeof(c));
	for(re int i=1;i<=n;++i)add(Y[p[i]]),L[p[i]]=ask(X[p[i]])+i-ask(Y[p[i]]);
	memset(c,0,sizeof(c)),sort(p+1,p+n+1,cmp2);
	for(re int i=n;i;--i)add(X[p[i]]),L[p[i]]+=(n-i+1)-ask(Y[p[i]]);
	ans=1ll*n*(n-1)*(n-2)/6;
	for(re int i=1;i<=n;++i)ans-=1ll*L[i]*R[i],s+=1ll*(L[i]+R[i])*(n-L[i]-R[i]-1);
	printf("%lld",ans-(s>>1));
}