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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,sum[200002],X[200002],Y[200002],st[200002],ed[200002],f[502][220002],tot,vis[200002],typ[200002],B;
inline void Add(re int x,re int l,re int r){
	if(X[x]+Y[x]<=B){
		int*A=f[X[x]+Y[x]];
		for(re int i=l+X[x];i<=l+X[x]+Y[x]-1&&i<=r;++i){
			++A[i];
			re int z=(r-i)/(X[x]+Y[x]);
			--A[i+(z+1)*(X[x]+Y[x])];
		}
		return;
	}
	for(re int i=l;i<=r;i+=X[x]+Y[x]){
		if(i+X[x]-1>r)return;
		++sum[i+X[x]];
		--sum[min(r+1,i+X[x]+Y[x])];
	}
}
int main(){
	n=read(),m=read(),B=sqrt(n);
	for(re int i=1;i<=n;++i)X[i]=read(),Y[i]=read();
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read();
		if(x==1)++tot,st[tot]=i,ed[tot]=m,vis[y]=tot,typ[tot]=y;
		else ed[vis[y]]=i-1;
	}
	for(re int i=1;i<=tot;++i)if(st[i]<=ed[i])Add(typ[i],st[i],ed[i]);
	for(re int i=1;i<=m;++i)sum[i]+=sum[i-1];
	for(re int i=1;i<=500;++i)
		for(re int j=i;j<=m;++j)
			f[i][j]+=f[i][j-i];
	for(re int i=1;i<=m;++i){
		re int s=sum[i];
		for(re int j=1;j<=500;++j)s+=f[j][i];
		printf("%d\n",s);
	}
}