#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int inf = 1000000001;
const int N = 200005;
int n, m, k, i, j, a, b, d, u, out;
bool sp [N];
int d1 [N];
int d2 [N];
vector <int> e [N];
vector < pair <int,int> > vec;
queue <int> Q;

void bfs (int s, int* dis)
	{
	for (i=1; i<=n; i++)
		dis[i] = inf;
	dis[s] = 0;
	Q.push(s);
	while (!Q.empty())
		{
		u = Q.front();
		Q.pop();
		for (int v : e[u])
			if (dis[v] > dis[u] + 1)
				{
				dis[v] = dis[u] + 1;
				Q.push(v);
				}
		}
	}

int main ()
	{
	scanf ("%d%d%d", &n, &m, &k);
	for (i=1; i<=k; i++)
		{
		scanf ("%d", &a);
		sp[a] = true;
		}

	for (i=1; i<=m; i++)
		{
		scanf ("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
		}

	bfs(1, d1);
	bfs(n, d2);
	
	for (i=1; i<=n; i++)
		if (sp[i] == true)
			vec.push_back({d1[i], d2[i]});

	d = d1[n];
	sort(vec.begin(), vec.end());
	
	out = 0;
	
	for (i=0; i+1<vec.size(); i++)
		{
		const pair <int,int>& p1 = vec[i];
		const pair <int,int>& p2 = vec[i+1];
		out = max(out, min(p1.f + p2.s + 1, p1.s + p2.f + 1));
		}

	out = min(out, d);
	printf ("%d\n", out);
	return 0;
	}