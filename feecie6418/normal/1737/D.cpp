#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,inf=1e9+5;
int g[505][505],dis[505][505],n,m;
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=inf,dis[i][j]=inf;
		}
	}
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)swap(x,y);
		g[x][y]=min(g[x][y],z);
		g[y][x]=min(g[y][x],z);
	}
	dis[1][n]=0;
	queue<pr> q;
	q.push(pr(1,n));
	while(!q.empty()){
		pr u=q.front();
		q.pop();
		int x=u.first,y=u.second;
		for(int i=1;i<=n;i++){
			if(g[x][i]<inf||x==y){
				int nx=i,ny=y;
				if(nx>ny)swap(nx,ny);
				if(dis[nx][ny]>dis[x][y]+1){
					dis[nx][ny]=dis[x][y]+1;
					q.push(pr(nx,ny));
				}
			}
			if(g[y][i]<inf){
				int nx=x,ny=i;
				if(nx>ny)swap(nx,ny);
				if(dis[nx][ny]>dis[x][y]+1){
					dis[nx][ny]=dis[x][y]+1;
					q.push(pr(nx,ny));
				}
			}
		}
	}
	//cout<<dis[7][8]<<'\n';
	//cout<<dis[4][8]<<'\n';
	//cout<<dis[4][4]<<'\n';
	//cout<<dis[2][4]<<'\n';
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]<inf){
				ans=min(ans,1ll*(dis[i][j]+1)*g[i][j]);
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}