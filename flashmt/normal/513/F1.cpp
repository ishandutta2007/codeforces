#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const long long LIM = 1LL << 50;

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


struct Scayger
{
  int x, y, t;
  
  Scayger(int x = 0, int y = 0, int t = 0)
  {
    this -> x = x;
    this -> y = y;
    this -> t = t;
  }
};

int m, n, M, F, dist[25][25][25][25];
Scayger males[555], females[555], boss;
string a[25];

void bfs(int sx, int sy)
{
  queue < pair<int,int> > q;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      dist[sx][sy][i][j] = -1;
  dist[sx][sy][sx][sy] = 0;
  q.push(make_pair(sx, sy));
  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
      if (dist[sx][sy][xx][yy] >= 0) continue;
      if (a[xx][yy] != '.') continue;
      dist[sx][sy][xx][yy] = dist[sx][sy][x][y] + 1;
      q.push(make_pair(xx, yy));
    }
  }
}

int ok(long long maxTime)
{
  int S = M + F + m * n * 2 + 1, T = S + 1;
  DinicFlow f(T, S, T);
  for (int i = 0; i < M; i++) f.addEdge(S, i + 1, 1);
  for (int i = 0; i < F; i++) f.addEdge(M + i + 1, T, 1);
  for (int x = 0; x < m; x++)
    for (int y = 0; y < n; y++)
      if (a[x][y] == '.')
        f.addEdge(M + F + x * n + y + 1, M + F + m * n + x * n + y + 1, 1);
  
  for (int i = 0; i < M; i++)
    for (int x = 0; x < m; x++)
      for (int y = 0; y < n; y++)
      {
        if (a[x][y] == '#') continue;
        int curDist = dist[x][y][males[i].x][males[i].y];
        if (curDist < 0) continue;
        if (1LL * curDist * males[i].t > maxTime) continue;
        f.addEdge(i + 1, M + F + x * n + y + 1, 1);
      }
      
  for (int i = 0; i < F; i++)
    for (int x = 0; x < m; x++)
      for (int y = 0; y < n; y++)
      {
        if (a[x][y] == '#') continue;
        int curDist = dist[x][y][females[i].x][females[i].y];
        if (curDist < 0) continue;
        if (1LL * curDist * females[i].t > maxTime) continue;
        f.addEdge(M + F + m * n + x * n + y + 1, M + i + 1, 1);
      }
  
  return f.maxFlow() == M;
}

int main()
{
  ios::sync_with_stdio(0);
  //freopen("f.in", "r", stdin);
  int x, y, t;
  cin >> m >> n >> M >> F;
  for (int i = 0; i < m; i++) cin >> a[i];
  cin >> x >> y >> t;
  boss = Scayger(x - 1, y - 1, t);
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y >> t;
    males[i] = Scayger(x - 1, y - 1, t);
  }
  for (int i = 0; i < F; i++)
  {
    cin >> x >> y >> t;
    females[i] = Scayger(x - 1, y - 1, t);
  }
  
  if (abs(M - F) != 1)
  {
    cout << -1 << endl;
    return 0;
  }
  
  if (M > F) females[F++] = boss;
  else males[M++] = boss;
  
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      bfs(i, j);
      
  long long low = 0, high = LIM, ans = LIM + 1;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    if (ok(mid)) 
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  
  if (ans > LIM) ans = -1;
  cout << ans << endl;
}