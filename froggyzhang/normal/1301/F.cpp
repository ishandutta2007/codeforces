#include<bits/stdc++.h>
using namespace std;
#define y1 ysgh1
#define y2 ysgh2
#define N 1010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,k,Q,dis[41][N][N],a[N][N];
vector<pair<int,int> > p[41];
int f[N][N];
queue<pair<int,int> > q;
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
inline bool In(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;	
}
void bfs(int dis[][N]){
	bitset<64> vis;
	vis.reset();
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		if(!vis[a[x][y]]){
			vis[a[x][y]]=1;
			for(auto [nx,ny]:p[a[x][y]]){
				if(dis[nx][ny]==inf){
					dis[nx][ny]=dis[x][y]+1;
					q.push(make_pair(nx,ny));
				}	
			}	
		}
		for(int i=0;i<4;++i){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(In(nx,ny)&&dis[nx][ny]==inf){
				dis[nx][ny]=dis[x][y]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			p[a[i][j]].emplace_back(i,j);
		}	
	}
	memset(dis,0x3f,sizeof(dis));
	memset(f,0x3f,sizeof(f));
	for(int p=1;p<=k;++p){
		f[p][p]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]==p){
					q.push(make_pair(i,j));
					dis[p][i][j]=0;
				}
			}
		}
		bfs(dis[p]);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				f[p][a[i][j]]=min(f[p][a[i][j]],dis[p][i][j]);
			}
		}
	}
	cin>>Q;
	while(Q--){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		int ans=abs(x1-x2)+abs(y1-y2);
		for(int p=1;p<=k;++p){
			ans=min(ans,dis[p][x1][y1]+dis[p][x2][y2]+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}