#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100050
typedef long long ll;
ll f[N],g[N];
int head[N],to[N<<1],nxt[N<<1],cnt,n,m;
int fa[N],dep[N],top[N],son[N],siz[N];
int S[N],a[N],la,tp,vis[N],dfn[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x,int y) {
	int i; siz[x]=1; fa[x]=y; dep[x]=dep[y]+1; 
	dfn[x]=++dfn[0];
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df1(to[i],x); siz[x]+=siz[to[i]];
		if(siz[to[i]]>siz[son[x]]) son[x]=to[i];
	}
}
void df2(int x,int t) {
	top[x]=t;
	if(son[x]) df2(son[x],t);
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=fa[x]&&to[i]!=son[x]) df2(to[i],to[i]);
}
int lca(int x,int y) {
	for(;top[x]!=top[y];y=fa[top[y]]) if(dep[top[x]]>dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
inline bool cmp(const int &x,const int &y) {return dfn[x]<dfn[y];}
void df3(int x) {
	int i;
	ll sf=0,smn=0,mx=0,ss=0;
	for(i=head[x];i;i=nxt[i]) {
		df3(to[i]);
		sf+=f[to[i]];
		smn+=min(f[to[i]],g[to[i]]);
		mx=max(mx,f[to[i]]-g[to[i]]);
		if(dep[to[i]]-dep[x]>1) {
			ss+=min(f[to[i]],g[to[i]]+1);
		}else ss+=f[to[i]];
	}
	if(vis[x]) {
		f[x]=int(0x3f3f3f3f);
		g[x]=ss;
	}else {
		f[x]=min(ss,smn+1);
		g[x]=sf-mx;
	}
	head[x]=0;
}
int main() {
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	df1(1,0); df2(1,1);
	memset(head,0,sizeof(head)); cnt=0;
	scanf("%d",&m);
	while(m--) {
		scanf("%d",&la); cnt=0;
		for(i=1;i<=la;i++) scanf("%d",&a[i]),vis[a[i]]=1;
		int flg=0;
		for(i=1;i<=la;i++) {
			if(vis[fa[a[i]]]) {
				flg=1; break;
			}
		}
		if(flg) {
			puts("-1");
			for(i=1;i<=la;i++) vis[a[i]]=0;
			continue;
		}
		sort(a+1,a+la+1,cmp);
		S[tp=1]=1;
		for(i=1;i<=la;i++) {
			x=a[i],y=lca(x,S[tp]);
			while(dep[y]<dep[S[tp]]) {
				if(dep[y]>=dep[S[tp-1]]) {
					add(y,S[tp]); tp--;
					if(S[tp]!=y) S[++tp]=y;
					break;
				}
				add(S[tp-1],S[tp]); tp--;
			}
			if(S[tp]!=x) S[++tp]=x;
		}
		while(tp>1) add(S[tp-1],S[tp]),tp--;
		df3(1);
		printf("%lld\n",min(f[1],g[1]));
		for(i=1;i<=la;i++) vis[a[i]]=0;
	}
}