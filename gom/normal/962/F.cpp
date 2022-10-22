#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
mat operator *(const mat &a,const mat &b)
{
	int n=a.size(),w=b.size(),m=b[0].size();
	mat c(n,vector<ll>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<m;k++){
				(c[i][k]+=a[i][j]*b[j][k]%mod)%=mod;
			}
		}
	}
	return c;
}
namespace fastIO{
	int cntF = 0;
	int lenF = 0;
	char bufF[1000000];
	void re() {
		cntF = 0;
		lenF = fread(bufF, 1, 1000000, stdin);
	}
	int nextint() {
		if (lenF == cntF) re();
		while (!(bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return -1;
		}
		int retF = 0;
		while ((bufF[cntF] >= '0' && bufF[cntF] <= '9')) {
			retF *= 10;
			retF += bufF[cntF]-'0';
			cntF++;
			if (lenF == cntF) re();
			if (lenF == cntF) return retF;
		}
		return retF;
	}
};
using namespace fastIO;
const int N=1e5+5;
int n,m,vis[N],cur;
int u[N],v[N],h[N],p[N],pe[N],nxt[N],clr[N],par[N],sz[N];
vector<int> g[N],ans;
int fi(int x)
{
	if(par[x]==x) return x;
	return par[x]=fi(par[x]);
}
void un(int x,int y)
{
	x=fi(x); y=fi(y);
	if(x==y) return;
	par[y]=x;
	sz[x]+=sz[y];
}
void dfs(int x)
{
	vis[x]=1;
	for(auto &it : g[x]){
		if(!vis[it]){
			p[it]=nxt[it]=x;
			h[it]=h[x]+1;
			dfs(it);
		}
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	for(int i=1;i<=m;i++) if(h[u[i]]>h[v[i]]) swap(u[i],v[i]);
	for(int i=1;i<=m;i++){
		par[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){
		if(h[v[i]]==h[u[i]]+1){
			pe[v[i]]=i;
			continue;
		}
		vector<int> vec;
		int cur=v[i];
		while(h[cur]>h[u[i]]){
			vec.push_back(cur);
			if(!clr[cur]) clr[cur]=i;
			else un(clr[cur],i);
			cur=nxt[cur];
		}
		for(auto &it : vec) nxt[it]=u[i];
	}
	for(int i=1;i<=m;i++){
		if(h[v[i]]==h[u[i]]+1) continue;
		if(sz[fi(i)]!=1) continue;
		ans.push_back(i);
		for(int cur=v[i];cur!=u[i];cur=p[cur]) ans.push_back(pe[cur]);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(auto &it : ans) cout<<it<<" ";
    return 0;
}