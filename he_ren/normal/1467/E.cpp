#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int tot[MAXN];

int a[MAXN];
map<int,int> *ss[MAXN];

inline void merge(map<int,int> *&ss,map<int,int> *&tt)
{
	if(ss -> size() > tt -> size()) swap(ss,tt);
	map<int,int> &s = *ss, &t = *tt;
	for(map<int,int>::iterator it = s.begin(); it != s.end(); ++it)
		t[it -> first] += it -> second;
}

int val[MAXN];
void dfs_s(int u,int fa)
{
	ss[u] = new map<int,int>;
	++(*ss[u])[a[u]];
	
	int sum = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_s(v,u);
		int cur = (*ss[v])[a[u]]; merge(ss[v], ss[u]);
		sum += cur;
		if(cur) ++val[1], --val[v];
	}
	if(sum != tot[a[u]]) ++val[u];
}

void dfs_val(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		val[v] += val[u];
		dfs_val(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	static int dsc[MAXN],dcnt=0;
	for(int i=1; i<=n; ++i) dsc[++dcnt] = a[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i) a[i] = lower_bound(dsc+1,dsc+dcnt+1,a[i]) - dsc;
	
	for(int i=1; i<=n; ++i) ++tot[a[i]];
	
	dfs_s(1,0);
	dfs_val(1,0);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(!val[i]) ++ans;
	printf("%d",ans);
	return 0;
}