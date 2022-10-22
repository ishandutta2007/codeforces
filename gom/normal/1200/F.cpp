#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1005,K=2525,M=1005*2520;
const ll mod=2520;
int n,q;
int k[N],m[N],e[N][15];
vector<P> g[M];
vector<int> cyc[M];
int grp[M],ans[M],cn,cgp,ce,nv[M];
bool vis[M],cnt[M];
int mp[N][K];
int mp2[M];
bool cur[M];
deque<int> dq;
int f(int v)
{
	ll val=((ll)v+(ll)mod*(ll)1e6)%mod;
	return val;
}
void dfs1(int x,int p)
{
	vis[x]=1;
	grp[x]=cgp;
	dq.push_back(x);
	for(auto &it : g[x]){
		if(vis[it.fi]&&it.se!=p&&!cyc[cgp].size()){
			for(int i=dq.size()-1;i>=0;i--){
				if(!cur[mp2[dq[i]]]){
					cur[mp2[dq[i]]]=true;
					ans[cgp]++;
				}
				cyc[cgp].push_back(dq[i]);
				if(dq[i]==it.fi) break;
			}
			for(int i=dq.size()-1;i>=0;i--){
				if(cur[mp2[dq[i]]]){
					cur[mp2[dq[i]]]=false;
				}
				if(dq[i]==it.fi) break;
			}
		}
		else if(!vis[it.fi]) dfs1(it.fi,it.se);
	}
	dq.pop_back();
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		k[i]=f(k[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>m[i];
		for(int j=0;j<m[i];j++) cin>>e[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mod;j++){
			if(!mp[i][j]){
				mp[i][j]=++cn;
				mp2[cn]=i;
			}
			int u=mp[i][j];
			int nxt=e[i][(j+k[i])%m[i]],val=(j+k[i])%mod;
			if(!mp[nxt][val]){
				mp[nxt][val]=++cn;
				mp2[cn]=nxt;
			}
			int v=mp[nxt][val];
			nv[u]=v;
			g[u].push_back(P(v,++ce)); g[v].push_back(P(u,ce));
		}
	}
	for(int i=1;i<=cn;i++){
		if(!vis[i]){
			++cgp;
			dfs1(i,0);
		}
	}
	cin>>q;
	for(int x,y,i=1;i<=q;i++){
		cin>>x>>y;
		y=f(y);
		int u=mp[x][y];
		cout<<ans[grp[u]]<<"\n";
	}
    return 0;
}