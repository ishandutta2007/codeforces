#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int dis[105][105],g[105][105],tmp[105][105],S[105],E[105],n,m,K,A,B;
int f[105][105],nd[105][105],on[105][105],must[105][105];
vector<int> to[105][105];
int main(){
	cin>>n>>m>>A>>B,memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,dis[x][y]=1;
	cin>>K;
	for(int i=1;i<=K;i++)cin>>S[i]>>E[i];
	memcpy(g,dis,sizeof(g));
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int u=1;u<=n;u++){
		memcpy(tmp,g,sizeof(g));
		for(int i=1;i<=n;i++)tmp[i][u]=tmp[u][i]=0x3f3f3f3f;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tmp[i][j]=min(tmp[i][j],tmp[i][k]+tmp[k][j]);
		for(int i=1;i<=K;i++)if(tmp[S[i]][E[i]]!=dis[S[i]][E[i]])must[i][u]=1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=K;j++)on[i][j]=(dis[S[j]][E[j]]==dis[S[j]][i]+dis[i][E[j]]);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=K;i++)if(on[B][i])f[B][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=K;j++)
			for(int k=1;k<=n;k++)
				if(on[i][j]&&on[k][j]&&dis[i][E[j]]+1==dis[k][E[j]]&&dis[k][i]==1)nd[k][j]++,to[i][j].push_back(k);
	for(int i=0;i<n;i++){
		queue<pr> q;
		for(int j=1;j<=n;j++)for(int k=1;k<=K;k++)if(f[j][k]==i)q.push(pr(j,k));
		while(!q.empty()){// 
			pr x=q.front();
			q.pop();
			for(int j:to[x.first][x.second])
				if((!--nd[j][x.second])&&f[j][x.second]>i)f[j][x.second]=i,q.push(pr(j,x.second));
		}
		for(int j=1;j<=n;j++)for(int k=1;k<=K;k++)if(f[j][k]==i&&must[k][j])for(int o=1;o<=K;o++)f[j][o]=min(f[j][o],f[j][k]+1);
		//for(int j=1;j<=n;j++)for(int k=1;k<=K;k++)if(f[j][k]==i)printf("f[%d][%d]=%d\n",j,k,f[j][k]);
	}
	int ans=0x3f3f3f3f;
	for(int o=1;o<=K;o++)if(must[o][A])ans=min(ans,f[A][o]);
	if(ans<1e9)cout<<ans+1;
	else cout<<-1;
}