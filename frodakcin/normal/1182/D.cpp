#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MN = 1e5 + 100;
int N;
vector<int> a[MN];
int p[MN], d[MN];
int get_far(int n)
{
	queue<int> q;
	q.push(n);
	p[n] = 0, d[n] = 0;
	int x;
	for(;!q.empty();q.pop())
	{
		x = q.front();
		for(int y : a[x])
			if(y!=p[x])
				p[y] = x, d[y] = d[x]+1, q.push(y);
	}
	return x;
}
int C, D;
int get_center(void)
{
	int v = get_far(get_far(1));
	D = d[v];
	for(int i = 0;i < D>>1;i++)
		v = p[v];
	return C = v;
}

int v[MN];
bool ex;
vector<int> paths;
int dfs(int n)
{
	int cc = 0, r;
	for(int x : a[n])
		if(x != p[n])
			p[x] = n, d[x] = d[n]+1, r = dfs(x), cc++;
	if(!cc) return n;
	else if(cc == 1) return r;
	else return -1;
}
void dfs2(int n)
{
	if(~v[d[n]] && v[d[n]] != a[n].size()) ex = 0;
	v[d[n]] = a[n].size();
	for(int x : a[n])
		if(p[n] != x)
			dfs2(x);
}
vector<int> ans;
int plc[MN], diff;
bool check_center(void)
{
	ex = 1;
	for(int i = 0;i <= N;i++)
		v[i] = -1;
	for(int x : a[C])
	{
		d[x] = 1, p[x] = C;
		int res = dfs(x);
		if(!~res) dfs2(x);
		else paths.push_back(res);
	}
	for(int x : paths)
		diff += !plc[d[x]]++;
	if(ex && paths.empty() || paths.size() == a[C].size() && diff == 1)
		ans.push_back(C);
	if(diff == 1)
	{
		if(paths.size() == 1 && ex || paths.size() == a[C].size())
			for(int x : paths)
				ans.push_back(x);
	}
	else if(diff == 2)
		if(paths.size() == a[C].size())
			for(int x : paths)
				if(plc[d[x]] == 1)
					ans.push_back(x);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, u, v;i < N-1;i++)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	get_center();
	check_center();
	sort(ans.begin(), ans.end());
	if(ans.empty()) printf("-1\n");
	else printf("%d\n", ans.back());
	return 0;
}