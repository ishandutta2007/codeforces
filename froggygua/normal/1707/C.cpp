#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,tr[N],id[N],ans[N],s[N];
vector<int> G[N];
class Union_Set{
public:
	int f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
}S;
struct Link{
	int x,y;
}L[N];
int dfn[N],num,siz[N],dep[N];
int ff[N][19];
inline bool In(int x,int y){
	return dfn[x]>=dfn[y]&&dfn[x]<=dfn[y]+siz[y]-1;
}
inline int Jump(int x,int t){
	for(int i=18;i>=0;--i){
		if(t>>i&1)x=ff[x][i];
	}
	return x;
}
void dfs(int u,int fa){
	siz[u]=1;
	dfn[u]=++num;
	id[num]=u;
	ff[u][0]=fa;
	for(int i=1;i<=18;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>L[i].x>>L[i].y;
	}
	S.init(n);
	for(int i=1;i<=m;++i){
		int fx=S.getf(L[i].x),fy=S.getf(L[i].y);
		if(fx==fy)continue;
		tr[i]=1;
		S.f[fy]=fx;
		G[L[i].x].push_back(L[i].y);
		G[L[i].y].push_back(L[i].x);
	}
	dfs(1,0);
	for(int i=1;i<=m;++i){
		if(tr[i])continue;
		int x=L[i].x,y=L[i].y;
		if(dfn[x]>dfn[y])swap(x,y);
		if(In(y,x)){
			int z=Jump(y,dep[y]-dep[x]-1);
			++s[1],--s[dfn[z]],++s[dfn[z]+siz[z]];
			++s[dfn[y]],--s[dfn[y]+siz[y]];
		}
		else{
			++s[dfn[x]],--s[dfn[x]+siz[x]];
			++s[dfn[y]],--s[dfn[y]+siz[y]];
		}
	}
	for(int i=1;i<=n;++i){
		s[i]+=s[i-1];
		if(s[i]==m-(n-1))ans[id[i]]=1;
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}