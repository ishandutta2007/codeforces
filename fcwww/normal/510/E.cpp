#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1050
#define M 2000050
#define S 1049
#define T 1048
#define inf 0x3f3f3f3f
int head[M],nxt[M],to[M],cnt=1,n,flow[M];
int dep[N],Q[N],a[N];
int vis[M],pri[M],pri_cnt,ch[N][2];
int vec[N][N],vsize[N],inv[N];
void sieve() {
	int i,j,lim=15000;
	for(i=2;i<=lim;i++) {
		if(!vis[i]) {
			pri[++pri_cnt]=i;
		}
		for(j=1;j<=pri_cnt&&i*pri[j]<=lim;j++) {
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
inline void add(int u,int v,int f) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; flow[cnt]=f;
	to[++cnt]=u; nxt[cnt]=head[v]; head[v]=cnt; flow[cnt]=0;
}
bool bfs() {
	int i;
	memset(dep,0,sizeof(dep));
	int l=0,r=0;
	Q[r++]=S; dep[S]=1;
	while(l<r) {
		int x=Q[l++];
		for(i=head[x];i;i=nxt[i]) if(flow[i]&&!dep[to[i]]) {
			dep[to[i]]=dep[x]+1;
			if(to[i]==T) return 1;
			Q[r++]=to[i];
		}
	}
	return 0;
}
int dfs(int x,int mf) {
	int i,nf=0;
	if(x==T) return mf;
	for(i=head[x];i;i=nxt[i]) if(flow[i]&&dep[to[i]]==dep[x]+1) {
		int tmp=dfs(to[i],min(mf-nf,flow[i]));
		if(!tmp) dep[to[i]]=0;
		nf+=tmp;
		flow[i]-=tmp;
		flow[i^1]+=tmp;
		if(nf==mf) break;
	}
	return nf;
}
void dinic() {
	while(bfs()) {
		while(dfs(S,inf)>0);
	}
}
bool check(int x) {
	int i;
	for(i=1;i<=pri_cnt&&pri[i]*pri[i]<=x;i++) if(x%pri[i]==0) return 0;
	return 1;
}
int main() {
	sieve();
	scanf("%d",&n);
	int i,j,x;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) {
		if(!(a[i]&1)) {
			add(S,i,2);
			for(j=1;j<=n;j++) if(i!=j&&(a[j]&1)) {
				
				if(check(a[i]+a[j])) {
					add(i,j,1);
					if(i==1&&j==3) puts("FUCK");
				}
			}
		}else {
			add(i,T,2);
		}
	}
	dinic();
	int ERR=0;
	for(x=1;x<=n;x++) {
		if(!(a[x]&1)) {
			for(i=head[x];i;i=nxt[i]) if(to[i]!=S) {
				if(flow[i]==0) {
					if(!ch[x][0]) ch[x][0]=to[i];
					else ch[x][1]=to[i];
				}
			}
			if(!ch[x][1]) {ERR=1; break;}
		}else {
			for(i=head[x];i;i=nxt[i]) if(to[i]!=T) {
				if(flow[i]==1) {
					if(!ch[x][0]) ch[x][0]=to[i];
					else ch[x][1]=to[i];
				}
			}
			if(!ch[x][1]) {ERR=1; break;}
		}
	}
	if(ERR) {puts("Impossible"); return 0;}
	memset(vis,0,sizeof(vis));
	int tot=0;
	for(i=1;i<=n;i++) if(!vis[i]) {
		int tp=0;
		memset(inv,0,sizeof(inv));
		vec[++tot][++tp]=i; inv[i]=1;
		for(j=1;;j++) {
			int p=vec[tot][j];
			inv[p]=1;
			if(inv[ch[p][0]]&&inv[ch[p][1]]) break;
			if(inv[ch[p][0]]) {
				vec[tot][++tp]=ch[p][1];
			}else {
				vec[tot][++tp]=ch[p][0];
			}
		}
		for(j=1;j<=tp;j++) vis[vec[tot][j]]=1;
		vsize[tot]=tp;
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;i++) {
		printf("%d ",vsize[i]);
		for(j=1;j<=vsize[i];j++) {
			printf("%d ",vec[i][j]);
		}
		puts("");
	}
}