#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, m, i, j, u, s, t;
int dis [N];
queue <int> Q;
vector <int> p;
vector <int> e [N];
vector <int> g [N];

int main ()
	{
	int a, b;
	scanf ("%d%d", &n, &m);
	while (m--)
		{
		scanf ("%d%d", &a, &b);
		g[a].push_back(b);
		e[b].push_back(a);
		}
	
	scanf ("%d", &m);
	p.resize(m);
	for (int& a : p)
		scanf ("%d", &a);
	
	for (i=1; i<=n; i++)
		dis[i] = N;

	s = p[0];
	t = p.back();
	dis[t] = 0;
	Q.push(t);

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

	int out1 = 0;
	int out2 = 0;
	
//	for (i=0; i<p.size(); i++)
//		printf ("> %d: %d\n", p[i], dis[p[i]]);
	
	for (i=0; i+1 < p.size(); i++)
		if (dis[p[i+1]] >= dis[p[i]])
			out1++;

	for (i=0; i+1 < p.size(); i++)
		{
		a = p[i];
		b = p[i+1];
		if (dis[b] >= dis[a])
			{
			out2++;
			continue;
			}
		for (int v : g[a])
			if (v != b && dis[v] == dis[b])
				{
				out2++;
				break;
				}
		}
	
	printf ("%d %d\n", out1, out2);
	return 0;
	}