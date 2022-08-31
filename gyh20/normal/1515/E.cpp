#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,M,f[402][402],ans,C[802][802],num;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
#define ui unsigned int
#define ull unsigned long long
struct Fast_Mod {	ui M,a,b;	inline Fast_Mod(const ui m=2):M(m),a((1ull<<32)/m),b(((1ull<<32)%m<<32)/m){}	inline ull Mo(ull x) const {		return x-=((((x&~0u)*a+(x>>32)*b)>>32)+(x>>32)*a)*M,x>=M?x-M:x;	}}F;
signed main(){
	f[0][0]=1,f[1][1]=1,f[2][2]=2,f[2][1]=0;
	n=read(),M=read();F=Fast_Mod(M);
	for(re int i=C[0][0]=1;i<=n;++i)for(re int j=C[i][0]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	for(re int x=3;x<=n;++x){
		for(re int y=(x>>1)+1;y<=x;++y){		
			for(re int i=1;i<=(x>>1);++i){
				for(re int j=max(y+i-x-1,i>>1);j<=i&&(y-j)>((x-i-1)>>1);++j){
					re int L=f[i-1][j];
					if(i>2)add(L,f[i-2][j]);
					re int R=f[x-i][y-j-1];
					if(i<x-1)add(R,f[x-i-1][y-j-1]);
					re int oo;
					if(i!=1&&i!=x)oo=F.Mo(1ll*L*R+1ll*f[i-1][j]*(M-f[x-i][y-j-1]));
					else oo=F.Mo(1ll*L*R);
					add(f[x][y],F.Mo(1ll*C[y-1][j]*oo));
				}
			}
			add(f[x][y],f[x][y]);
			if(x&1){
				re int i=(x+1>>1);
				for(re int j=i>>1;(y-j)>((x-i-1)>>1);++j){
					re int L=f[i-1][j];
					if(i>2)add(L,f[i-2][j]);
					re int R=f[x-i][y-j-1];
					if(i<x-1)add(R,f[x-i-1][y-j-1]);
					re int oo;
					if(i!=1&&i!=x)oo=(1ll*L*R+1ll*f[i-1][j]*(M-f[x-i][y-j-1]))%M;
					else oo=1ll*L*R%M;
					add(f[x][y],1ll*C[y-1][j]*oo%M);
				}
			}
		}
	}
	for(re int i=1;i<=n;++i)add(ans,f[n][i]);
	printf("%d",ans);
}