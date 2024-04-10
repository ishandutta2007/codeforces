#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
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
const int M=998244353;
ull lmt=17e18,ans;
inline void Add(re ull &x,re ull y){(x+=y)>=lmt?x%=M:x;}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,a[2002][2002],fac[2002],d[2002],f[2002][2002],pw[2002],c1[2002],c2[2002];
char A[2002],B[2002];
inline void add(re int*c,re int x){for(;x<=n;x+=x&(-x))++c[x];}
inline void del(re int*c,re int x){for(;x<=n;x+=x&(-x))--c[x];}
inline int ask(re int*c,re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
int main(){
	n=read(),f[0][0]=1,f[1][1]=0,f[1][0]=1,d[0]=1;
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M; 
	for(re int i=2;i<=n;++i)d[i]=1ll*(i-1)*(d[i-1]+d[i-2])%M;
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=1ll*pw[i-1]*d[n]%M;
	for(re int i=2;i<=n;++i)
		for(re int j=0;j<=i;++j){
			if(i==j){
				f[i][j]=d[i];
				continue;
			}
			re int x=j,y=i-j;
			add(f[i][j],1ll*f[i-1][j]*y%M);
			if(j)add(f[i][j],1ll*f[i-1][j-1]*x%M);
		}
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)a[i][j]=read();
	for(re int i=1;i<=n;++i){
		re int num=0;
		for(re int j=i+1;j<=n;++j)num+=a[1][j]<=a[1][i];
		Add(ans,1ll*num*fac[n-i]);
	}
	ans=1ll*ans%M*pw[n-1]%M;
	for(re int i=2;i<=n;++i){
		memset(c1,0,sizeof(c1)),memset(c2,0,sizeof(c2));
		for(re int j=1;j<=n;++j)A[j]=0,B[j]=1,add(c2,j);
		re int num=0;
		for(re int j=1;j<=n;++j){
			B[a[i-1][j]]=0;
			if(A[a[i-1][j]])--num;
			else del(c2,a[i-1][j]),add(c1,a[i-1][j]);
			re int ss=0;
			add(ss,(1ll*ask(c2,a[i][j]-1)*f[n-j][n-j-num-1]+1ll*ask(c1,a[i][j]-1)*f[n-j][n-j-num])%M);
			if(a[i-1][j]<a[i][j]&&!A[a[i-1][j]])add(ss,M-f[n-j][n-j-num-B[a[i-1][j]]]);
			Add(ans,1ll*ss*pw[n-i]);
			if(B[a[i][j]])++num,del(c2,a[i][j]);
			else del(c1,a[i][j]);
			A[a[i][j]]=1;
		}
	}
	printf("%llu",ans%M);
	
}