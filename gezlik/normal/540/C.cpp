#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=500;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int n,m,sx,sy,tx,ty;
char s[N+9][N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%s",s[i]+1);
  scanf("%d%d",&sx,&sy);
  scanf("%d%d",&tx,&ty);
}

bool Out_map(int x,int y){return x<1||x>n||y<1||y>m;}

int vis[N+9][N+9];

bool Dfs(int x,int y,int tx,int ty){
  vis[x][y]=1;
  if (x==tx&&y==ty) return 1;
  for (int i=0;i<4;++i){
	int u=x+dx[i],v=y+dy[i];
	if (Out_map(u,v)) continue;
	if (vis[u][v]) continue;
	if (Dfs(u,v,tx,ty)) return 1;
  }
  return 0;
}

bool Check(int sx,int sy,int tx,int ty){
  for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j) vis[i][j]=s[i][j]=='X';
  return Dfs(sx,sy,tx,ty);
}

int can[4][4];

void work(){
  if (sx==tx&&sy==ty){
	for (int i=0;i<4;++i){
	  int x=tx+dx[i],y=ty+dy[i];
	  if (Out_map(x,y)) continue;
	  if (s[x][y]=='X') continue;
	  puts("YES");
	  return;
	}
	puts("NO");
	return;
  }
  if (s[tx][ty]=='X'){
	s[tx][ty]='.';
	puts(Check(sx,sy,tx,ty)?"YES":"NO");
	return;
  }
  s[tx][ty]='X';
  for (int i=0;i<4;++i){
	int u=tx+dx[i],v=ty+dy[i];
	if (Out_map(u,v)) continue;
	if (!Check(sx,sy,u,v)) continue;
	for (int j=0;j<4;++j){
	  if (i==j) continue;
	  int x=tx+dx[j],y=ty+dy[j];
	  if (Out_map(x,y)) continue;
	  if (s[x][y]=='X') continue;
	  puts("YES");
	  return;
	}
  }
  puts("NO");
}

void outo(){
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