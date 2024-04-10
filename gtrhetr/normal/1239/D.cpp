#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000010];
stack<int> st;

int dfn[1000010],low[1000010],from[1000010],t,n,m,cl,cnt;
bool inq[1000010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dfs(int x)
{
	dfn[x]=low[x]=++cl;inq[x]=true;st.push(x);
	for (int t:v[x])
	{
		if (!dfn[t]) dfs(t),low[x]=min(low[x],low[t]);
		else if (inq[t]) low[x]=min(low[x],dfn[t]);
	}
	if (dfn[x]==low[x])
	{
		cnt++;
		while (233)
		{
			int hh=st.top();st.pop();
			from[hh]=cnt;inq[hh]=false;
			if (hh==x) break;
		}
	}
}

inline void work()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) v[i].clear();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		if (x!=y) v[x].push_back(y);
	}
	cl=cnt=0;
	for (int i=1;i<=n;i++) dfn[i]=low[i]=from[i]=inq[i]=0;
	while (!st.empty()) st.pop();
	for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i);
	if (cnt==1) { puts("No");return; }
	puts("Yes");
	int hh=0;
	for (int i=1;i<=n;i++) if (from[i]==1) hh++;
	printf("%d %d\n",hh,n-hh);
	for (int i=1;i<=n;i++) if (from[i]==1) printf("%d ",i);puts("");
	for (int i=1;i<=n;i++) if (from[i]>1) printf("%d ",i);puts("");
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}