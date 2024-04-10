#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, v[222], used[222];
vector <int> table[222], a[222];

struct edge
{
	int x, y, cap, flow;
};

struct DinicFlow
{
	int n, S, T;
	vector < vector <int> > a;
	vector <int> cur, d;
	vector <edge> e;
	
	DinicFlow() {}
	DinicFlow(int n, int S, int T)
	{
		this -> n = n;
		this -> S = S;
		this -> T = T;
		a = vector < vector <int> >(n + 1);
		cur = vector <int>(n + 1);
		d = vector <int>(n + 1);
	}
	
	void addEdge(int x, int y, int cap)
	{
		edge e1 = {x, y, cap, 0};
		edge e2 = {y, x, 0, 0};
		a[x].push_back(e.size()); e.push_back(e1);
		a[y].push_back(e.size()); e.push_back(e2);
	}
	
	int bfs()
	{
		queue <int> q;
		for (int i = 1; i <= n; i++) d[i] = -1;
		q.push(S); d[S] = 0;
		while (!q.empty() && d[T] < 0)
		{
			int x = q.front(); q.pop();
			for (int i = 0; i < int(a[x].size()); i++)
			{
				int id = a[x][i], y = e[id].y;
				if (d[y] < 0 && e[id].flow < e[id].cap)
					q.push(y), d[y] = d[x] + 1;
			}
		}
		return d[T] >= 0;
	}
	
	int dfs(int x, int val)
	{
		if (!val) return 0;
		if (x == T) return val;
		for (; cur[x] < int(a[x].size()); cur[x]++)
		{
			int id = a[x][cur[x]], y = e[id].y;
			if (d[y] != d[x] + 1) continue;
			int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
			if (pushed)
			{
				e[id].flow += pushed;
				e[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
	
	int maxFlow()
	{
		int res = 0;
		while (bfs())
		{
			for (int i = 1; i <= n; i++) cur[i] = 0;
			while (1)
			{
				int val = dfs(S, oo);
				if (!val) break;
				res += val;
			}
		}
		return res;
	}	
};

int isPrime(int x)
{
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  
  int S = n + 1, T = n + 2;
  DinicFlow f(T, S, T);
  
  for (int i = 1; i <= n; i++)
    if (v[i] % 2)
    {
      f.addEdge(S, i, 2);
      for (int j = 1; j <= n; j++)
        if (v[j] % 2 == 0 && isPrime(v[i] + v[j]))
          f.addEdge(i, j, 1);
    }
    else f.addEdge(i, T, 2);
        
  if (f.maxFlow() != n)
  {
    cout << "Impossible\n";
    return 0;
  }

  for (auto e : f.e)
    if (e.flow == 1)
    {
      a[e.x].push_back(e.y);
      a[e.y].push_back(e.x);
    }
      
  int numTable = 0;
  for (int i = 1; i <= n; i++)
    if (!used[i])
    {
      numTable++;
      int x = i;
      while (1)
      {
        used[x] = 1;
        table[numTable].push_back(x);
        int found = 0;
        for (auto y : a[x])
          if (!used[y]) 
          {
            x = y;
            found = 1;
            break;
          }
        if (!found) break;
      }
    }
    
  cout << numTable << endl;
  for (int i = 1; i <= numTable; i++)
  {
    cout << table[i].size() << ' ';
    for (auto j : table[i]) cout << j << ' ';
    cout << endl;
  }
}