#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef long long ll;
typedef double db;
const int N=85;
const int M=N*N;

inline int IN(){
	char ch;CH; int f=0,x=0;
	for(;pend(ch);CH); if(ch=='-')f=1,CH;
	for(;!pend(ch);CH) x=x*10+ch-'0';
	return (f)?(-x):(x);
}

struct edge{
	int u,v,w,c,pre;
}e[5000005];int dex=1,adj[N*N];
int n,m,a[N][N],id[N][N],s,t,cnt;
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};

void addedge(int u,int v,int w,int c){
	e[++dex]=(edge){u,v,w,c,adj[u]};adj[u]=dex;
	e[++dex]=(edge){v,u,0,-c,adj[v]};adj[v]=dex;
}

int dis[M],Q[M*10],In[M],l,r,pre[M];
int spfa(){
	For(i,1,cnt) dis[i]=1e9,In[i]=pre[i]=0;
	dis[Q[l=r=1]=s]=0;
	for(;l<=r;l++){
		int u=Q[l]; In[u]=0;
		for(int i=adj[u];i;i=e[i].pre){
			if(!e[i].w)continue;
			int v=e[i].v;
			if(dis[u]+e[i].c<dis[v]){
				dis[v]=dis[u]+e[i].c;
				pre[v]=i;
				if(!In[v]) In[Q[++r]=v]=1;
			}
		}
	}
	return dis[t]<1e9;
}

int mincost(){
	int ans=0;
	while(spfa()){
		int aug=1e9;
		for(int i=t;i!=s;i=e[pre[i]].u){
			aug=min(aug,e[pre[i]].w);
		}
		ans+=aug*dis[t];
		for(int i=t;i!=s;i=e[pre[i]].u){
			e[pre[i]].w-=aug;
			e[pre[i]^1].w+=aug;
		}
	}
	return ans;
}

int main(){
	n=IN();m=IN();
	For(i,1,n) For(j,1,m) a[i][j]=IN();
	For(i,1,n) For(j,1,m) id[i][j]=++cnt;
	s=++cnt;t=++cnt;
	For(i,1,n) For(j,1,m) 
	if((i+j)&1){
		For(d,1,4){
			int ni=i+dx[d],nj=j+dy[d];
			if(ni<=0||nj<=0||ni>n||nj>m)continue;
			int u=id[i][j],v=id[ni][nj];
			if(a[i][j]^a[ni][nj]) addedge(u,v,1,1);
			else addedge(u,v,1,0);
		}
		addedge(s,id[i][j],1,0);
	}else addedge(id[i][j],t,1,0);
	
	printf("%d\n",mincost());
	return 0;
}