#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n,m,K;
#define Maxn 150010

ll Ans;
namespace sub{
	int head[Maxn<<1],nxt[12000010],tot=0;pii v[12000010];
	int sum[Maxn<<1],lst[Maxn<<1];
	void run(int p,int l,int r){
		tot++;v[tot]=pii(p,1);nxt[tot]=head[l];head[l]=tot;
		tot++;v[tot]=pii(p,-1);nxt[tot]=head[r+1];head[r+1]=tot;
	}
	void init(){
		tot=0;memset(head,0,sizeof(int)*(2*n+1));
	}
	void calc(){
		rep(i,1,2*n)sum[i]=0,lst[i]=1;
		rep(u,1,n)
			for(int i=head[u];i;i=nxt[i]){
				Ans+=1ll*(u-lst[v[i].FR])*sum[v[i].FR]*(sum[v[i].FR]-1)/2;
				sum[v[i].FR]+=v[i].SE;lst[v[i].FR]=u;
			}
		rep(u,1,2*n)
			Ans+=1ll*(n+1-lst[u])*sum[u]*(sum[u]-1)/2;
	}
}

int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int dfn[Maxn],seq[Maxn],dfk=0;
int son[Maxn],siz[Maxn],top[Maxn],fa[Maxn],dep[Maxn];
void dfs1(int u,int f){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^f){
			fa[v[i]]=u;dep[v[i]]=dep[u]+1;
			dfs1(v[i],u);siz[u]+=siz[v[i]];
			if(!son[u]||siz[v[i]]>siz[son[u]])son[u]=v[i];
		}
}
void dfs2(int u,int tp){
	top[u]=tp;dfn[u]=++dfk;seq[dfk]=u;
	if(!son[u])return;
	dfs2(son[u],tp);
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=fa[u]&&v[i]!=son[u])dfs2(v[i],v[i]);
}

int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b])swap(a,b);
	return a;
}
int go_up(int u,int d){
	int t=dep[u]-d;
	while(dep[top[u]]>t)u=fa[top[u]];
	return seq[t-dep[top[u]]+dfn[top[u]]];
}

int p[Maxn];
pii path[Maxn];int lc[Maxn];

void gao(int u,int f){
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			gao(v[i],u);
			p[u]+=p[v[i]];
		}
	Ans+=1ll*p[u]*(p[u]-1)/2;
}

pii h1[105],h2[105];int cnt1,cnt2;

void init(int u,int lca,pii *h,int &cnt){
	cnt=0;
	while(dep[top[u]]>dep[lca]){
		h[++cnt]=pii(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[lca])h[++cnt]=pii(dfn[lca]+1,dfn[u]);
}

ll calc(){
	Ans=0;
	rep(u,1,n)p[u]=0;
	rep(i,1,m){
		int a=path[i].FR,b=path[i].SE,lca=lc[i];
		if(dfn[a]>dfn[b])swap(a,b);
		if(dep[a]-dep[lca]>=K){
			p[a]++;
			a=go_up(a,dep[a]-dep[lca]-K+1);
			p[a]--;
		}
		if(dep[b]-dep[lca]>=K){
			p[b]++;
			b=go_up(b,dep[b]-dep[lca]-K+1);
			p[b]--;
		}
		if(a==lca||b==lca)continue;
		assert(K>1);
		init(a,lca,h1,cnt1);init(b,lca,h2,cnt2);
		int t=K-(dep[a]-dep[lca]);
		int p1=1,p2=cnt2;
		while(p2&&h2[p2].SE-h2[p2].FR+1<t){
			t-=h2[p2].SE-h2[p2].FR+1;
			p2--;
		}
		int r2=h2[p2].SE-h2[p2].FR+1-t+1,r1=h1[1].SE-h1[1].FR+1;
		while(p1<=cnt1&&p2){
			int len=min(r1,r2);
			sub::run(h1[p1].FR+r1-1+h2[p2].SE-r2+1,h1[p1].FR+r1-1-len+1,h1[p1].FR+r1-1);
			if(r1==len){
				p1++;r1=h1[p1].SE-h1[p1].FR+1;
			}else r1-=len;
			if(r2==len){
				p2--;
				r2=h2[p2].SE-h2[p2].FR+1;
			}else r2-=len;
		}
	}
	gao(1,0);
	sub::calc();
	return Ans;
}

int main(){
	rd(n);rd(m);rd(K);
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	}
	dfs1(1,0);
	dfs2(1,1);
	rep(i,1,m){
		rd(path[i].FR);rd(path[i].SE);
		lc[i]=LCA(path[i].FR,path[i].SE);
	}
	ll res=calc();
	K++;sub::init();res-=calc();
	printf("%lld\n",res);
	return 0;
}