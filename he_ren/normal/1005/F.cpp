#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int n,m,d;
vector<int> g[MAXN], eid[MAXN];

vector<int> pre[MAXN];
string vis;
vector<string> ans;
void dfs_ans(int dep)
{
	if(dep > n)
	{
		ans.emplace_back(vis);
		if((int)ans.size() == d)
		{
			printf("%d\n",d);
			for(string &s: ans)
				cout << s << endl;
			exit(0);
		}
		return;
	}
	for(int x: pre[dep])
	{
		vis[x-1] = '1';
		dfs_ans(dep + 1);
		vis[x-1] = '0';
	}
}

int main(void)
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); eid[u].push_back(i);
		g[v].push_back(u); eid[v].push_back(i);
	}
	
	static int dep[MAXN];
	memset(dep, -1, sizeof(dep));
	queue<int> q;
	dep[1] = 0; q.push(1);
	while(q.size())
	{
		int u = q.front(); q.pop();
		for(int v: g[u])
			if(dep[v] == -1)
				dep[v] = dep[u] + 1, q.push(v);
	}
	
	for(int u=1; u<=n; ++u)
		for(int i=0; i<(int)g[u].size(); ++i)
			if(dep[g[u][i]] == dep[u] + 1)
				pre[g[u][i]].push_back(eid[u][i]);
	
	vis.resize(m, '0');
	dfs_ans(2);
	
	printf("%d\n",(int)ans.size());
	for(string &s: ans)
		cout << s << endl;
	return 0;
}