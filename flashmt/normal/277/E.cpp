#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const double oo = 1e17;

struct edge
{
	int x, y, cap, flow;
	double cost;
};

struct MinCostMaxFlow
{
	int n, S, T;
	vector < vector <int> > a;
	vector <int> prev, done;
	vector <double> dist, pot;
	vector <edge> e;
	
	MinCostMaxFlow() {}
	MinCostMaxFlow(int _n, int _S, int _T)
	{
		n = _n; S = _S; T = _T;
		a = vector < vector <int> >(n + 1);
		dist = vector <double>(n + 1);
		prev = vector <int>(n + 1);
		done = vector <int>(n + 1);
		pot = vector <double>(n + 1, 0);
	}
	
	void addEdge(int x, int y, int _cap, double _cost)
	{
		edge e1 = {x, y, _cap, 0, _cost};
		edge e2 = {y, x, 0, 0, -_cost};
		a[x].push_back(e.size()); e.push_back(e1);
		a[y].push_back(e.size()); e.push_back(e2);
	}
	
	pair <int,double> dijkstra()
	{
		int flow = 0;
		double cost = 0;
		for (int i = 1; i <= n; i++) done[i] = 0, dist[i] = oo;
		priority_queue < pair<double,int> > q;
		dist[S] = 0; prev[S] = -1;
		q.push(make_pair(0, S));
		while (!q.empty())
		{
			int x = q.top().second; q.pop();
			if (done[x]) continue;
			done[x] = 1;
			for (int i = 0; i < int(a[x].size()); i++)
			{
				int id = a[x][i], y = e[id].y;
				if (e[id].flow < e[id].cap)
				{
					double D = dist[x] + e[id].cost + pot[x] - pot[y];
					if (!done[y] && D < dist[y])
					{
						dist[y] = D; prev[y] = id;
						q.push(make_pair(-dist[y], y));
					}
				}
			}
		}
		
		for (int i = 1; i <= n; i++) pot[i] += dist[i];
		
		if (done[T])
		{
			flow = 1 << 29;
			for (int id = prev[T]; id >= 0; id = prev[e[id].x]) 
				flow = min(flow, e[id].cap - e[id].flow);
			for (int id = prev[T]; id >= 0; id = prev[e[id].x]) 
			{
				cost += e[id].cost * flow;
				e[id].flow += flow;
				e[id ^ 1].flow -= flow;
			}
		}
		
		return make_pair(flow, cost);
	}
	
	pair <int,double> minCostMaxFlow()
	{
		int totalFlow = 0;
		double totalCost = 0;
		while (1)
		{
			pair <int,double> u = dijkstra();
			if (!done[T]) break;
			totalFlow += u.first; totalCost += u.second;
		}
		return make_pair(totalFlow, totalCost);
	}
};

int main()
{
	int n, x[444], y[444];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	int S = n * 2 + 1, T = S + 1;
	MinCostMaxFlow F(T, S, T);
	
	for (int i = 1; i <= n; i++) F.addEdge(S, i, 2, 0);
	for (int i = 1; i <= n; i++) F.addEdge(i + n, T, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (y[i] > y[j]) 
				F.addEdge(i, j + n, 1, sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])));
				
	pair <int,double> ans = F.minCostMaxFlow();
	if (ans.first < n - 1) puts("-1");
	else printf("%.9lf\n", ans.second);
}