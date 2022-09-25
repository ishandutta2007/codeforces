#include<bits/stdc++.h>
using namespace std;
#define N 400020
typedef long long ll;
int n,m;
class Union_Set{
public:
	int f[N],siz[N];
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	inline void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i,siz[i]=1;
		}
	}
}S,T;
struct Link{
	int x,y,w,id;
}E[N];
vector<int> G[N],H[N],C[N],zz[N];
int ff[N][20],W[N],dep[N],ans[N];
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	ff[u][0]=fa;
	for(int j=1;j<=19;++j){
		ff[u][j]=ff[ff[u][j-1]][j-1];
	}
	for(auto v:H[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];
	}
	if(u==v)return u;
	for(int i=19;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return ff[u][0];
}
int tot;
void Merge(int x,int y,int w){
	if(S.siz[x]>S.siz[y])swap(x,y);
	static int deg[N];
	for(auto u:C[x]){
		vector<int> bin;
		for(auto z:zz[u]){
			for(auto v:G[z]){
				++deg[T.getf(v)];
				bin.push_back(T.getf(v));
			}
		}
		int now=u;
		vector<int> nw;
		for(auto v:C[y]){
			if(1LL*T.siz[u]*T.siz[v]==deg[v]){
				nw.push_back(v);continue;
			}
			++tot;
			T.f[now]=T.f[v]=tot;
			T.siz[tot]=T.siz[v]+T.siz[now];
			H[tot].push_back(now),H[tot].push_back(v);
			if(zz[v].size()<zz[now].size())swap(zz[v],zz[now]);
			swap(zz[tot],zz[v]);
			W[tot]=w;
			zz[tot].insert(zz[tot].end(),zz[now].begin(),zz[now].end());
			now=tot;
		}
		C[y]=nw;
		C[y].push_back(now);
		for(auto x:bin)deg[x]=0;
	}
	S.f[x]=y;
	S.siz[y]+=S.siz[x];
}
void Solve(){
	cin>>n>>m;
	S.init(n),T.init(n<<1);
	for(int i=1;i<=n<<1;++i)G[i].clear(),C[i].clear(),zz[i].clear(),H[i].clear();
	for(int i=1;i<=m;++i){
		cin>>E[i].x>>E[i].y>>E[i].w;
		G[E[i].x].push_back(E[i].y);
		G[E[i].y].push_back(E[i].x);
		E[i].id=i;
	}
	sort(E+1,E+m+1,[&](Link a,Link b){return a.w<b.w;});
	for(int i=1;i<=n;++i){
		C[i].push_back(i);
		zz[i].push_back(i);
	}
	tot=n;
	for(int i=1;i<=m;++i){
		int fx=S.getf(E[i].x),fy=S.getf(E[i].y);
		if(fx==fy)continue;
		Merge(fx,fy,E[i].w);
	}
	dfs1(tot,0);
	for(int i=1;i<=m;++i){
		ans[E[i].id]=W[LCA(E[i].x,E[i].y)];
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}