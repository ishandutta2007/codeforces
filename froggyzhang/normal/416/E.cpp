#include<bits/stdc++.h>
using namespace std;
#define N 506
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,m,dis[N][N],E[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	memset(E,0x3f,sizeof(E));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=dis[v][u]=E[u][v]=E[v][u]=w;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		static int sum[N],ans[N];
		memset(sum,0,sizeof(sum));
		memset(ans,0,sizeof(ans));
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				if(dis[i][u]+E[u][v]==dis[i][v])++sum[v];
			}
		}
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				if(dis[i][u]+dis[u][v]==dis[i][v])ans[v]+=sum[u];	
			}
		}
		for(int u=i+1;u<=n;++u)
			cout<<(dis[i][u]==inf?0:ans[u])<<' ';
	}
	return 0;
}