#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,t[N];
ll sg[N],h[N];
vector<int> G[N];
int get_mex(const vector<int> &v){
	static int vis[N],myh;
	++myh;
	for(auto x:v)vis[x]=myh;
	for(int i=0;;++i)if(vis[i]^myh)return i;
}
void dfs(int u){
	vector<int> tmp;
	for(auto v:G[u]){
		if(!~t[v])dfs(v);
		tmp.push_back(t[v]);	
	}
	t[u]=get_mex(tmp);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	for(int i=1;i<=n;++i){
		cin>>h[i];
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
		if(t[i]==-1)dfs(i);
	}
	int mx=0,zero=1;
	for(int i=1;i<=n;++i){
		sg[t[i]]^=h[i];
		mx=max(mx,t[i]);
	}
	while(mx>=0&&!sg[mx])--mx;
	if(mx<0){
		cout<<"LOSE\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(t[i]==mx&&h[i]>(h[i]^sg[mx])){
			h[i]=h[i]^sg[mx];
			for(auto v:G[i]){
				h[v]=h[v]^sg[t[v]];
				sg[t[v]]=0;
			}
			break;
		}
	}
	cout<<"WIN\n";
	for(int i=1;i<=n;++i){
		cout<<h[i]<<' ';
	}
	cout<<'\n';
	return 0;
}