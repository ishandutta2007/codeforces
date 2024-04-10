#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define y1 ysgh
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,f[N],dfn[N],num,top[N],siz[N],dep[N],son[N],Q;
int mn[N][19],mx[N][19],lg[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
inline pair<int,int> Query(int l,int r){
	int k=lg[r-l+1];
	return make_pair(dfn[mn[l][k]]<dfn[mn[r-(1<<k)+1][k]]?mn[l][k]:mn[r-(1<<k)+1][k],dfn[mx[l][k]]>dfn[mx[r-(1<<k)+1][k]]?mx[l][k]:mx[r-(1<<k)+1][k]);
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}	
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Get(int l,int r,int x){
	auto [x1,y1]=Query(l,x-1);
	auto [x2,y2]=Query(x+1,r);
	if(x==l)return LCA(x2,y2);
	if(x==r)return LCA(x1,y1);
	return LCA(LCA(x1,y1),LCA(x2,y2));
}
int main(){
	n=read(),Q=read();
	for(int i=2;i<=n;++i){
		f[i]=read();
		G[f[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i)mn[i][0]=mx[i][0]=i;
	for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			mn[i][j]=dfn[mn[i][j-1]]<dfn[mn[i+(1<<j-1)][j-1]]?mn[i][j-1]:mn[i+(1<<j-1)][j-1];
			mx[i][j]=dfn[mx[i][j-1]]>dfn[mx[i+(1<<j-1)][j-1]]?mx[i][j-1]:mx[i+(1<<j-1)][j-1];
		}
	}
	while(Q--){
		int l=read(),r=read();
		auto [x,y]=Query(l,r);
		int lcax=Get(l,r,x),lcay=Get(l,r,y);
		printf("%d %d\n",dep[lcax]>dep[lcay]?x:y,max(dep[lcax],dep[lcay]));
	}
	return 0;
}