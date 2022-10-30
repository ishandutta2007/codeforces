#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 500050
#define M (1<<22)
#define inf 0x3f3f3f3f
int head[N],to[N<<1],nxt[N<<1],cnt,n,val[N<<1];
int mx[M],siz[N],ans[N],son[N];
int dfn[N],idf[N],enp[N];
int nowans,dep[N],len[N];
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
void df1(int x,int y) {
	int i;
	siz[x]=1; len[x]=len[y]+1;
	dfn[x]=++dfn[0]; idf[dfn[0]]=x;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dep[to[i]]=dep[x]^(1<<val[i]);
		df1(to[i],x);
		siz[x]+=siz[to[i]];
		if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
	}
	enp[x]=dfn[0];
}
void df2(int x,int y,int opt) {
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y&&to[i]!=son[x]) {
		df2(to[i],x,0); ans[x]=max(ans[x],ans[to[i]]);
	}
	if(son[x]) {
		df2(son[x],x,1);
		ans[x]=max(ans[x],ans[son[x]]);
		nowans=max(nowans,mx[dep[x]]-len[x]);
		for(i=0;i<22;i++) nowans=max(nowans,mx[dep[x]^(1<<i)]-len[x]);
	}
	mx[dep[x]]=max(mx[dep[x]],len[x]);
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y&&to[i]!=son[x]) {
		int t=to[i],j,p,k;
		for(j=dfn[t];j<=enp[t];j++) {
			p=idf[j];
			nowans=max(nowans,mx[dep[p]]+len[p]-len[x]*2);
			for(k=0;k<22;k++) nowans=max(nowans,mx[ dep[p]^(1<<k) ]+len[p]-len[x]*2);
		}
		for(j=dfn[t];j<=enp[t];j++) {
			p=idf[j];
			mx[dep[p]]=max(mx[dep[p]],len[p]);
		}
	}
	ans[x]=max(ans[x],nowans);
	if(!opt) {
		nowans=-inf;
		for(i=dfn[x];i<=enp[x];i++) mx[dep[idf[i]]]=-inf;
	}
}
int main() {
	memset(mx,0xc0,sizeof(mx));
	scanf("%d",&n);
	int i,x; 
	char op[4];
	for(i=2;i<=n;i++) {
		scanf("%d%s",&x,op);
		add(x,i,op[0]-'a'); add(i,x,op[0]-'a');
	}
	df1(1,0);
	df2(1,0,1);
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}