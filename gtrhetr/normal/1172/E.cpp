#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<int> v[400010];
vector<pii> g[400010];

ll c[400010],now=0;
int fat[400010],col[400010],n,m;
bool bo[400010];

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

inline void pre_dfs(int x) { for (int t:v[x]) if (t!=fat[x]) fat[t]=x,pre_dfs(t); }

ll sum[400010],s[400010],num[400010],size[400010];
int ch[400010][2],fa[400010];

inline ll calc(const int &x) { return sum[x]+size[x]*size[x]; }

inline bool isroot(const int &x) { return (ch[fa[x]][0]!=x)&&(ch[fa[x]][1]!=x); }

inline void pushup(const int &o)
{
	size[o]=size[ch[o][0]]+size[ch[o][1]]+(num[o]+1)*(!bo[o]);
	sum[o]=sum[ch[o][0]]+sum[ch[o][1]]+s[o]*bo[o];
}

inline void rotate(int x)
{
	int y=fa[x],z=fa[y],l=(ch[y][1]==x);
	if (!isroot(y)) ch[z][ch[z][1]==y]=x;
	ch[y][l]=ch[x][l^1];ch[x][l^1]=y;
	fa[ch[y][l]]=y;fa[y]=x;fa[x]=z;
	pushup(y);pushup(x);
}

inline void splay(int x)
{
	while (!isroot(x))
	{
		int y=fa[x],z=fa[y];
		if (!isroot(y))
		{
			if ((ch[y][0]==x)^(ch[z][0]==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}

inline void access(int x)
{
	for (int y=0;x;y=x,x=fa[x])
	{
		splay(x);
		num[x]+=size[ch[x][1]]-size[y];
		s[x]+=calc(ch[x][1])-calc(y);
		ch[x][1]=y;pushup(x);
	}
}

inline void link(int x,int y)
{
	access(x);splay(x);access(y);splay(y);
	now-=calc(x)+calc(y);
	bo[x]^=1;fa[x]=y;pushup(x);
	num[y]+=size[x];s[y]+=calc(x);pushup(y);
	now+=calc(y);
}

inline void cut(int x)
{
	access(x);splay(x);
	now-=calc(x);
	int hh=ch[x][0];
	fa[hh]=0;ch[x][0]=0;
	bo[x]^=1;pushup(x);
	now+=calc(x)+calc(hh);
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) g[col[i]=rd()].push_back(pii(i,0));
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	fat[1]=n+1;pre_dfs(1);
	for (int i=1;i<=n+1;i++) bo[i]=true;
	for (int i=1;i<=n;i++) link(i,fat[i]);
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		g[col[x]].push_back(pii(x,i));
		g[y].push_back(pii(x,i));
		col[x]=y;
	}
	for (int i=1;i<=n;i++)
	{
		for (pii hh:g[i])
		{
			ll lst=now;
			if (bo[hh.first]) link(hh.first,fat[hh.first]);
			else cut(hh.first);
			c[hh.second]+=(lst-now);
		}
		for (pii hh:g[i]) if (bo[hh.first]) link(hh.first,fat[hh.first]);
	}
	for (int i=1;i<=m;i++) c[i]+=c[i-1];
	for (int i=0;i<=m;i++) print(c[i]);
	return 0;
}