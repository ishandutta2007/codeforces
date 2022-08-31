#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
char vis[752],s[10000002],v1[752],v2[752];
bitset<752>g[752];
int n,m,my[752],ans,ch[10000002][2],f[10000002],fa[752],pos[752],id[10000002],F[10000002],tot,h[10000002],v[752],p[752];
inline int root(re int x){return x==F[x]?x:F[x]=root(F[x]);}
queue<int>q;
inline void ins(re int y){
	re int nw=0;
	for(re int i=1;i<=m;++i){
		if(!ch[nw][s[i]-'a'])ch[nw][s[i]-'a']=++tot,h[tot]=nw;
		nw=ch[nw][s[i]-'a'];
	}pos[y]=nw,id[nw]=y;
}
inline bool dfs(re int x){
	for(re int i=g[x]._Find_first();i<=n;i=g[x]._Find_next(i))
		if(!vis[i]){
			vis[i]=1;
			if(!my[i]||dfs(my[i]))return my[i]=x;
		}
	return 0;
}
inline void dfs1(re int x){
	if(v1[x])return;v1[x]=1;
	for(re int i=g[x]._Find_first();i<=n;i=g[x]._Find_next(i))if(my[i]^x)v2[i]=1,dfs1(my[i]);
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)gets(s+1),m=strlen(s+1),ins(i);
	for(re int i=0;i<2;++i)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		re int x=q.front();q.pop();
		for(re int i=0;i<2;++i)
			if(ch[x][i]){
				f[ch[x][i]]=ch[f[x]][i];
				q.push(ch[x][i]);
			}
			else ch[x][i]=ch[f[x]][i];
	}
	for(re int i=1;i<=tot;++i)F[i]=id[i]?i:f[i];
	for(re int i=1;i<=n;++i){
		re int x=pos[i];
		if(id[root(f[x])])g[i][id[root(f[x])]]=1;
		x=h[x];
		while(x){
			g[i][id[root(x)]]=1;
			if(id[x])break;
			x=h[x];
		}
	}
	for(re int k=1;k<=n;++k)for(re int i=1;i<=n;++i)if(g[i][k])g[i]|=g[k];
	for(re int i=1;i<=n;++i)g[i][751]=1;
	for(re int i=1;i<=n;++i)memset(vis,0,sizeof(vis)),dfs(i);
	for(re int i=1;i<=n;++i)p[my[i]]=i;
	for(re int i=1;i<=n;++i)if(!p[i])dfs1(i);
	for(re int i=1;i<=n;++i)if(v1[i]&&!v2[i])++ans;
	printf("%d\n",ans);
	for(re int i=1;i<=n;++i)if(v1[i]&&!v2[i])printf("%d ",i);
}