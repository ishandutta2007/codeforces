#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,m,d[N],gg[N];
bool ok;
vector<int> G[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		G[i].clear();gg[i]=0;
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		d[i]=G[i].size()%3;
	}
	ok=false;
	for(int i=1;i<=n;++i){
		if(!d[i]){
			ok=true;gg[i]=1;break;
		}
	}
	if(!ok){
		static int dep[N],f[N];
		for(int i=1;i<=n;++i)dep[i]=f[i]=0;
		int A=0,B=0,mn=1e9;
		function<void(int,int)> dfs=[&](int u,int fa)->void{
			dep[u]=dep[fa]+1;
			f[u]=fa;
			for(auto v:G[u]){
				if(d[v]^2||v==fa)continue;
				if(!dep[v]){
					dfs(v,u);
				}
				else if(dep[v]<dep[u]){
					if(dep[u]-dep[v]<mn){
						mn=dep[u]-dep[v];
						A=u,B=v;
					}			
				}
			}
		};
		for(int u=1;u<=n;++u){
			if(dep[u])continue;
			if(d[u]==2)dfs(u,0);
		}
		if(A){
			ok=true;
			for(int u=A;;u=f[u]){
				gg[u]=1;
				if(u==B)break;
			}
		}
	}
	if(!ok){
		static int pre[N],vis[N];
		for(int i=1;i<=n;++i)pre[i]=vis[i]=0;
		queue<int> q;
		for(int u=1;u<=n;++u){
			if(d[u]==1){
				q.push(u);vis[u]=1;break;
			}
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(ok)break;
			for(auto v:G[u]){
				if(vis[v])continue;
				vis[v]=1;
				pre[v]=u;
				if(d[v]==1){
					for(;v;v=pre[v]){
						gg[v]=1;
					}
					ok=true;
					break;	
				}
				q.push(v);		
			}
		}	
	}
	if(!ok){
		static int jb[N],vis[N];
		for(int i=1;i<=n;++i)jb[i]=vis[i]=0;
		for(int u=1;u<=n;++u){
			if(d[u]==1){
				for(auto v:G[u]){
					jb[v]=1;
				}
				gg[u]=1;
			}
		}
		bool myh=false;
		function<void(int,int)> dfs=[&](int u,int fa) -> void{
			static int st[N],top;
			st[++top]=u;
			vis[u]=1;
			if(top>1&&jb[u]&&!myh){
				for(int i=1;i<=top;++i)gg[st[i]]=1;
				myh=true;
			}
			for(auto v:G[u]){
				if(v==fa||d[v]==1)continue;
				if(!vis[v])dfs(v,u);
			}
			--top;
		};
		int tmp=2;
		for(int u=1;u<=n;++u){
			if(jb[u]&&!vis[u]){
				myh=false;
				dfs(u,0);
				--tmp;
				if(!tmp)break;	
			}	
		}
		if(!tmp)ok=true;
	}
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(!gg[i])ans.push_back(i);
	}
	if(ans.empty()||ans.size()==n){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n"<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<" ";
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}