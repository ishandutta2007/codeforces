#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,m;
struct side{
  int y,next,v;
}e[N+9];
int lin[N+9],cs;

void Ins(int x,int y,int v){e[++cs].y=y;e[cs].v=v;e[cs].next=lin[x];lin[x]=cs;}

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=m;++i){
	int x,y,v;
	scanf("%d%d%d",&x,&y,&v);
	Ins(x,y,v);
  }
}

int dfn[N+9],low[N+9],vis[N+9],co;
stack<int>sta;
int bel[N+9],cc;
LL dis[N+9],gk[N+9];

void Tarjan(int k){
  dfn[k]=low[k]=++co;
  vis[k]=1;sta.push(k);
  for (int i=lin[k];i;i=e[i].next){
	if (!dfn[e[i].y]){
	  dis[e[i].y]=dis[k]+e[i].v;
	  Tarjan(e[i].y);
	  low[k]=min(low[k],low[e[i].y]);
	}else if (vis[e[i].y]){
	  low[k]=min(low[k],dfn[e[i].y]);
	  gk[k]=__gcd(gk[k],dis[k]+e[i].v-dis[e[i].y]);
	}
  }
  if (low[k]^dfn[k]) return;
  for (++cc;vis[k];){
	int t=sta.top();sta.pop();
	vis[t]=0;
	bel[t]=cc;
  }
}

LL g[N+9];

void Contract(){
  for (int i=1;i<=n;++i)
	if (!dfn[i]) Tarjan(i);
  for (int i=1;i<=n;++i) g[bel[i]]=__gcd(g[bel[i]],gk[i]);
}

void work(){
  Contract();
}

void outo(){
  int cq;
  scanf("%d",&cq);
  for (;cq--;){
	int k;
	LL s,t;
	scanf("%d%lld%lld",&k,&s,&t);
	puts(s%__gcd(g[bel[k]],t)?"NO":"YES");
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