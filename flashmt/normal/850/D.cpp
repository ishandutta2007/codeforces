#include <bits/stdc++.h>
using namespace std;
const int N = 65, SUM = 2000, oo = 27081993;

int m, a[33], f[77][77][2222], result[77][77];
pair <int, int> teams[2222];
vector <int> scores;

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

void trace(int i, int j, int sum)
{
  if (!i)
    return;
  int cnt = f[i][j][sum];
  trace(i - 1, j - cnt, sum - cnt * a[i - 1]);
  while (cnt--)
    scores.push_back(a[i - 1]);
}

int main()
{
  int x;
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  sort(a, a + m);

  f[0][0][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < N; j++)
      for (int sum = 0; sum <= SUM; sum++)
        if (f[i][j][sum])
        {
          int newSum = sum;
          for (int jj = j + 1; jj <= N; jj++)
          {
            newSum += a[i];
            if (newSum < jj * (jj - 1) / 2)
              break;
            f[i + 1][jj][newSum] = jj - j;
          }
        }

  for (int n = 1; n <= N; n++)
    if (f[m][n][n * (n - 1) / 2])
    {
      int matches = n * (n - 1) / 2;
      scores.clear();
      trace(m, n, matches);
      int S = matches + n + 1, T = S + 1, matchId = 1;
      DinicFlow flow(T, S, T);
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
          teams[matchId] = {i, j};
          flow.addEdge(S, matchId, 1);
          flow.addEdge(matchId, matches + i + 1, 1);
          flow.addEdge(matchId, matches + j + 1, 1);
          matchId++;
        }
      for (int i = 0; i < n; i++)
        flow.addEdge(matches + i + 1, T, scores[i]);
      int maxFlow = flow.maxFlow();
      if (maxFlow != matches)
        continue;
      for (auto e : flow.e)
        if (e.x <= matches && e.y > matches && e.y <= matches + n && e.flow == 1)
        {
          int win = e.y - matches - 1, lose;
          if (win == teams[e.x].first) lose = teams[e.x].second;
          else lose = teams[e.x].first;
          result[win][lose] = 1;
        }

      cout << n << endl;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
          cout << result[i][j];
        cout << endl;
      }
      return 0;
    }

  cout << "=(" << endl;
}