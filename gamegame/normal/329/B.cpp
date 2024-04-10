#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m;
char c[1001][1001];
queue<int>qx,qy;
int dis[1001][1001];
bool ingrid(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m && c[x][y]!='T';
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int sx,sy,ex,ey;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
			if(c[i][j]=='S'){
				sx=i;sy=j;
			}
			else if(c[i][j]=='E'){
				ex=i;ey=j;
			}
			dis[i][j]=1e9;
		}
	}
	dis[ex][ey]=0;
	qx.push(ex);qy.push(ey);
	while(!qx.empty()){
		int cx=qx.front(),cy=qy.front();
		qx.pop();qy.pop();
		for(int i=0; i<4 ;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if(!ingrid(nx,ny) || dis[nx][ny]<=dis[cx][cy]+1) continue;
			dis[nx][ny]=dis[cx][cy]+1;
			qx.push(nx);qy.push(ny);
		}
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			if(c[i][j]>=48 && c[i][j]<=57 && dis[i][j]<=dis[sx][sy]) ans+=c[i][j]-48;
		}
	}
	cout << ans << endl;
}