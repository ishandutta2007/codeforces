#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
ll ds[N][N],dt[N][N];
int n,m,W,a[N][N];
const int d[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
inline bool In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
ll bfs(ll dis[][N],int sx,int sy){
	ll mn=inf;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dis[i][j]=inf;
	dis[sx][sy]=0;	
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(a[x][y]>0)mn=min(mn,dis[x][y]+a[x][y]);
		for(int i=0;i<4;++i){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(In(nx,ny)&&dis[nx][ny]==inf&&~a[nx][ny]){
				dis[nx][ny]=dis[x][y]+W;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return mn;
}
int main(){
	n=read(),m=read(),W=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	ll x=bfs(ds,1,1);
	ll y=bfs(dt,n,m);
	ll ans=ds[n][m];
	ans=min(ans,x+y);
	printf("%lld\n",ans==inf?-1:ans);
	return 0;
}