#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, i, j, out;
bool vis [N];
set <int> S;
queue <int> Q;
set < pair <int,int> > E;

vector <int> vec;

void bfs (int u)
	{
	vis[u] = true;
	S.erase(u);
	Q.push(u);
	while (!Q.empty())
		{
		u = Q.front();
		vis[u] = true;
		Q.pop();
		vec.clear();
		for (int v : S)
			if (E.find({u, v})==E.end())
				vec.push_back(v);
		for (int v : vec)
			{
			S.erase(v);
			Q.push(v);
			}
		}
	}

int main ()
	{
	scanf ("%d%d",&n,&m);
	while (m--)
		{
		int a, b;
		scanf ("%d%d",&a,&b);
		E.insert({a, b});
		E.insert({b, a});
		}
	
	for (i=1; i<=n; i++)
		S.insert(i);
	
	for (i=1; i<=n; i++)
		if (vis[i]==false)
			{
			bfs(i);
			out++;
			}
	
	out--;
	printf ("%d\n", out);
	return 0;
	}