#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double f2;
#define N 515
#define eps 1e-8
int head[N],to[N<<1],nxt[N<<1],val[N<<1],n,cnt,wa[N];
ll dis[N][N],X;
f2 a[N<<1][N];
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
void dfs(int x,int y,int rt,ll d) {
	dis[rt][x]=d;
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x,rt,d+val[i]);
	}
}
void pivot(int r,int c,int n,int m) {
	int i,j;
	f2 t=-a[r][c]; a[r][c]=-1;
	for(i=0;i<=n;i++) a[r][i]/=t;
	for(i=0;i<=m;i++) if(abs(a[i][c])>eps&&i!=r) {
		t=a[i][c]; a[i][c]=0;
		for(j=0;j<=n;j++) a[i][j]+=t*a[r][j];
	}
}
void simplex(int n,int m) {
	int i,j,k;
	f2 t;
	while(1) {
		i=j=0;
		t=-eps;
		for(k=1;k<=m;k++) if(a[k][0]<t) t=a[i=k][0];
		if(!i) break;
		for(k=1;k<=n;k++) if(a[i][k]>eps) {
			j=k; break;
		}
		if(!j) {puts("-1"); return ;}
		pivot(i,j,n,m);
	}
	while(1) {
		i=j=0;
		t=eps;
		for(k=1;k<=n;k++) if(a[0][k]>t) t=a[0][j=k];
		if(!j) break;
		t=1e9;
		for(k=1;k<=m;k++) if(a[k][j]<-eps&&(-a[k][0]/a[k][j])<t) {
			t=-a[k][0]/a[k][j]; i=k;
		}
		if(!i) {puts("INF"); return ;}
		pivot(i,j,n,m);
	}
	if(abs(a[0][0])<eps) puts("0");
	else if(-a[0][0]>n) puts("-1");
	else printf("%.0f\n",-a[0][0]/2);
}
int main() {
	scanf("%d%lld",&n,&X);
	int i,x,y,z,j,sum=0;
	for(i=1;i<=n;i++) scanf("%d",&wa[i]),sum+=wa[i];
	for(i=1;i<n;i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}
	for(i=1;i<=n;i++) {
		dfs(i,0,i,0);
	}
	for(i=1;i<=n;i++) a[0][i]=-1;
	for(i=1;i<=n;i++) {
		int t=0;
		for(j=1;j<=n;j++) {
			if(dis[i][j]<=X) {
				if(wa[j]) t++,a[i][j]=-1;
				else a[i][j]=1;
			}
		}
		a[i][0]=t-1;
	}
	int t=0;
	for(i=1;i<=n;i++) {
		if(wa[i]) t++,a[n+1][i]=-1;
		else a[n+1][i]=1;
	}
	a[n+1][0]=t-sum;
	t=0;
	for(i=1;i<=n;i++) {
		if(wa[i]) t--,a[n+2][i]=1;
		else a[n+2][i]=-1;
	}
	a[n+2][0]=t+sum;
	int tot=n+2;
	for(i=1;i<=n;i++) {
		a[++tot][i]=-1;
		a[tot][0]=1;
	}
	simplex(n,tot);
}