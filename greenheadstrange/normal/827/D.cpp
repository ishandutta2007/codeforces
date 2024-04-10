#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 200005
using namespace std;
int c[maxn], ans[maxn];
vector<int> egid[maxn], egv[maxn];
int pre[maxn][20], dep[maxn], mx[maxn][20], prid[maxn];
void dfs(int a)
{
	for(int i = 0; i < egid[a].size(); i++)
	{
		int ed = egv[a][i];
		if(dep[ed]) continue;
		prid[ed] = egid[a][i];
		pre[ed][0] = a;
		dep[ed] = dep[a] + 1;
		for(int i = 1; i < 20; i++)
			pre[ed][i] = pre[pre[ed][i - 1]][i - 1];
		mx[ed][0] = c[prid[ed]];
		for(int i = 1; i < 20; i++)
			mx[ed][i] = max(mx[ed][i - 1], mx[pre[ed][i - 1]][i - 1]);
		dfs(ed);
	}
}
int fa[maxn];
struct eg
{
	int w, u, v, id;
	bool operator < (const eg &a)const
	{
		return w < a.w;
	}
}p[maxn];
bool flag[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int gmx(int a, int b)
{
	if(dep[a] < dep[b]) swap(a, b);
	int ans = 0;
	for(int i = 19; i >= 0; i--)
		if(dep[pre[a][i]] >= dep[b]) 
			ans = max(ans, mx[a][i]), a = pre[a][i];
	for(int i = 19; i >= 0; i--)
		if(pre[a][i] != pre[b][i])
			ans = max(ans, mx[a][i]), ans = max(ans, mx[b][i]), 
			a = pre[a][i], b = pre[b][i];
	if(a != b) ans = max(ans, mx[a][0]), ans = max(ans, mx[b][0]), a = pre[a][0], b = pre[b][0];
	return ans;
}
int st[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d%d", &u, &v, &c[i]);
		p[i].id = i, p[i].w = c[i], p[i].u = u, p[i].v = v;
	}
	sort(p + 1, p + m + 1);
	for(int i = 1; i <= m; i++)
	{
	//	cout<<"BF"<<i<<" "<<p[i].u<<" "<<p[i].v<<" "<<p[i].w<<endl;
		if(gfa(p[i].u) == gfa(p[i].v)) continue;
		flag[i] = 1;
		fa[gfa(p[i].u)] = gfa(p[i].v);
	//	cout<<"ADE"<<i<<" "<<p[i].u<<" "<<p[i].v<<endl;
		egid[p[i].u].push_back(p[i].id), egid[p[i].v].push_back(p[i].id);
		egv[p[i].u].push_back(p[i].v), egv[p[i].v].push_back(p[i].u);
	}	
	
	dep[1] = 1;
//	cout<<"!!!"<<endl;
	dfs(1);
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= m; i++)
	{
		if(flag[i]) continue;
		ans[p[i].id] = gmx(p[i].u, p[i].v) - 1;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		if(flag[i]) continue;
		int u = gfa(p[i].u), v = gfa(p[i].v);
		int top = 0;
		while(u != v)
		{
			if(dep[u] < dep[v]) swap(u, v);
			if(ans[prid[u]] == -1) ans[prid[u]] = p[i].w - 1; 
			st[top++] = u, u = gfa(pre[u][0]);
		}	
		for(int j = 0; j < top; j++)
			fa[gfa(st[j])] = u;
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;	
} 
/*
5 6
1 2 3
2 3 4
1 4 5
4 1 7
3 4 8
3 1 9

*/