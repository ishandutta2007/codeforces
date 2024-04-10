#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { int t,v,next; }a[600010];

vector<int> v[300010];

int ans=0;
int c[300010];
int from[300010],s0[300010],s1[300010],head[300010],col[300010],len[300010],n,k,tot;
bool vis[300010];
char s[300010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline int find(int x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline void pre_dfs(int x)
{
	vis[x]=true;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (vis[t]) continue;
		col[t]=col[x]^a[i].v;
		pre_dfs(t);
	}
}

inline int calc(int x)
{
	if (c[x]!=2) return (c[x]==0)?s0[x]:s1[x];
	return min(s0[x],s1[x]);
}

inline void merge(int x,int y)
{
	x=find(x);y=find(y);
	if (x==y) return;
	ans-=calc(x);ans-=calc(y);
	from[x]=y;s0[y]+=s0[x];s1[y]+=s1[x];
	if (c[x]!=2) c[y]=c[x];
	ans+=calc(y);
}

inline void change(int x,int hh)
{
	x=find(x);ans-=calc(x);
	c[x]=hh;ans+=calc(x);
}

int main()
{
	n=rd();k=rd();
	scanf("%s",s+1);
	for (int i=1;i<=k;i++)
	{
		len[i]=rd();
		for (int j=1;j<=len[i];j++) v[rd()].push_back(i);
	}
	ans=0;
	for (int i=1;i<=n;i++) if (v[i].size()==2)
	{
		int x=v[i][0],y=v[i][1];
		if (s[i]=='0') add(x,y,1),add(y,x,1);
		else add(x,y,0),add(y,x,0);
	}
	for (int i=1;i<=k;i++) if (!vis[i]) pre_dfs(i);
	for (int i=1;i<=k;i++)
	{
		from[i]=i;c[i]=2;
		if (col[i]==0) s0[i]++;
		else s1[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i].size()==2) merge(v[i][0],v[i][1]);
		else if (v[i].size()==1) change(v[i][0],(s[i]=='0')?col[v[i][0]]:(col[v[i][0]]^1));
		print(ans);
	}
	return 0;
}