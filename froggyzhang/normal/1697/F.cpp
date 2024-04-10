#include<bits/stdc++.h>
using namespace std;
#define N 440020
typedef long long ll;
int n,m,k,dfn[N],low[N],num,tot,col[N];
vector<int> G[N];
inline int yes(int x){return 2*x+1;}
inline int no(int x){return 2*x;}
inline int ID(int x,int y){
	return (x-1)*(k+1)+y+1;	
}
inline void adde(int u,int v){
	G[u].push_back(v);
	G[v^1].push_back(u^1);
}
bool vis[N];
void Clear(int n){
	for(int i=1;i<=n;++i){
		dfn[i]=low[i]=vis[i]=col[i]=0;
		G[i].clear();
	}
	num=tot=0;
}

void Tarjan(int u){
//	cerr<<" ?? "<<u<<endl;
	static int st[N],top;
	dfn[u]=low[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int t=0;
		++tot;
		while(t^u){
			t=st[top--];
			vis[t]=0;
			col[t]=tot;
		}
	}
}
void Solve(){
	cin>>n>>m>>k;
	Clear(yes(ID(n,k)));
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			adde(yes(ID(i,j)),yes(ID(i,j+1)));
		}
		if(i<n){
			for(int j=0;j<=k;++j){
				adde(yes(ID(i+1,j)),yes(ID(i,j)));
			}
		}
		adde(no(ID(i,k)),yes(ID(i,k)));
		adde(yes(ID(i,0)),no(ID(i,0)));
	}
	for(int i=1;i<=m;++i){
		int opt;
		cin>>opt;
		if(opt==1){
			int u,x;
			cin>>u>>x;
			adde(no(ID(u,x-1)),no(ID(u,x)));
		}
		else{
			int u,v,x;
			cin>>u>>v>>x;
			for(int p=1;p<=k;++p){
				int q=x-p;
				if(opt==2){
					if(q>=0&&q<=k){
						adde(no(ID(u,p-1)),yes(ID(v,q)));
						adde(no(ID(v,p-1)),yes(ID(u,q)));
					}
					else if(q<0){
						adde(no(ID(u,p)),yes(ID(u,p)));
						adde(no(ID(v,p)),yes(ID(v,p)));
					}
				}
				else{
					if(q>=1&&q<=k){
						adde(yes(ID(u,p)),no(ID(v,q-1)));
						adde(yes(ID(v,p)),no(ID(u,q-1)));
					}
					else if(q>k){
						adde(yes(ID(u,p)),no(ID(u,p)));
						adde(yes(ID(v,p)),no(ID(v,p)));
					}
				}
			}
		}
	}
	for(int i=2;i<=yes(ID(n,k));++i){
		if(!dfn[i]){
			Tarjan(i);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			if(col[yes(ID(i,j))]==col[no(ID(i,j))]){
				cout<<-1<<'\n';
				return;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			if(col[yes(ID(i,j))]<col[no(ID(i,j))]){
				cout<<j<<' ';
				break;
			}
		}
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