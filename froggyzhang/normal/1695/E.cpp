#include<bits/stdc++.h>
using namespace std;
#define N 600060
typedef long long ll;
int n,vis[N],t[2][N];
char a1[2][N],a2[2][N];
vector<pair<int,int> > G[N];
vector<int> ans;
void dfs(int u){
	while(!G[u].empty()){
		auto [v,id]=G[u].back();
		G[u].pop_back();
		if(vis[id])continue;
		vis[id]=1;
		dfs(v);
		ans.push_back(v); 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		G[u].emplace_back(v,i+n);
		G[v].emplace_back(u,i+n);
	}
	for(int i=1,k=1;i<=n<<1;++i){
		ans.clear();
		dfs(i);
		if(ans.empty())continue;
		if(ans.size()<=2){
			cout<<"-1\n";
			return 0;
		}
		reverse(ans.begin(),ans.end());
		int m=ans.size()/2;
		for(int j=0;j<m;++j){
			t[0][k+j]=ans[j];
		}
		for(int j=0;j<m;++j){
			t[1][k+m-1-j]=ans[j+m];
		}
		for(int j=0;j<m;j+=2){
			if(j==m-1)a1[0][k+m-1]='U';
			else a1[0][k+j]='L',a1[0][k+j+1]='R';
		}
		for(int j=0;j<m;j+=2){
			if(j==m-1)a1[1][k+m-1]='D';
			else a1[1][k+j]='L',a1[1][k+j+1]='R';
		}
		a2[0][k]='U';
		for(int j=1;j<m;j+=2){
			if(j==m-1)a2[0][k+m-1]='U';
			else a2[0][k+j]='L',a2[0][k+j+1]='R';
		}
		a2[1][k]='D';
		for(int j=1;j<m;j+=2){
			if(j==m-1)a2[1][k+m-1]='D';
			else a2[1][k+j]='L',a2[1][k+j+1]='R';
		}
		k+=m;
	}
	cout<<2<<' '<<n<<'\n';
	for(int i=0;i<2;++i,cout<<'\n')
		for(int j=1;j<=n;++j)
			cout<<t[i][j]<<' ';
	for(int i=0;i<2;++i,cout<<'\n')
		for(int j=1;j<=n;++j)
			cout<<a1[i][j];
	for(int i=0;i<2;++i,cout<<'\n')
		for(int j=1;j<=n;++j)
			cout<<a2[i][j];
	return 0;
}