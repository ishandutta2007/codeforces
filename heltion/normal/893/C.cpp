#include<iostream>
#include<vector>
using namespace std;
int c[100010];
vector<int> G[100010];
int d[100010]={};
int minc[100010];
int t=0;
void dfs(int i){
	d[i]=t;
	for(int j=0;j<G[i].size();++j)if(d[G[i][j]]==0)dfs(G[i][j]);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=n;++i)if(d[i]==0){
		t++;
		dfs(i);
	}
	for(int i=1;i<=t;++i)minc[i]=1000000000;
	for(int i=1;i<=n;++i)minc[d[i]]=min(minc[d[i]],c[i]);
	long long s=0;
	for(int i=1;i<=t;++i)s+=minc[i];
	cout<<s;
}