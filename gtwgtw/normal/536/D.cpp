#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Forn(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=2005;
const int M=100005;

int n,m,s,t,p[N];
struct edge{
	int u,v,w,pre;
}e[M*2]; int dex,adj[N];
long long ds[N],dt[N];
int vis[N],Q[N*30],l,r,sz[N][N];
long long a[N][N],sm[N][N],f[N][N][2][2],x[N],y[N];
bool V[N][N][2][2];

void spfa(int x,long long *d){
	memset(d,0x3f,sizeof ds);
	memset(vis,0,sizeof vis);
	d[Q[vis[x]=l=r=1]=x]=0;
	for(int u;l<=r;l++){
		u=Q[l];
		for(int i=adj[u];i;i=e[i].pre){
			int v=e[i].v;
			if(d[u]+e[i].w<d[v]){
				d[v]=d[u]+e[i].w;
				if(!vis[v]) vis[Q[++r]=v]=1;
			}
		}  vis[u]=0;
	}
}

long long sum=0;

long long Ask(int a,int b,int c,int d){
	return sm[c][d]-sm[a][b];
}

int size(int a,int b,int c,int d){
	return (sz[c][d]-sz[a][b])>0;
}

long long F(int A,int B,int a,int b){
	if(A>*x || B>*y) return 0;
	if(V[A][B][a][b]) return f[A][B][a][b];
	V[A][B][a][b]=1;
	long long z=0;
	if(a) z=F(A,B+1,a,b||size(A,B+1,A,B))+Ask(A,B+1,A,B);
	else z=F(A+1,B,a,b||size(A+1,B,A,B))+Ask(A+1,B,A,B);	
	if(b) z=max(z,-F(A,B,a^1,0));
	return f[A][B][a][b]=z;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	For(i,1,n) scanf("%d",p+i),sum+=p[i];
	For(i,1,m){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[++dex]=(edge){x,y,w,adj[x]}; adj[x]=dex;
		e[++dex]=(edge){y,x,w,adj[y]}; adj[y]=dex;
	}
	spfa(s,ds); spfa(t,dt);
	For(i,1,n) x[i]=ds[i],y[i]=dt[i];
	sort(x+1,x+n+1); *x=unique(x+1,x+n+1)-(x+1);
	sort(y+1,y+n+1); *y=unique(y+1,y+n+1)-(y+1);
	For(i,1,n){
		ds[i]=lower_bound(x+1,x+*x+1,ds[i])-x;
		dt[i]=lower_bound(y+1,y+*y+1,dt[i])-y;
		a[ds[i]][dt[i]]+=p[i];
		sz[ds[i]][dt[i]]++;
	}
	Forn(i,*x,1) Forn(j,*y,1){
		sm[i][j]=sm[i][j+1]+sm[i+1][j]-sm[i+1][j+1]+a[i][j];
		sz[i][j]+=sz[i][j+1]+sz[i+1][j]-sz[i+1][j+1];
	}
	long long ans=F(1,1,0,0);
	if(ans<0) puts("Cry");
	if(ans>0) puts("Break a heart");
	if(ans==0) puts("Flowers");
	return 0;
}