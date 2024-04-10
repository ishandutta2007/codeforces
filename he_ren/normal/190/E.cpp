#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef unsigned int uint;
const int MAXN = 5e5 + 5;

vector<int> g[MAXN];

set<int> lft;
vector<int> ans[MAXN];
queue<int> q;

void bfs(int s)
{
	q.push(s);
	lft.erase(s);	
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		ans[s].push_back(u);
		
		set<int>::iterator it = lft.begin();
		uint i=0;
		while(it!=lft.end())
		{
			int v=*it;
			while(i<g[u].size() && g[u][i]<v) ++i;
			if(i<g[u].size() && g[u][i]==v)
			{
				++it;
				continue;
			}
			
			q.push(v);
			++it; lft.erase(v);
		}
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) sort(g[i].begin(),g[i].end());
	
	for(int i=1; i<=n; ++i) lft.insert(i);
	int cnt=0;
	while(!lft.empty())
		bfs(*lft.begin()), ++cnt;
	
	printf("%d\n",cnt);
	for(int i=1; i<=n; ++i) if(ans[i].size())
	{
		printf("%d ",ans[i].size());
		for(uint j=0; j<ans[i].size(); ++j) printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}