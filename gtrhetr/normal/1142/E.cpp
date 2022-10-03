#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[1000010];

unordered_map<int,bool> mp[1000010];
vector<int> v[1000010],have[1000010],h;
stack<int> st;

int head[1000010],dfn[1000010],low[1000010],from[1000010],in[1000010],n,m,cl,cnt,tot;
bool inq[1000010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return rd();
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x)
{
	dfn[x]=low[x]=++cl;
	st.push(x);inq[x]=true;
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
			from[hh]=cnt;inq[hh]=false;
			have[cnt].push_back(hh);
			if (hh==x) break;
		}
	}
}

int main()
{
	n=rd();m=rd();tot=0;
	for (int i=1;i<=m;i++) { int x=rd(),y=rd();add(x,y); }
	for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i);
	for (int i=1;i<=n;i++) for (int j=head[i];j;j=a[j].next) if (from[i]!=from[a[j].t]&&!mp[from[i]][from[a[j].t]])
	{
		in[from[a[j].t]]++;
		v[from[i]].push_back(from[a[j].t]);
		mp[from[i]][from[a[j].t]]=true;
	}
	for (int i=1;i<=cnt;i++) if (!in[i]) h.push_back(i);
	while (h.size()>1)
	{
		int x=have[h[0]].back(),y=have[h[1]].back();
		if (!ask(x,y)) swap(h[0],h[1]);
		have[h[1]].pop_back();
		if (have[h[1]].empty())
		{
			swap(h[1],h.back());
			int hh=h.back();h.pop_back();
			for (int t:v[hh]) if (!(--in[t])) h.push_back(t);
		}
	}
	printf("! %d\n",have[h[0]].back());
	fflush(stdout);
	return 0;
}