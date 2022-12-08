#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1000000;

int main()
{
	vector<vector<int> > g;
	int n, col[sz], count[sz];
	queue<int> q;

	scanf("%d",&n);
	g.resize(n);
	rep(i,0,n)
		g[i].clear();
	rep(i,0,n-1)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i,0,n)
	{
		scanf("%d",&col[i]);
	}
	rep(i,0,n)
		count[i] = -1;
	rep(i,0,n)
		if(count[i]==-1)
		{
			int cnt = 0;
			q.push(i);
			while(!q.empty())
			{
				int v = q.front();
				q.pop();
				if(count[v] == -1 && col[v]==col[i])
				{
					count[v] = 0;
					cnt++;
					for(int k=0;k<g[v].size();k++)
						q.push(g[v][k]);
				}
			}
			q.push(i);
			while(!q.empty())
			{
				int v = q.front();
				q.pop();
				if(count[v] == 0 && col[v]==col[i])
				{
					count[v] = cnt;
					for(int k=0;k<g[v].size();k++)
						q.push(g[v][k]);
				}
			}
		}
	bool yes = false;
	int x = 0;
	rep(i,0,n)
	{
		int sum = count[i]-1;
		for(int j=0;j<g[i].size();j++)
			if(col[g[i][j]]!=col[i])
			   sum+=count[g[i][j]];
		if(sum==n-1)
		{
			yes = true;
			x = i;
		}
	}
	if(yes)
		printf("YES\n%d\n",x+1);
	else
		printf("NO\n");
}