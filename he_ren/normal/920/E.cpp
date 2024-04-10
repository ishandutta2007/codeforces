#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef unsigned int uint;
const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
set<int> lft;

int size[MAXN];
queue<int> q;
void bfs(int s)
{
	lft.erase(s);
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		++size[s];
		
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
	while(!lft.empty())
		bfs(*lft.begin());
	
	sort(size+1,size+n+1);
	int now=1;
	while(!size[now]) ++now;
	printf("%d\n",n-now+1);
	for(; now<=n; ++now) printf("%d ",size[now]);
	return 0;
}