#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
typedef long long ll;
int head[N],to[N<<1],nxt[N<<1],cnt,n,w[N];
int idf[N],dfn[N],enp[N],fa[N],siz[N],son[N];
int col[N],mx;
ll nowsum,ans[N];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
char buf[100000],*p1,*p2;
inline int rd()
{
	register int x=0;register char c=nc();
	while(c<48)c=nc();
	while(c>47)x=((x+(x<<2))<<1)+(c^48),c=nc();
	return x;
}
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x,int y) {
	int i; siz[x]=1; fa[x]=y; dfn[x]=++dfn[0];
	idf[dfn[0]]=x;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df1(to[i],x);
		siz[x]+=siz[to[i]];
		if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
	}
	enp[x]=dfn[0];
}
void up(int x) {
	col[x]++;
	if(col[x]>=mx) {
		if(col[x]>mx) mx=col[x],nowsum=0;
		nowsum+=x;
	}
}
void df2(int x,int op) {
	int i,j,y;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=fa[x]&&to[i]!=son[x]) {
		df2(to[i],0);
	}
	if(son[x]) df2(son[x],1);
	up(w[x]);
	for(i=head[x];i;i=nxt[i]) if(to[i]!=fa[x]&&to[i]!=son[x]) {
		y=to[i];
		for(j=dfn[y];j<=enp[y];j++) up(w[idf[j]]);
	}
	ans[x]=nowsum;
	if(!op) {
		for(i=dfn[x];i<=enp[x];i++) col[w[idf[i]]]--;
		nowsum=mx=0;
	}
}
int main() {
	n=rd();
	int i;
	for(i=1;i<=n;i++) w[i]=rd();
	int x,y;
	for(i=1;i<n;i++) x=rd(),y=rd(),add(x,y),add(y,x);
	df1(1,0);
	df2(1,1);
	for(i=1;i<=n;i++) printf("%lld ",ans[i]);
}