//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 200500;

using namespace std;

struct edge
{
	int a, b, cap, flow;
};

int n, s, t, d[N], ptr[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int a, int b, int cap)
{
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back(e.size());
	e.push_back(e1);
	g[b].push_back(e.size());
	e.push_back(e2);
}

bool bfs()
{
	for (int i = 0; i < n; i++)
	{
		d[i] = -1;
	}
	d[s] = 0;
	queue<int> qu;
	qu.push(s);
	while (qu.size())
	{
		int v = qu.front();
		qu.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int id = g[v][i];
			int to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap)
			{
				d[to] = d[v] + 1;
				qu.push(to);
			}
		}
	}
	return d[t] != -1;
}

int dfs(int v, int flow)
{
	if (v == t || flow == 0)
		return flow;
	for (; ptr[v] < g[v].size(); ptr[v]++)
	{
		int id = g[v][ptr[v]];
		int to = e[id].b;
		if (d[to] != d[v] + 1)
			continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if (pushed)
		{
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic()
{
	int flow = 0;
	while (true)
	{
		if (!bfs())
			break;
		for (int i = 0; i < n; i++)
		{
			ptr[i] = 0;
		}
		while (true)
		{
			int pushed = dfs(s, 10000);
			if (!pushed)
				break;
			flow += pushed;
		}
	}
	return flow;
}

int m, x, k;
vector<pair<pair<int, int>, int> > E;

void construct_graph(double val)
{
	e.clear();
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < E.size(); i++)
	{
		//cout << E[i].second << " " << val << endl;
		long double d_here = E[i].second*1.0 / val+eps;
		if (d_here>1e9)
			d_here = 1e6;
		int here = d_here;
		add_edge(E[i].first.first, E[i].first.second, here);
	}
}

void update_graph(double val)
{
	for (int i = 0; i < E.size(); i++)
	{
		double d_here = E[i].second*1.0 / val+eps;
		if (d_here>1e9)
			d_here = 1e6;
		int here = d_here;
		int rem = here - e[i * 2].cap;
		e[i * 2].cap += rem;
		//cout << rem << " " << val << " " << e[i * 2].cap << " "<<e[i*2].flow<<endl;
	}
}

double get_next(double val)
{
	double res = 0;
	for (int i = 0; i < E.size(); i++)
	{
		double d_here = E[i].second*1.0 / val+eps;
		if (d_here>1e9)
			d_here = 1e6;
		int here = d_here;
		double thold = (E[i].second*1.0 / (here + 1));
		res = max(res, thold);
	}
	return res;
}

vector<pair<int, double> > G[N];
double D[N];
//set<pair<double, int> > S;
//set<pair<double, int> > ::iterator it;

priority_queue<pair<double, int> > S,emp;

double smart_next(double val)
{
	for (int i = 0; i < n; i++)
	{
		G[i].clear();
		D[i] = 0;
	}

	for (int i = 0; i < E.size(); i++)
	{
		//cout << e[i*2].a<<" "<<e[i*2].b<<" "<<e[i * 2].cap << " " << e[i * 2].flow << endl;
		double T = E[i].second*1.0 / (e[i * 2].cap + 1);
		if (e[i * 2].flow < e[i * 2].cap)
			G[E[i].first.first].push_back(make_pair(E[i].first.second, val));
		else
			G[E[i].first.first].push_back(make_pair(E[i].first.second, T));
		if (e[i * 2 + 1].flow < e[i * 2+1].cap)
		{
			G[E[i].first.second].push_back(make_pair(E[i].first.first, val));
		}
		else
			G[E[i].first.second].push_back(make_pair(E[i].first.first, T));
	}

	S = emp;

	D[0] = val;
	for (int i = 0; i < n; i++)
		S.push(make_pair(D[i], i));

	while (S.size())
	{
		pair<double, int> p = S.top();
		S.pop();
		if (D[p.second]>p.first + eps)
			continue;
		int cur = p.second;
		if (cur == n - 1)
			break;
		//cout << cur << " " << p.first <<" "<<S.size()<< endl;
		for (int i = 0; i < G[cur].size(); i++)
		{
			int to = G[cur][i].first;
			double cost = min(G[cur][i].second, D[cur]);
			if (D[to]<cost-eps)
			{
				//S.erase(make_pair(D[to], to));
				D[to] = cost;
				S.push(make_pair(D[to], to));
			}
		}
	}
	return D[n - 1];
}

double solve_naive(int need)
{
	long double l, r;
	l = 1e-6;
	r = 1e6;
	for (int iter = 1; iter <= 70; iter++)
	{
		double mid = l + r;
		mid /= 2;
		construct_graph(mid);
		int here = dinic();
		if (here >= need)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> x;
	k = 1;

	s = 0;
	t = n - 1;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		E.push_back(make_pair(make_pair(a, b), c));
	}

	cout.precision(7);

	long double cur_val = solve_naive(x);

	construct_graph(cur_val - eps);
	int cur_flow = dinic();

	for (int i = x; i < x + k; i++)
	{
		//cout << i << "@" << cur_flow << endl;
		while (cur_flow < i)
		{
			double next_cand = smart_next(cur_val);
			update_graph(next_cand);
			//cout << next_cand << endl;
			//cin.get();
			bfs();
			for (int j = 0; j < n; j++)
				ptr[j] = 0;
			while (true)
			{
				int pushed = dfs(s, 1000000);
				if (pushed == 0)
					break;
				cur_flow += pushed;
			}
//			cout << pushed << endl;
//			cin.get();
			cur_val = next_cand;
		}
		cout << fixed << cur_val*i << "\n";
	}
	/*
	for (int i = x; i < x + k; i++)
	{
		cout << fixed << solve_naive(i)*i << endl;
	}*/

	cin.get(); cin.get();
	return 0;
}