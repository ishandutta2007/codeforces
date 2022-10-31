#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 300050
int n,m,head[N],to[N<<1],nxt[N<<1],cnt,S,tot,vis[N],ans[N],id[N<<1];
int flg[N<<1],Q[N];
struct A {
	int x,y;
}a[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
int main() {
	scanf("%d%d%d",&n,&m,&S);
	int i,o,x,y;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&o,&x,&y);
		if(o==1) add(x,y);
		else a[++tot]=(A){x,y},add(x,y),add(y,x),flg[cnt]=2,flg[cnt-1]=1,id[cnt]=id[cnt-1]=tot;
	}
	memset(ans,-1,sizeof(ans));
	int ans1=0,ans2=0;
	int l=0,r=0;
	Q[r++]=S; vis[S]=1;
	while(l<r) {
		x=Q[l++]; ans1++;
		for(i=head[x];i;i=nxt[i]) {
			if(!flg[i]&&!vis[to[i]]) {
				Q[r++]=to[i]; vis[to[i]]=1;
			}else if(flg[i]&&!vis[to[i]]&&ans[id[i]]==-1) {
				ans[id[i]]=flg[i]; Q[r++]=to[i]; vis[to[i]]=1;
			}
		}
	}
	printf("%d\n",ans1);
	for(i=1;i<=tot;i++) if(ans[i]==-1) ans[i]=1;
	for(i=1;i<=tot;i++) printf("%c",ans[i]==1?'+':'-');
	puts("");
	l=r=0;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	Q[r++]=S; vis[S]=1;
	while(l<r) {
		x=Q[l++]; ans2++;
		for(i=head[x];i;i=nxt[i]) {
			if(flg[i]&&ans[id[i]]==-1&&!vis[to[i]]) {
				ans[id[i]]=3-flg[i];
			}else if(flg[i]==0&&!vis[to[i]]) {
				Q[r++]=to[i]; vis[to[i]]=1;
			}
		}
	}
	printf("%d\n",ans2);
	for(i=1;i<=tot;i++) if(ans[i]==-1) ans[i]=1;
	for(i=1;i<=tot;i++) printf("%c",ans[i]==1?'+':'-');
}