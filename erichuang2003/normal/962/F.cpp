#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 100005;
 
struct Edge
{
    int from;
	int to;
    int next;
}edge[MAXN << 1];

int n,m,id,df;
int dfn[MAXN];
int low[MAXN];
int first[MAXN];

stack<int> S;
set<int> bcc;
vector<int> cur,ans;

void addE(int u,int v)
{
	edge[++id] = (Edge){u,v,first[u]};
	first[u] = id;
}
 
void dfs(int u,int fa)
{
    dfn[u] = low[u] = ++df;
    for (int i = first[u];i;i = edge[i].next)
	{
	    int v = edge[i].to;
	    if (v == fa)
			continue;
	    if (!dfn[v])
		{
		    S.push(i);
		    dfs(v,u);
		    low[u] = min(low[u],low[v]);
		    if (low[v] >= dfn[u])
			{
			    int cnt = 0,tmp;
			    bcc.clear();
			    cur.clear();
			    do
				{
				    tmp = S.top();
				    S.pop();
				    cur.push_back(tmp);
				    bcc.insert(edge[tmp].from);
				    bcc.insert(edge[tmp].to);
				}while (!S.empty() && edge[tmp].from != u || edge[tmp].to != v);
			    if (cur.size() == bcc.size())
				{
					for (int j = 0;j < cur.size();j++)
						ans.push_back(cur[j]);
				}
			}
		}
	    else if (dfn[v] < dfn[u])
		{
		    S.push(i);
		    low[u] = min(low[u],dfn[v]);
		}
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
    for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
	    addE(u,v);
	    addE(v,u);
	}
    for (int i = 1;i <= n;i++)
	    if (!dfn[i])
			dfs(i,0);
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << (ans[i] + 1) / 2 << ' ';
	cout << endl;
    return 0;
}