#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,fa[1002],ans,siz[1002],A[1002],B[1002],k,sz[1002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void merge(re int x,re int y){
	x=root(x),y=root(y),fa[x]=y,siz[y]+=siz[x];
}
int main(){
	n=read(),m=read(),k=1;
	for(re int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	for(re int i=1;i<=m;++i){
		A[i]=read(),B[i]=read();
		if(root(A[i])==root(B[i]))++k;
		else merge(A[i],B[i]);
		re int o=0;
		for(re int j=1;j<=n;++j)if(root(j)==j)sz[++o]=siz[root(j)];
		sort(sz+1,sz+o+1),reverse(sz+1,sz+o+1);
		re int s=0;
		for(re int j=1;j<=k;++j)s+=sz[j];
		printf("%d\n",s-1);
	}
}