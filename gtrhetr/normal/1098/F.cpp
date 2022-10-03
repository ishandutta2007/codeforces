#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))

struct node { int t,next; }a[800010];

struct hhhh { int l,r; }h[200010];

vector<pii> v[400010];
vector<int> g[400010];

ll ans[400010];
int fa[400010],son[400010],dep[400010],top[400010],size[400010];
int fat[400010][20],head[400010],id[400010],c[400010],len[400010],n,m,tt,tot;
char s[400010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

namespace sam
{

int ch[400010][26],fa[400010],len[400010],tot,last;

inline void init() { tot=last=1; }

inline int insert(int x)
{
	int p=last,np=++tot;
	len[np]=len[p]+1;
	for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if (!p) fa[np]=1;
	else
	{
		int q=ch[p][x];
		if (len[q]==len[p]+1) fa[np]=q;
		else
		{
			int nq=++tot;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			len[nq]=len[p]+1;
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for (;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
	return last=np;
}

inline void build() { for (int i=2;i<=tot;i++) add(fa[i],i); }

}

inline void dfs1(int x)
{
	size[x]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		dep[t]=dep[x]+1;
		fa[t]=x;dfs1(t);
		size[x]+=size[t];
		if (size[t]>size[son[x]]) son[x]=t;
	}
}

inline void dfs2(int x,int tp)
{
	top[x]=tp;
	if (son[x]) dfs2(son[x],tp);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
}

struct bit
{
	ll c[200010];
	inline void add(int x,ll y) { for (;x<=n;x+=lowbit(x)) c[x]+=y; }
	inline void modify(int l,int r,ll hh) { add(l,hh);add(r+1,-hh); }
	inline ll query(int x)
	{
		ll res=0;
		for (;x>0;x-=lowbit(x)) res+=c[x];
		return res;
	}
	inline ll query(int l,int r) { return query(r)-query(l-1); }
}c1,c2,c3,c4,c5;

inline void work()
{
	int hh=len[fa[c[1]]]+1;
	for (int i=1;i<=tt;i++)
	{
		int x=c[i];
		for (int t:g[x])
		{
			int k=t+hh-1;
			c1.add(k,1);c2.add(k,k);
		}
	}
	for (int i=1;i<=tt;i++)
	{
		int x=c[i],now=len[x]-hh+1;
		for (pii hhh:v[x])
		{
			int t=hhh.first,now=hhh.second;
			int l=h[t].l,r=h[t].r;
			ans[t]+=c1.query(r-now)*now;
			ans[t]+=c1.query(r-now+1,r)*(r+1)-c2.query(r-now+1,r);
			ans[t]+=c3.query(r)+c4.query(r)*r-c5.query(r);
		}
		for (int t:g[x])
		{
			int k=t+hh-1;
			c1.add(k,-1);c2.add(k,-k);
			c3.add(k+now,now);
			c4.modify(k,k+now-1,1);
			c5.modify(k,k+now-1,k-1);
		}
	}
	for (int i=1;i<=tt;i++)
	{
		int x=c[i],now=len[x]-hh+1;
		for (int t:g[x])
		{
			int k=t+hh-1;
			c3.add(k+now,-now);
			c4.modify(k,k+now-1,-1);
			c5.modify(k,k+now-1,-k+1);
			c1.add(t,1);
		}
	}
	for (int i=1;i<=tt;i++)
	{
		int x=c[i],now=len[x]-hh+1;
		for (pii hhh:v[x])
		{
			int t=hhh.first,now=hhh.second;
			int l=h[t].l,r=h[t].r;
			ans[t]-=c1.query(l-1)*now;
			ans[t]-=c2.query(l-1);
		}
		for (int t:g[x]) c1.add(t,-1),c2.add(t,now);
	}
	for (int i=1;i<=tt;i++) for (int t:g[c[i]]) c2.add(t,-(len[c[i]]-hh+1));
}

inline int jump(int x,int y)
{
	for (int i=19;~i;i--) if (len[fat[x][i]]>=y) x=fat[x][i];
	return x;
}

inline void gao()
{
	for (int i=1;i<=sam::tot;i++) if (top[i]==i)
	{
		tt=0;
		for (int j=i;j;j=son[j]) if (j>1) c[++tt]=j;
		work();
	}
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);m=rd();
	sam::init();
	for (int i=n;i;i--) id[i]=sam::insert(s[i]-'a');
	sam::build();
	for (int i=1;i<=sam::tot;i++) len[i]=sam::len[i];
	dfs1(1);dfs2(1,1);
	for (int i=1;i<=sam::tot;i++) fat[i][0]=fa[i];
	for (int j=1;j<20;j++) for (int i=1;i<=sam::tot;i++) fat[i][j]=fat[fat[i][j-1]][j-1];
	for (int i=1;i<=m;i++) h[i].l=rd(),h[i].r=rd();
	for (int i=1;i<=m;i++)
	{
		int hh=jump(id[h[i].l],h[i].r-h[i].l+1);
		v[hh].push_back(pii(i,(h[i].r-h[i].l+1)-len[fa[top[hh]]]));
		for (int j=fa[top[hh]];j;j=fa[top[j]]) v[j].push_back(pii(i,len[j]-len[fa[top[j]]]));
	}
	for (int i=1;i<=n;i++) for (int j=id[i];j;j=fa[top[j]]) g[j].push_back(i);
	gao();
	for (int i=1;i<=m;i++) print(ans[i]);
	return 0;
}