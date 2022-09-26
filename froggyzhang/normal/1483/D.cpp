#include<bits/stdc++.h>
using namespace std;
#define N 606
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,m,q,ans,E[N][N];
ll dis[N][N],mx[N];
vector<pair<int,int> > vec[N];
int main(){
	n=read(),m=read();
	memset(dis,0x0f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		E[u][v]=E[v][u]=w;
		dis[u][v]=dis[v][u]=min(dis[u][v],1LL*w);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	q=read();
	for(int i=1;i<=q;++i){
		int u=read(),v=read(),l=read();
		vec[u].emplace_back(v,l);
		vec[v].emplace_back(u,l);
	}
	for(int y=1;y<=n;++y){
		for(int u=1;u<=n;++u){
			mx[u]=-inf;
			for(auto [v,l]:vec[u]){
				mx[u]=max(mx[u],l-dis[y][v]);
			}
		}
		for(int x=y+1;x<=n;++x){
			if(!E[x][y])continue;
			for(int u=1;u<=n;++u){
				if(mx[u]>=dis[x][u]+E[x][y]){
					++ans;break;
				}
			}	
		}
	}
	printf("%d\n",ans);
	return 0;
}