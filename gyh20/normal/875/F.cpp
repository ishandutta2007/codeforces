#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define re register
#define int long long
using namespace std;
inline int read() {
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,my[100002],f[2][40002],ans1,fa[200002],bh[200002],rd[102],ans2,val[102],siz[102],mmx,vvv;
long long ans,sum;
struct node {
	int a,b,c;
	bool operator <(const node x)const {
		return c>x.c;
	}
} pp[200002],a[200002];
inline int root(re int x) {
	return x==fa[x]?x:fa[x]=root(fa[x]);
}
inline void merge(re int x,re int y) {
	x=root(x),y=root(y);
	if(x^y)fa[x]=y,val[y]+=val[x];
}
inline bool dfs(re int x,re int y=0) {
	if(!my[pp[x].a]) {
		my[pp[x].a]=x;
		return 1;
	}
	if(!my[pp[x].b]) {
		my[pp[x].b]=x;
		return 1;
	}
	if(!y) {
		re int xx=my[pp[x].a];
		if(dfs(xx,pp[x].a))return my[pp[x].a]=x,1;
		my[pp[x].a]=xx;
	}
	if(pp[x].b^y) {
		re int xx=my[pp[x].b];
		if(dfs(xx,pp[x].b))return my[pp[x].b]=x,1;
	}
	return 0;
}
int head[300002],b,c,d,cnt=1,S,T,dis[300002],pre[300002],p[300002],vv[300002];
struct edge {
	int next,w,to,ww,fr;
} e[2000002];
void bu(register int u,register int v,register int w,re int ww) {
	if(w==0)return;
	e[++cnt].to=v;
	e[cnt].ww=ww;
	e[cnt].w=w;
	e[cnt].fr=u;
	e[cnt].next=head[u];
	head[u]=cnt;
	e[++cnt].to=u;
	e[cnt].fr=v;
	e[cnt].ww=-ww;
	e[cnt].next=head[v];
	head[v]=cnt;
}
deque <int> q;
int spfa(register int s,register int t) {

	memset(p,0,sizeof(p));
	memset(dis,127,sizeof(dis));
	memset(vv,0,sizeof(vv));
	bool zzw=0;
	q.push_front(s);
	dis[s]=0;
	vv[s]=1;
	while(!q.empty()) {
		int r=q.front();
		q.pop_front();
		vv[r]=0;
		if(r==t)zzw=1;
		for(register int i=head[r]; i; i=e[i].next) {
			if(e[i].w&&dis[e[i].to]>dis[r]+e[i].ww) {
				dis[e[i].to]=dis[r]+e[i].ww;
				p[e[i].to]=i;
				if(!vv[e[i].to]) {

					vv[e[i].to]=1;
					if(!q.empty()&&dis[e[i].to]<dis[q.front()])
						q.push_front(e[i].to);
					else q.push_back(e[i].to);
				}
			}
		}
	}
	if(zzw)return 1;
	return 0;
}
void dfs() {
	int tmp=0x7fffffff,cnt=0,pp;
	for(re int i=T; i!=S; i=e[pp^1].to) {
		pp=p[i];
		cnt+=e[pp].ww;
		tmp=min(tmp,e[pp].w);
	}
	for(re int i=T; i!=S; i=e[pp^1].to) {
		pp=p[i];
		e[pp].w-=tmp,e[pp^1].w+=tmp;
	}

	ans1+=tmp,ans2+=tmp*cnt;
}

signed main() {
//	freopen("there.in","r",stdin);
//	freopen("there.out","w",stdout);
	m=read(),n=read();
	for(re int i=1; i<=n; ++i)pp[i].a=read(),pp[i].b=read(),pp[i].c=read();
	sort(pp+1,pp+n+1);
	for(re int i=1;i<=m;++i)fa[i]=i;
//	for(re int i=1;i<=n;++i)if(dfs(i))ans+=pp[i].c;
	for(int i=1; i<=n; ++i)		{
		re int x=root(pp[i].a),y=root(pp[i].b);
		if(x^y)				{
			if(!bh[x]||!bh[y]) ans2+=pp[i].c,fa[y]=x,bh[x]=((bh[x]==0&&bh[y]==0)?0:1);
		}			else				if(!bh[x]) ans2+=pp[i].c,bh[x]=1;
	}
	printf("%lld",ans2);
}