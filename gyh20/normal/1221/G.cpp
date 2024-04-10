#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,G[42][42],Z[22],B,O[42],f[1<<21],lmt,fa[42],u[42],col[42],ia,n1,n2;
ll ans,sum;
inline void dfs(re int x,re int z){
	if(x>n){++n1;
		++f[z];
		return;
	}
	O[x]=0,dfs(x+1,z);
	re bool ia=1;
	for(re int i=21;i<x;++i)if(O[i]&&G[i][x])ia=0;
	if(ia)O[x]=1,dfs(x+1,z|(1<<x-21));
}
inline void dfs1(re int x,re int z){
	if(x==lmt){++n2;
		sum+=f[z^1048575];
		return;
	}
	O[x]=0,dfs1(x+1,z);
	re bool ia=1;
	for(re int i=1;i<x;++i)if(O[i]&&G[i][x])ia=0;
	if(ia)O[x]=1,dfs1(x+1,z|Z[x]);
}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){
	x=root(x),y=root(y);
	fa[x]=y;
}
inline void ddfs(re int x,re int y){
	if(col[x]&&col[x]!=y){
		ia=0;
		return;
	}if(col[x])return;col[x]=y;
	for(re int i=1;i<=n;++i)if(G[x][i])ddfs(i,y^1);
}
int main(){
	n=read(),m=read(),ans=1;
	for(re int i=1;i<=n;++i)ans<<=1,fa[i]=i;
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();Merge(x,y),u[x]=u[y]=1;
		if(x>y)swap(x,y);
		if(x<=20&&y>20)Z[x]|=1<<y-21;
		G[x][y]=G[y][x]=1;
	}
	dfs(21,0),lmt=min(n+1,21);
	for(re int i=1;i<(1<<20);i<<=1)
		for(re int j=0;j<(1<<20);++j)
			if(j&i)f[j]+=f[j^i];
	dfs1(1,0),ans-=sum*2;re ll tmp=1;
	for(re int i=1;i<=n;++i)if(root(i)==i)tmp<<=1;
	ans-=tmp,tmp=1;
	for(re int i=1;i<=n;++i)if(!u[i])tmp<<=1;
	ans+=tmp<<1;tmp=1,ia=1;
	for(re int i=1;i<=n;++i)
		if(root(i)==i){
			tmp<<=1;
			ddfs(i,2);
		} 
	if(ia)ans+=tmp;
	if(!m)ans-=1ll<<n;
	printf("%lld",ans);
}