#include<iostream>
#include<queue>
using namespace std;
int n,m,r,c,p,q;
int dis[2001][2001];
bool vis[2001][2001];
char a[2001][2001];
bool ingrid(int x,int y){
	return (x>0 && x<=n && y>=1 && y<=m && a[x][y]!='*');
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
deque<int>qx,qy;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> r >> c >> p >> q;
	qx.push_back(r);
	qy.push_back(c);
	for(int i=1; i<=n ;i++) for(int j=1; j<=m ;j++) dis[i][j]=1e9;
	dis[r][c]=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
		}
	}
	while(!qx.empty()){
		int cx=qx.front();
		int cy=qy.front();
		qx.pop_front();
		qy.pop_front();
		if(vis[cx][cy]) continue;
		vis[cx][cy]=true;
		for(int i=0; i<4 ;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if(!ingrid(nx,ny)) continue;
			int ndis=0;
			if(i==0 && ny<=c || i==1 && ny>=c) ndis=1;
			if(dis[nx][ny]>dis[cx][cy]+ndis){
				dis[nx][ny]=dis[cx][cy]+ndis;
				if(ndis==1) qx.push_back(nx),qy.push_back(ny);
				else qx.push_front(nx),qy.push_front(ny);
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(!ingrid(i,j)) continue;
			int lc,rc;
			lc=rc=dis[i][j];
			if(j<=c) lc+=c-j;
			else rc+=j-c;
			if(lc<=p && rc<=q) ans++;
		}
	}
	cout << ans << endl;
}