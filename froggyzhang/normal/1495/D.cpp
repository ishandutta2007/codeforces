#include<bits/stdc++.h>
using namespace std;
#define N 505 
const int mod=998244353;
typedef long long ll;
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
vector<int> G[N];
int dis[N][N],n,m;
int ok[N],vis[N],pre[N];
int main(){
	n=read(),m=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		dis[u][v]=dis[v][u]=1;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int cnt=0;
			for(int k=1;k<=n;++k){
				ok[k]=0;
				pre[k]=0;
			}
			for(int k=1;k<=n;++k){
				if(dis[i][k]+dis[k][j]==dis[i][j]){
					ok[k]=1;
					++cnt;
				}
			}
			if(cnt!=dis[i][j]+1){
				printf("0 ");
				continue;
			}
			queue<int> q;
			for(int i=1;i<=n;++i){
				vis[i]=0;
				if(ok[i])vis[i]=1,q.push(i);
			}
			int ans=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:G[u]){
					if(dis[u][i]+1==dis[v][i]&&dis[u][j]+1==dis[v][j]){
						++pre[v];
						if(!vis[v])vis[v]=1,q.push(v);
					}
				}
			}
			for(int i=1;i<=n;++i){
				if(!ok[i])ans=1LL*ans*pre[i]%mod;
			}
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}