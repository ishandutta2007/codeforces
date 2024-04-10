#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define ui unsigned int
#define ull unsigned long long 
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,k,ans,M,f[102][102][102],fac[102],C[102][102],g[102][102];
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
struct Fast_Mod {	ui M,a,b;	inline Fast_Mod(const ui m=2):M(m),a((1ull<<32)/m),b(((1ull<<32)%m<<32)/m){}	inline ull Mo(ull x) const {		return x-=((((x&~0u)*a+(x>>32)*b)>>32)+(x>>32)*a)*M,x>=M?x-M:x;	}}F;
inline int Get(re int x,re int y){
	if(~g[x][y])return g[x][y];
	if(x==0)return 0;
	if(y==m)return 1;
	re int &s=g[x][y];s=0;
	for(re int i=1;i<=x;++i)s=max(s,Get(i-1,y+1)+Get(x-i,y+1));
	return s;
}
inline int calc(re int x,re int y,re int d){
	if(x==0&&y==0)return 1;
	if(~f[x][y][d])return f[x][y][d];
	if(y>x)return 0;
	if(Get(x,d)<y)return 0;
	if(x==1&&y==0&&d<m)return 1;
	if(d==m){
		if(y==1)return fac[x];
		return 0;
	}
	re int &ss=f[x][y][d];ss=0;
	for(re int i=0;i<x;++i)
		for(re int j=0;j<=y;++j){
			re int s=F.Mo(F.Mo(1ll*calc(i,j,d+1)*calc(x-i-1,y-j,d+1))*C[x-1][i]);
			add(ss,s);
		}
	return ss;
}
int main(){
	n=read(),m=read(),k=read(),M=read(),memset(f,-1,sizeof(f));F=Fast_Mod(M),memset(g,-1,sizeof(g));
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	for(re int i=C[0][0]=1;i<=n;++i)	
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	printf("%d",calc(n,k,1)%M);
}