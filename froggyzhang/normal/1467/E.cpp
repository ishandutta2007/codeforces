#include<bits/stdc++.h>
using namespace std;
#define N 200010
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
map<int,vector<int> > mp;
int n,a[N],num,siz[N],dfn[N],c[N],f[N][20],dep[N],ans;
vector<int> G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int j=1;j<=18;++j){
		f[u][j]=f[f[u][j-1]][j-1];
	}
	dfn[u]=++num;
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int Get(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;i>=0;--i){
		if(dep[f[x][i]]>dep[y])x=f[x][i];
	}
	return f[x][0]==y?x:-1;
}
void Cov(int l,int r,int x){
	c[l]+=x,c[r+1]-=x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(auto [qwq,vec]:mp){
		if(vec.size()==1)continue;
		sort(vec.begin(),vec.end(),[&](int i,int j){return dfn[i]<dfn[j];});
		for(int i=0;i<(int)vec.size();++i){
			int x=vec[i],y=vec[(i+1)%vec.size()];
			if(dfn[x]>dfn[y])swap(x,y);
			if(x){
				int p=Get(x,y);
				Cov(dfn[y],dfn[y]+siz[y]-1,1);
				if(~p){
					Cov(1,n,1);
					Cov(dfn[p],dfn[p]+siz[p]-1,-1);
				}
				else{
					Cov(dfn[x],dfn[x]+siz[x]-1,1);
				}     
			}
		} 
	}
	for(int i=1;i<=n;++i){
		c[i]+=c[i-1];
		ans+=c[i]==0;
	}
	printf("%d\n",ans);
	return 0;
}