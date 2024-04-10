#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,C,w[182],pw[182];
struct edge{int x,y,w;bool operator <(const edge a)const{return w<a.w;};}e[400002];
bitset<182>p[182][182],v,nw;
inline void mul(bitset<182>c[182],bitset<182>r[182]){
	for(re int i=1;i<=n;++i){
		r[i].reset();
		for(re int j=1;j<=n;++j)if(c[i][j])r[i]|=c[j];
	}
}
inline void muls(bitset<182>&c1,bitset<182>c2[182]){
	bitset<182>tm=c1;c1.reset();
	for(re int i=1;i<=n;++i)if(tm[i])c1|=c2[i];
}
signed main(){
	for(int i=pw[0]=1;i<31;++i)pw[i]=pw[i-1]<<1;
	n=read(),m=read();
	for(re int i=1;i<=m;++i)e[i].x=read(),e[i].y=read(),e[i].w=read(),w[++C]=e[i].w;
	sort(w+1,w+C+1),C=unique(w+1,w+C+1)-w-1;
	w[C+1]=w[C]+1e9;
	sort(e+1,e+m+1),v[1]=p[0][n][n]=1;
	if(w[1])return puts("Impossible"),0;
	for(int i=1,j=1,k;i<=C;++i){
		while(j<=m&&e[j].w==w[i])p[0][e[j].x][e[j].y]=1,++j;
		k=1,nw=v;
		while(pw[k]<=w[i+1]-w[i])mul(p[k-1],p[k]),++k;
		for(int l=k-1;~l;--l)if(((w[i+1]-w[i])>>l)&1)muls(v,p[l]);
		if(!v[n])continue;
		int ans=0;v=nw;
		while(k--){
			nw=v,muls(v,p[k]);
			if(!v[n])ans+=pw[k];
			else v=nw;
		}
		return printf("%d",ans+w[i]+1),0;
	}
	puts("Impossible");
}