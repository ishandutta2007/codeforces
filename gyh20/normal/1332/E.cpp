#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,mod,a[5][5],f[5],b[5][5],g[5],cs,aa[5][5];
inline void mul() {
	memset(g,0,sizeof(g));
	for(register int i=1; i<=n; ++i) {
		for(register int j=1; j<=n; ++j) {
			g[i]+=(f[j]*a[j][i])%mod;
			g[i]%=mod;
		}
	}
	memcpy(f,g,sizeof(g));
}
inline void mulself() {
	memset(b,0,sizeof(b));
	for(register int i=1; i<=n; ++i) {
		for(register int j=1; j<=n; ++j) {
			for(register int k=1; k<=n; ++k){
				b[i][j]+=a[i][k]*a[k][j]%mod;
				b[i][j]%=mod;
			}
		}
	}
	memcpy(a,b,sizeof(b));
}
int k,l,r;
#define re register
const int Mxdt=100000;
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read() {
	int res=0,bj=0;
	char ch=gc();
	while(ch<'0')bj|=(ch=='-'),ch=gc();
	while(ch>='0')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return bj?-res:res;
}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int s,t;
signed main() {mod=998244353;
	n=read();m=read();l=read();r=read();re int kk=n*m;
	k=m*n;s=(r-l+1)/2;
	if((r&1)&&(l&1))++s;t=r-l+1-s;
	n=2;f[1]=1,f[2]=0;
	a[2][1]=s,a[2][2]=t;
	a[1][1]=t,a[1][2]=s;
	
if(kk%2==0){
	while(k) {

		if(k&1)mul();
		mulself();	
		k>>=1;
	}
	long long ans=f[1];
	printf("%lld",ans);}
	else{printf("%lld",ksm(r-l+1,kk));
	}
}