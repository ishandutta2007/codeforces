#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,M=50;

int n,m,sk;
char s[N+9][M+9];
struct side{
  int y,next;
}e[N*M*2+9];
int lin[3][N*M+9],cs;

void Ins(int id,int x,int y){e[++cs].y=y;e[cs].next=lin[id][x];lin[id][x]=cs;}

void into(){
  scanf("%d%d%d",&n,&m,&sk);
  for (int i=1;i<=m;++i){
	int x,y;
	scanf("%d%d",&x,&y);
	Ins(0,x,y);
  }
  for (int i=1;i<=n;++i)
	scanf("%s",s[i]);
}

int dfn[N+9],low[N+9],vis[N*M+9],co;
stack<int>sta;
int bel[N+9],cc;

void Tarjan(int k){
  dfn[k]=low[k]=++co;
  vis[k]=1;sta.push(k);
  for (int i=lin[0][k];i;i=e[i].next){
	if (!dfn[e[i].y]){
	  Tarjan(e[i].y);
	  low[k]=min(low[k],low[e[i].y]);
	}else if (vis[e[i].y]) low[k]=min(low[k],dfn[e[i].y]);
  }
  if (low[k]^dfn[k]) return;
  for (++cc;vis[k];){
	int t=sta.top();sta.pop();
	vis[t]=0;
	bel[t]=cc;
  }
}

void Contract(){
  for (int i=1;i<=n;++i)
	if (!dfn[i]) Tarjan(i);
  for (int k=1;k<=n;++k)
	for (int i=lin[0][k];i;i=e[i].next)
	  if (bel[k]==bel[e[i].y]) Ins(1,k,e[i].y);
}

int id[N+9][M+9],cid;

void Dfs_id(int k,int u){
  id[k][u]=cid;
  for (int i=lin[1][k];i;i=e[i].next){
	int y=e[i].y,v=u+1==sk?0:u+1;
	if (!id[y][v]) Dfs_id(y,v);
  }
}

int cnt[N*M+9];

void Get_id(){
  for (int i=1;i<=n;++i)
	for (int j=0;j<sk;++j){
	  if (id[i][j]) continue;
	  ++cid;
	  Dfs_id(i,j);
	}
  for (int i=1;i<=n;++i) vis[i]=0;
  for (int i=1;i<=n;++i){
	for (int j=0;j<sk;++j)
	  if (s[i][j]=='1'&&!vis[id[i][j]]) ++cnt[id[i][j]],vis[id[i][j]]=1;
    for (int j=0;j<sk;++j) vis[id[i][j]]=0;
  }
  for (int k=1;k<=n;++k)
	for (int i=lin[0][k];i;i=e[i].next){
	  int y=e[i].y;
	  if (bel[k]==bel[y]) continue;
	  for (int u=0;u<sk;++u){
		int v=u+1==sk?0:u+1;
		Ins(2,id[k][u],id[y][v]);
	  }
	}
}

int dp[N*M+9];

void Dfs_dp(int k){
  vis[k]=1;
  for (int i=lin[2][k];i;i=e[i].next){
	if (!vis[e[i].y]) Dfs_dp(e[i].y);
	dp[k]=max(dp[k],dp[e[i].y]);
  }
  dp[k]+=cnt[k];
}

void work(){
  Contract();
  Get_id();
  Dfs_dp(id[1][0]);
}

void outo(){
  printf("%d\n",dp[id[1][0]]);
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