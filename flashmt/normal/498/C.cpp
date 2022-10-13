#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

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

int main()
{
  ios::sync_with_stdio(0);
  int n, m, a[111], b[111], c[111];
  
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) 
  {
    cin >> b[i] >> c[i];
    if (b[i] % 2) swap(b[i], c[i]);
  }
  
  set <int> primes;
  for (int i = 1; i <= n; i++)
  {
    int x = a[i];
    for (int j = 2; j * j <= x; j++)
      if (x % j == 0)
      {
        while (x % j == 0) x /= j;
        primes.insert(j);
      }
    if (x > 1) primes.insert(x);
  }
  
  int ans = 0;
  for (auto p : primes)
  {
    int S = n + 1, T = n + 2;
    DinicFlow f(T, S, T);
        
    for (int i = 1; i <= n; i++)
    {
      int power = 0, x = a[i];
      while (x % p == 0)
      {
        power++;
        x /= p;
      } 
      
      if (!power) continue;
      
      if (i % 2) f.addEdge(i, T, power);
      else f.addEdge(S, i, power);
    }
    
    for (int i = 1; i <= m; i++)
    {
      int g = __gcd(a[b[i]], a[c[i]]);
      int power = 0;
      while (g % p == 0) 
      {
        power++;
        g /= p;
      }
      
      if (power) f.addEdge(b[i], c[i], power);
    }
    
    ans += f.maxFlow();
  }
  
  cout << ans << endl;
}