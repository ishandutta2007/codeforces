#include<iostream>
#include<queue>
using namespace std;
int n,m;
bool ingrid(int i,int j){
	return (i>0 && i<=n && j>0 && j<=m);
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	int conn[n+1][m+1][4],dis[n+1][m+1][4];
	int moves[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	char c;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c;
			switch(c){
				case '+': {int p[4]={1,1,1,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '|': {int p[4]={1,0,1,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '-': {int p[4]={0,1,0,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '^': {int p[4]={1,0,0,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '>': {int p[4]={0,1,0,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '<': {int p[4]={0,0,0,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case 'v': {int p[4]={0,0,1,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case 'L': {int p[4]={1,1,1,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case 'R': {int p[4]={1,0,1,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case 'U': {int p[4]={0,1,1,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case 'D': {int p[4]={1,1,0,1};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
				case '*': {int p[4]={0,0,0,0};for(int k=0; k<4 ;k++){conn[i][j][k]=p[k];}}break;
			}
		}
	}
	int xm,ym,xr,yr;
	cin >> xr >> yr >> xm >> ym;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			for(int k=0; k<4 ;k++){
				dis[i][j][k]=2e9;
			}
		}
	}
	queue<pair<int,pair<int,int> > >q;
	q.push(make_pair(0,make_pair(xr,yr)));
	dis[xr][yr][0]=0;
	while(!q.empty()){
		int ori=q.front().first;
		pair<int,int>cur=q.front().second;
		q.pop();
		for(int i=0; i<4 ;i++){//four directions
			if(ingrid(cur.first+moves[i][0],cur.second+moves[i][1]) && dis[cur.first+moves[i][0]][cur.second+moves[i][1]][ori]==2e9){
				if(conn[cur.first][cur.second][(i-ori+4)%4]==1 && conn[cur.first+moves[i][0]][cur.second+moves[i][1]][(i-ori+6)%4]==1){
					dis[cur.first+moves[i][0]][cur.second+moves[i][1]][ori]=dis[cur.first][cur.second][ori]+1;
					q.push(make_pair(ori,make_pair(cur.first+moves[i][0],cur.second+moves[i][1])));
				}
			}
		}
		if(dis[cur.first][cur.second][(ori+1)%4]==2e9){
			dis[cur.first][cur.second][(ori+1)%4]=dis[cur.first][cur.second][ori]+1;
			q.push(make_pair((ori+1)%4,cur));
		}
	}
	int ans=dis[xm][ym][0];
	for(int i=1; i<4 ;i++){
		ans=min(ans,dis[xm][ym][i]);
	}
	if(ans==2e9){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
}