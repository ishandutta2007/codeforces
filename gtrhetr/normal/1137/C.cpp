#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct node { int t,next; }a[100010];

vector<int> v[100010];
stack<int> st;
queue<pii> q;

int dfn[100010],low[100010],from[100010],cl,cnt;
int f[100010][60],head[100010],n,m,d,tot;
bool bo[100010][60],inq[100010];
bool vis[100010][60];
bool can[100010][60];
char s[60];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x)
{
	dfn[x]=low[x]=++cl;st.push(x);inq[x]=true;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (!dfn[t]) dfs(t),low[x]=min(low[x],low[t]);
		else if (inq[t]) low[x]=min(low[x],dfn[t]);
	}
	if (dfn[x]==low[x])
	{
		cnt++;
		while (233)
		{
			int hh=st.top();st.pop();
			from[hh]=cnt;v[cnt].push_back(hh);
			inq[hh]=false;
			if (hh==x) break;
		}
	}
}

inline int gao(int x,int y)
{
	if (vis[x][y]) return f[x][y];
	vis[x][y]=true;
	int hh=from[x];
	for (int i=0;i<v[hh].size();i++) for (int j=0;j<d;j++) can[v[hh][i]][j]=false;
	while (!q.empty()) q.pop();
	can[x][y]=true;q.push(pii(x,y));
	while (!q.empty())
	{
		pii now=q.front();q.pop();
		int x=now.first;
		for (int i=head[x];i;i=a[i].next)
		{
			int t=a[i].t;
			if (from[t]!=hh) continue;
			int t1=(now.second+1)%d;
			if (can[t][t1]) continue;
			can[t][t1]=true;q.push(pii(t,t1));
		}
	}
	int res=0;
	for (int i=0;i<v[hh].size();i++)
	{
		bool flag=false;
		for (int j=0;j<d;j++) if (can[v[hh][i]][j]&&bo[v[hh][i]][j]) flag=true;
		res+=flag;
	}
	int res1=0;
	for (int i=0;i<v[hh].size();i++)
	{
		int x=v[hh][i];
		for (int j=head[x];j;j=a[j].next)
		{
			int t=a[j].t;
			if (from[t]==from[x]) continue;
			for (int k=0;k<d;k++) if (can[x][k]) res1=max(res1,gao(t,(k+1)%d));
		}
	}
	for (int i=0;i<v[hh].size();i++) for (int j=0;j<d;j++) if (can[v[hh][i]][j]) vis[v[hh][i]][j]=true,f[v[hh][i]][j]=res+res1;
	return f[x][y]=res+res1;
}

int main()
{
	n=rd();m=rd();d=rd();tot=0;
	for (int i=1;i<=m;i++) { int x=rd(),y=rd();add(x,y); }
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<d;j++) bo[i][j]=(s[j]=='1');
	}
	cl=cnt=0;
	dfs(1);
	printf("%d\n",gao(1,0));
	return 0;
}