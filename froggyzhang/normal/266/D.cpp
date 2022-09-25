#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
const int inf=0x3f3f3f3f;
int G[N][N],dis[N][N];
pair<int,int> g[N][N];
int ans,n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;++i)G[i][i]=0;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=min(G[u][v],w);
	}
	ans=2e9;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=G[i][j];
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			g[i][j]=make_pair(dis[i][j],j);
		}
		sort(g[i]+1,g[i]+n+1);
		for(int j=i+1;j<=n;++j){
			if(G[i][j]==inf)continue;
			static int suf[N];
			suf[n+1]=0;
			for(int k=n;k>=1;--k){
				suf[k]=max(suf[k+1],dis[j][g[i][k].second]);	
			}
			for(int k=0;k<=n;++k){
				int A=g[i][k].first,B=suf[k+1];
				ans=min(ans,max(max(A,B)*2,A+B+G[i][j]));
			}
		}
	}
	cout<<fixed<<setprecision(10)<<ans/2.0<<'\n';
	return 0;
}