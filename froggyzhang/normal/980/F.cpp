#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,tot,dfn[N],low[N],num;
vector<int> H[N],G[N];
void Tarjan(int u){
	static int st[N],top;
	st[++top]=u;
	dfn[u]=low[u]=++num;
	for(auto v:H[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				if(st[top]^v){
					++tot;
					int t=0;
					while(t^v){
						t=st[top--];
						G[t].push_back(tot);
						G[tot].push_back(t);
					}
					G[tot].push_back(u);
					G[u].push_back(tot);
				}
				else{
					--top;
					G[u].push_back(v);
					G[v].push_back(u);
				}
			}
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int dp[N],g[N];
void dfs1(int u,int fa){
	dp[u]=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}	
	if(u<=n){
		for(auto v:G[u]){
			if(v==fa)continue;
			dp[u]=max(dp[v]+1,dp[u]);
		}
	}
	else{
		vector<int> pre(G[u].size()),suf(G[u].size());
		for(auto it=G[u].begin();;++it){
			if((*it)==fa){
				rotate(G[u].begin(),it,G[u].end());
				break;
			}
		}
		for(int i=1;i<(int)G[u].size();++i){
			int v=G[u][i];
			if(v==fa)continue;
			pre[i]=i-1+dp[v];	
			suf[i]=(int)G[u].size()-i-1+dp[v];
		}
		for(int i=1;i<(int)G[u].size();++i){
			pre[i]=max(pre[i-1],pre[i]);
		}
		for(int i=(int)G[u].size()-2;i>=0;--i){
			suf[i]=max(suf[i],suf[i+1]);
		}
		dp[u]=inf;
		for(int i=0;i<(int)G[u].size();++i){
			dp[u]=min(dp[u],max(pre[i],(i+1==G[u].size()?0:suf[i+1])));	
		}
	}
}
void dfs2(int u,int fa,int wfa){
	if(u<=n){
		g[u]=max(dp[u],wfa);
		vector<int> pre(G[u].size()),suf(G[u].size());
		for(int i=0;i<(int)G[u].size();++i){
			if(G[u][i]==fa)continue;
			pre[i]=suf[i]=dp[G[u][i]]+2;
		}
		for(int i=1;i<(int)G[u].size();++i){
			pre[i]=max(pre[i-1],pre[i]);
		}
		for(int i=(int)G[u].size()-2;i>=0;--i){
			suf[i]=max(suf[i],suf[i+1]);
		}
		for(int i=0;i<(int)G[u].size();++i){
			int v=G[u][i];
			if(v==fa)continue;
			dfs2(v,u,max(wfa+1,max(!i?-inf:pre[i-1],i+1==G[u].size()?-inf:suf[i+1])));
		}
	}
	else{
		vector<int> W(G[u].size()<<1),zz(G[u].size());
		for(int i=0;i<(int)G[u].size();++i){
			W[i]=W[i+G[u].size()]=(!i?wfa-1:dp[G[u][i]]);
		}
		deque<int> q1,q2;
		for(int i=1;i<(int)G[u].size();++i){
			while(!q2.empty()&&W[i]-i>=W[q2.back()]-q2.back())q2.pop_back();
			q2.push_back(i);
		}
		q1.push_back(0);
		for(int i=0,j=1;i<(int)G[u].size();++i){
			zz[i]=max(q1.empty()?-inf:W[q1.front()]+q1.front()-i,q2.empty()?-inf:W[q2.front()]-q2.front()+i+(int)G[u].size());
			if(i==q1.front())q1.pop_front();
			while(j<i+(int)G[u].size()){
				int Lnxt=max(q1.empty()?-inf:W[q1.front()]+q1.front()-i,W[j]+j-i);
				int Rnxt=(q2.front()==j?(q2.size()==1?-inf:W[q2[1]]-q2[1]+i+G[u].size()):W[q2.front()]-q2.front()+i+G[u].size());
				zz[i]=min(zz[i],max(Lnxt,Rnxt));
				if(j>i+1&&Lnxt>Rnxt)break;
				while(!q1.empty()&&W[j]+j>=W[q1.back()]+q1.back())q1.pop_back();
				q1.push_back(j);
				if(q2.front()==j)q2.pop_front();
				++j;
			}
			while(!q2.empty()&&W[i+G[u].size()]-i-(int)G[u].size()>=W[q2.back()]-q2.back())q2.pop_back();
			q2.push_back(i+G[u].size());
		}
		for(int i=1;i<(int)G[u].size();++i){
			int v=G[u][i];
			dfs2(v,u,zz[i]);
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
		H[u].push_back(v);
		H[v].push_back(u);
	}
	tot=n;
	Tarjan(1);
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;++i){
		cout<<g[i]<<' ';
	}
	cout<<'\n';
	return 0;
}