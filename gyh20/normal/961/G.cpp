#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int M=1e9+7;
const int Mxdt=100000;	// 
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
int fac[200002],inv[200002],pri[200002],v[200002],cnt,pw[200002];
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int calc(re int n,re int m){
	cnt=0,memset(v,0,sizeof(v)),pw[1]=1;
	for(re int i=2;i<=m;++i){
		if(!v[i])pw[i]=ksm(i,n),pri[++cnt]=i;
		for(re int j=1;j<=cnt&&i*pri[j]<=m;++j){
			v[i*pri[j]]=1,pw[i*pri[j]]=1ll*pw[i]*pw[pri[j]]%M;
			if(i%pri[j]==0)break;
		}
	}
	re int s=0;
	for(re int i=0;i<m;++i)(i&1)?add(s,M-1ll*pw[m-i]*inv[i]%M*inv[m-i]%M):add(s,1ll*pw[m-i]*inv[i]%M*inv[m-i]%M);
	return s;
}
int n,sum,m;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)add(sum,read());
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	printf("%d",1ll*sum*(calc(n,m)+1ll*(n-1)*calc(n-1,m)%M)%M);
}