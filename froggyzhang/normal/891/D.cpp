#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,siz[N],f[N],c[N];
vector<int> G[N];
struct Data{
	int d[2][2]; //  
	Data(int _x=0){d[0][0]=_x;d[0][1]=d[1][0]=d[1][1]=0;}
	friend Data operator * (const Data &a,const Data &b){ 
		Data c;
		for(int i=0;i<2;++i){
			for(int j=i;j<2;++j){
				for(int x=0;x<2;++x){
					for(int y=0;x+y<2;++y){
						c.d[i==j][x+y]+=a.d[i][x]*b.d[j][y];
					}
				}
			}
			c.d[i][1]+=a.d[i][0]*b.d[0][0];
		} 
		return c;
	}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		for(int i=0;i<2;++i){
			for(int j=0;i+j<2;++j){
				for(int x=0;x<2;++x){
					for(int y=0;x+y<2;++y){
						c.d[i+j][x+y]+=a.d[i][x]*b.d[j][y];
					}
				}
			}
		}
		return c;
	}
}dp[N],g[N];
ll ans;
void dfs1(int u){
	siz[u]=1;
	if(f[u]){
		G[u].erase(find(G[u].begin(),G[u].end(),f[u]));
	}
	for(auto v:G[u]){
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		c[u]+=c[v]+(siz[v]&1?-1:1);
	}
}
void dfs2(int u){
	dp[u]=Data(1);
	for(auto v:G[u]){
		dfs2(v);
		dp[u]=dp[u]*dp[v];
	}
}
void dfs3(int u){
	vector<Data> pre(G[u].size()+1),suf(G[u].size()+1);
	pre[0]=(u==1?Data(1):Data(1)*g[u]);
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		pre[i+1]=pre[i]*dp[v];
	}
	suf[G[u].size()]=Data(1);
	for(int i=(int)G[u].size()-1;i>=0;--i){
		int v=G[u][i];
		suf[i]=suf[i+1]*dp[v];
	}
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		g[v]=pre[i]+suf[i+1];
		dfs3(v);
		if(c[1]==-1&&siz[v]%2==0){
			ans+=1LL*siz[v]*(n-siz[v]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n&1){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	dfs3(1);
	for(int i=2;i<=n;++i){
		if(siz[i]&1){
			ans+=1LL*(dp[i].d[0][0]+dp[i].d[1][1])*(g[i].d[0][0]+g[i].d[1][1]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}