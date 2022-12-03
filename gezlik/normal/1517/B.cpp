#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100;

int n,m,a[N+9][N+9];
struct point{
  int x,y,v;
  point(int X=0,int Y=0,int V=0){x=X;y=Y;v=V;}
  bool operator < (const point &p)const{return v<p.v;}
}b[N*N+9];
int vis[N+9][N+9];

void into(){
  scanf("%d%d",&n,&m);
  int cb=0;
  for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j)
	  scanf("%d",&a[i][j]);
    sort(a[i]+1,a[i]+m+1);
	for (int j=1;j<=m;++j) b[++cb]=point(i,j,a[i][j]);
  }
  sort(b+1,b+n*m+1);
  for (int i=1;i<=m;++i) vis[b[i].x][b[i].y]=1;
}

int cnt[N+9],ans[N+9][N+9];

void work(){
  for (int i=1;i<=n;++i) cnt[i]=m;
  for (int i=m;i>=1;--i){
	int x=b[i].x;
	ans[x][i]=b[i].v;
	for (int j=1;j<=n;++j)
	  if (j^x) ans[j][i]=a[j][cnt[j]--];
  }
}

void outo(){
  for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j) printf("%d ",ans[i][j]);
	puts("");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}