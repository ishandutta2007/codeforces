#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,f[N],book[N],dep[N],sg[N];
vector<int> G[N];
void dfs(int u){
	for(auto v:G[u]){
		if(v==f[u])continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs(v);
		sg[u]^=sg[v]+1;	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	int rt=sg[1];
	book[1]=1;
	if(rt){
		cout<<1;
	}
	else{
		cout<<2;
	}
	int E=0;
	for(int _u=2;_u<=n;++_u){
		int las=0,u=_u;
		while(!book[u]){
			for(auto v:G[u]){
				if(v==f[u]||v==las)continue;
				rt^=sg[v]+1;	
			}
			++E,book[u]=1,las=u,u=f[u];
		}
		if(las){
			rt^=sg[las]+1;
		}
		if(rt^(E&1)){
			cout<<1;
		}
		else{
			cout<<2;
		}
	}
	return 0;
}