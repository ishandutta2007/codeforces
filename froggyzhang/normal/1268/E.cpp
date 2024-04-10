#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,m,dfn[N],low[N],num,up[N],R[N],dp[N],g[N];
vector<pair<int,int> > G[N];
pair<int,int> E[N];
void Tarjan(int u,int fa){
	static int st[N],top;
	dfn[u]=low[u]=++num;
	for(auto [v,w]:G[u]){
		if(!dfn[v]){
			st[++top]=w;
			Tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				vector<int> cc;
				int t=0;
				while(t^w){
					t=st[top--];
					cc.push_back(t);
				}
				if(cc.size()==1)continue;
				int p=min_element(cc.begin(),cc.end())-cc.begin();
				int l=p,r=p;
				int len=cc.size();
				#define pre(x) (x+len-1)%len
				#define suf(x) (x+1)%len
				while(cc[pre(l)]>cc[l])l=pre(l);
				while(cc[suf(r)]>cc[r])r=suf(r);
				if(l==r)R[cc[p]]=cc[l];
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
			if(v^fa&&dfn[v]<dfn[u])st[++top]=w;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		E[i]=make_pair(u,v);	
	}
	Tarjan(1,0);
	for(int i=1;i<=n;++i)dp[i]=1;
	for(int i=m;i>=1;--i){
		auto [x,y]=E[i];
		dp[x]=dp[y]=g[i]=dp[x]+dp[y]-g[R[i]];
	}
	for(int i=1;i<=n;++i){
		cout<<dp[i]-1<<' ';
	}
	return 0;
}