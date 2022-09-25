#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
typedef pair<int,int> pii;
int n,m,f[N],siz[N],dfn[N],num,dep[N],top[N],son[N];
vector<int> G[N];
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=1;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}Bi;
vector<pair<int,int> > A,B;
inline bool In(int x,int y){ // x in y
	return dfn[x]>=dfn[y]&&dfn[x]<=dfn[y]+siz[y]-1;	
}
void dfs1(int u){
	siz[u]=1;
	dep[u]=dep[f[u]]+1;
	for(auto v:G[u]){
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	dfn[u]=++num;
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==son[u])continue;
		dfs2(v,v);
	}
}
inline int Get(int x,int y){
	while(top[x]^top[y]){
		if(f[top[y]]==x)return top[y];
		y=f[top[y]];
	}
	return son[x];
}
int Query(int x){
	return Bi.Ask(dfn[x]+siz[x]-1)-Bi.Ask(dfn[x]-1);	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		if(dep[x]>dep[y])swap(x,y);
		if(f[y]==x){
			cout<<-1<<'\n';
			return 0;
		}
		if(In(y,x))A.emplace_back(x,y);
		else B.emplace_back(x,y);
	}
	sort(A.begin(),A.end(),[&](pii a,pii b){return dep[a.first]>dep[b.first];});
	int ans=0;
	for(auto [x,y]:A){
		int z=Get(x,y);
		if(Query(z)-Query(y))continue;
		Bi.Add(dfn[z],1);
		++ans;
	}
	for(auto [x,y]:B){
		if(Query(x)+Query(y)==ans){
			++ans;
			break;
		}	
	}
	cout<<ans<<'\n';
	return 0;
}