#include<bits/stdc++.h>
using namespace std;
#define N 1600020
typedef long long ll;
int n,m1,m2,H,dfn[N],low[N],num,col[N],tot,vis[N];
stack<int> st;
vector<int> G[N];
void Tarjan(int u){
	low[u]=dfn[u]=++num;
	vis[u]=1;
	st.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}		
	}
	if(low[u]==dfn[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st.top();
			st.pop();
			vis[t]=0,col[t]=tot;
		}	
	}
}
#define yes(x) 2*(x)
#define no(x) 2*(x)-1
inline void adde(int u,int v){
	G[u].push_back(v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m1>>n>>H>>m2;
	for(int i=1;i<=m1;++i){
		int u,v;
		cin>>u>>v;
		adde(no(u),yes(v));
		adde(no(v),yes(u));		
	}
	adde(yes(n+1),no(n+1));
	for(int i=1;i<=H;++i){
		adde(yes(n+i),yes(n+i+1));
		adde(no(n+i+1),no(n+i));
	}
	for(int i=1;i<=n;++i){
		int l,r;
		cin>>l>>r;
		adde(yes(n+l),no(i));
		adde(no(n+r+1),no(i));
		adde(yes(i),no(n+l));
		adde(yes(i),yes(n+r+1));
	}
	for(int i=1;i<=m2;++i){
		int u,v;
		cin>>u>>v;
		adde(yes(u),no(v));
		adde(yes(v),no(u));
	}
	for(int i=1;i<=2*(n+H+1);++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=n+H+1;++i){
		if(col[no(i)]==col[yes(i)]){
			cout<<-1<<'\n';
			return 0;
		}	
	}
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(col[yes(i)]<col[no(i)])ans.push_back(i);	
	}
	cout<<ans.size()<<' ';
	for(int i=0;i<H;++i){
		if(col[no(n+i+1)]<col[yes(n+i+1)]&&col[yes(n+i+2)]<col[no(n+i+2)]){
			cout<<i+1<<'\n';
			break;
		}	
	}
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return 0;
}