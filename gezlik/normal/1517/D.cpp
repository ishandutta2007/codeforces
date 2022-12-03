#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int n,m,sk,e[N+9][N+9][4];

void into(){
  scanf("%d%d%d",&n,&m,&sk);
  for (int i=1;i<=n;++i)
	for (int j=1;j<m;++j){
	  int x;
	  scanf("%d",&x);
	  e[i][j][0]=x;
	  e[i][j+1][1]=x;
	}
  for (int i=1;i<n;++i)
	for (int j=1;j<=m;++j){
	  int x;
	  scanf("%d",&x);
	  e[i][j][2]=x;
	  e[i+1][j][3]=x;
	}
}

int dis[11][N+9][N+9];

void Get_dis(){
  if (sk&1) return;
  for (int i=1;i<=sk>>1;++i)
	for (int x=1;x<=n;++x)
      for (int y=1;y<=m;++y){
		dis[i][x][y]=(1<<30)-1;
		for (int j=0;j<4;++j){
		  int u=x+dx[j],v=y+dy[j];
		  if (u<1||u>n||v<1||v>m) continue;
		  dis[i][x][y]=min(dis[i][x][y],dis[i-1][u][v]+e[x][y][j]);
		}
	  }
}

void work(){
  Get_dis();
}

void outo(){
  for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j) printf("%d ",sk&1?-1:dis[sk>>1][i][j]<<1);
	puts("");
  }
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}