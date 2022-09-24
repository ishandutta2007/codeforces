#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{
	int to,val;
};
int n,m,K,has[200005][9],v[9],cant[9][9][9],ans=0,fbd[9][9];
vector<E> g[200005];
void dfs(int x){
	if(x==K){
		bool flag=0;
		for(int i=0;i<K;i++)for(int j=0;j<K;j++)if(i!=j&&(cant[i][v[i]][j]&(1<<v[j])))flag=1;
		ans+=!flag;
		return ;
	}
	for(int i=0;i<=x;i++)if(!fbd[x][i])v[x]=i,dfs(x+1);
}
int main(){
	cin>>n>>m>>K;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z});
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end(),[](E x,E y){return x.val<y.val;});
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(has[g[i][j].to][g[i].size()-1]&(1<<j))fbd[g[i].size()-1][j]=1;
			has[g[i][j].to][g[i].size()-1]|=1<<j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<K;j++){
			for(int l=0;l<=j;l++){
				if(!(has[i][j]&(1<<l)))continue;
				for(int k=0;k<K;k++)cant[j][l][k]|=has[i][k];
			}
		}
	}
	dfs(0);
	cout<<ans;
}