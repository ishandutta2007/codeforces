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
int n,m,A[200002],B[200002],K,L[200002],R[200002],mx[22][200002],stk[200002],tp,X[200002],Y[200002],inf=2e5+1,p1[200002],p2[200002],c[200002];
long long ans;
inline void build(re int *a,re int n,re int* O){tp=0;
	for(re int i=1;i<=n;++i){
		re int mx=0;
		while(tp&&a[i]<=a[stk[tp]])mx=max(mx,L[stk[tp]]),--tp;
		L[i]=max(a[i],mx);if(!tp)O[i]=inf;else O[i]=L[i];stk[++tp]=i;
	}tp=0;
	for(re int i=n;i;--i){
		re int mx=0;
		while(tp&&a[i]<a[stk[tp]])mx=max(mx,R[stk[tp]]),--tp;
		R[i]=max(a[i],mx);if(tp)O[i]=min(O[i],R[i]);stk[++tp]=i;
	}
}
inline int cmp1(re int x,re int y){return A[x]<A[y];}
inline int cmp2(re int x,re int y){return Y[x]>Y[y];}
inline void Add(re int x){for(;x<=K;x+=x&(-x))++c[x];}
inline int Ask(re int x,re int y,re int s=0){
	x=max(x,0),y=max(y,0);
	while(x&&y&&(x^y)){
		if(y>x)s+=c[y],y^=y&(-y);
		else s-=c[x],x^=x&(-x);
	}
	if(x^y){
		while(y)s+=c[y],y^=y&(-y);
		while(x)s-=c[x],x^=x&(-x);
	}
	return s;
}
int main(){
	n=read(),m=read(),K=read();
	for(re int i=1;i<=n;++i)A[i]=read(),p1[i]=i;
	for(re int i=1;i<=m;++i)B[i]=read(),p2[i]=i;
	build(A,n,X),build(B,m,Y),sort(p1+1,p1+n+1,cmp1),sort(p2+1,p2+m+1,cmp2);re int pos=1;
	for(re int i=1;i<=n;++i){
		while(pos<=m&&A[p1[i]]+Y[p2[pos]]>K)Add(B[p2[pos++]]);
		ans+=Ask(K-X[p1[i]],K-A[p1[i]]);
	}
	printf("%lld",ans);
}