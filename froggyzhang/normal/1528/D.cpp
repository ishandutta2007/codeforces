#include<bits/stdc++.h>
using namespace std;
#define N 606
typedef long long ll;
const ll inf=1e18+233;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
ll G[N][N],H[N][N],dis[N][N];
void Dijkstra(int s,ll *dis){
	static int vis[N];
	for(int i=1;i<=n;++i){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	for(int i=1;i<=n;++i){
		int u=0;
		for(int j=1;j<=n;++j){
			if(vis[j])continue;
			if(!u||dis[j]<dis[u])u=j;
		}
		vis[u]=1;
		for(int v=1;v<=n;++v){
			int k=(v-dis[u]%n+n-1)%n+1;
			if(dis[v]>dis[u]+H[u][k]){
				dis[v]=dis[u]+H[u][k];
			}	
		}
	}	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			G[i][j]=inf;
		}
	}
	for(int i=1;i<=m;++i){
		int u=read()+1,v=read()+1,w=read();
		G[u][v]=w;
	}
	for(int u=1;u<=n;++u){
		for(int i=1;i<=n;++i){
			H[u][i]=inf;
			for(int j=0;j<n;++j){
				H[u][i]=min(H[u][i],j+G[u][(i-j+n-1)%n+1]);
			}
		}	
	}
	for(int s=1;s<=n;++s){
		Dijkstra(s,dis[s]);	
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%lld ",dis[i][j]);
		}
		printf("\n");
	}
	return 0;
}