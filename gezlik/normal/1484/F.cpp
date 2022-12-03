#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=600;
const LL INF=(1LL<<60)-1;

int n,m,sk,e[N+9][N+9];
LL dis[N+9][N+9];
struct path{
  int y,lim;
  path(int Y=0,int Lim=0){y=Y;lim=Lim;}
};
vector<path>p[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j) dis[i][j]=i==j?0:INF;
  for (int i=1;i<=m;++i){
	int x,y,v;
	scanf("%d%d%d",&x,&y,&v);
	e[x][y]=e[y][x]=v;
	dis[x][y]=dis[y][x]=min(dis[x][y],1LL*v);
  }
  scanf("%d",&sk);
  for (int i=1;i<=sk;++i){
	int x,y,lim;
	scanf("%d%d%d",&x,&y,&lim);
	p[x].push_back(path(y,lim));
	p[y].push_back(path(x,lim));
  }
}

void Floyd(){
  for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j)
	  for (int k=1;k<=n;++k) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
}

LL mx[N+9];
int ans;

void Get_ans(){
  for (int i=1;i<=n;++i){
	for (int x=1;x<=n;++x){
	  mx[x]=-INF;
	  for (int vs=p[x].size(),j=0;j<vs;++j){
		int y=p[x][j].y,lim=p[x][j].lim;
		mx[x]=max(mx[x],lim-dis[i][y]);
	  }
	}
	for (int j=i+1;j<=n;++j){
	  if (!e[i][j]) continue;
	  for (int k=1;k<=n;++k)
		if (mx[k]>=dis[j][k]+e[i][j]) {++ans;break;}
	}
  }
}

void work(){
  Floyd();
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  int T=1;
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}