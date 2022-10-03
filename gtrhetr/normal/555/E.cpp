#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct node { int t,v,next; }a[400010];

unordered_map<int,bool> mp[200010];

vector<int> v[200010];
stack<int> st;

pii h[200010];

int fa[200010][20],dep[200010],s1[200010],s2[200010];
int head[200010],dfn[200010],low[200010],from[200010],n,m,q,cl,cnt,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline int find(int x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline void dfs(int x,int y)
{
	dfn[x]=low[x]=++cl;st.push(x);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (!dfn[t])
		{
			dfs(t,a[i].v);
			low[x]=min(low[x],low[t]);
			if (low[t]>dfn[x])
			{
				cnt++;
				while (233)
				{
					int hh=st.top();st.pop();
					from[hh]=cnt;
					if (hh==t) break;
				}
			}
		}
		else if (a[i].v!=y) low[x]=min(low[x],dfn[t]);
	}
}

inline void dfs(int x)
{
	for (int t:v[x]) if (t!=fa[x][0]) dep[t]=dep[x]+1,fa[t][0]=x,dfs(t);
}

inline void gao(int x)
{
	for (int t:v[x]) if (t!=fa[x][0]) gao(t),s1[x]+=s1[t],s2[x]+=s2[t];
}

inline int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	for (int i=17;~i;i--) if ((t>>i)&1) x=fa[x][i];
	if (x==y) return x;
	for (int i=17;~i;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main()
{
	n=rd();m=rd();q=rd();
	for (int i=1;i<=n;i++) from[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		add(x,y,i);add(y,x,i);
		from[find(x)]=find(y);
	}
	for (int i=1;i<=q;i++)
	{
		h[i].first=rd();h[i].second=rd();
		if (find(h[i].first)!=find(h[i].second)) { puts("No");return 0; }
	}
	memset(from,0,sizeof(from));
	cl=cnt=0;
	for (int i=1;i<=n;i++) if (!dfn[i])
	{
		dfs(i,0);cnt++;
		while (!st.empty()) from[st.top()]=cnt,st.pop();
	}
	for (int i=1;i<=n;i++) for (int j=head[i];j;j=a[j].next) if (from[i]!=from[a[j].t]&&!mp[from[i]][from[a[j].t]])
	{
		mp[from[i]][from[a[j].t]]=mp[from[a[j].t]][from[i]]=true;
		v[from[i]].push_back(from[a[j].t]);
		v[from[a[j].t]].push_back(from[i]);
	}
	for (int i=1;i<=cnt;i++) if (!fa[i][0]) dep[i]=1,dfs(i);
	for (int j=1;j<18;j++) for (int i=1;i<=cnt;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=q;i++)
	{
		h[i].first=from[h[i].first];h[i].second=from[h[i].second];
		int hh=lca(h[i].first,h[i].second);
		s1[h[i].first]++;s1[hh]--;
		s2[h[i].second]++;s2[hh]--;
	}
	for (int i=1;i<=cnt;i++) if (!fa[i][0]) gao(i);
	for (int i=1;i<=cnt;i++) if (s1[i]&&s2[i]) { puts("No");return 0; }
	puts("Yes");
	return 0;
}