#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[3005], gr[3005];

const int inf = -1e+9;
pair<int, int> d[3005][3005];
int tmp[3005][3005];

void bfs(int n, int x) {
  for (int i = 0; i < n; ++i) {
    d[x][i] = {inf, i};
  }

  d[x][x].first = 0;
  vector<int> q(1, x);
  for (int i = 0; i < q.size(); ++i) {
    for (int u : g[q[i]]) {
      if (d[x][u].first == inf) {
        d[x][u].first = d[x][q[i]].first + 1;
        q.push_back(u);
      }
    }
  }

  for (int i = 0; i < n; ++i)
    tmp[x][i] = d[x][i].first;

  sort(d[x], d[x] + n);
  reverse(d[x], d[x] + n);
}


pair<int, int> dr[3005][3005];
int tmpr[3005][3005];

void bfs2(int n, int x) {
  for (int i = 0; i < n; ++i) {
    dr[x][i] = {inf, i};
  }

  dr[x][x].first = 0;
  vector<int> q(1, x);
  for (int i = 0; i < q.size(); ++i) {
    for (int u : gr[q[i]]) {
      if (dr[x][u].first == inf) {
        dr[x][u].first = dr[x][q[i]].first + 1;
        q.push_back(u);
      }
    }
  }

  for (int i = 0; i < n; ++i)
    tmpr[x][i] = dr[x][i].first;

  sort(dr[x], dr[x] + n);
  reverse(dr[x], dr[x] + n);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }


  for (int i = 0; i < n; ++i) {
    bfs(n, i);
    bfs2(n, i);
  }

  long long mx = -1, a, b, c, D;

  for (int a1 = 0; a1 < n; ++a1) {
    for (int a2 = 0; a2 < n; ++a2) {
      if (a1 == a2) continue;
      for (int i = 0; i < 6; ++i) {
        if (dr[a1][i].second == a1 || dr[a1][i].second == a2) continue;
        for (int j = 0; j < 6; ++j) {
          if (d[a2][j].second == a1 || d[a2][j].second == a2 || d[a2][j].second == dr[a1][i].second) continue;
          long long total = 0LL + dr[a1][i].first + tmp[a1][a2] + d[a2][j].first;
          if (total > mx) {
            mx = total;
            a = dr[a1][i].second + 1;
            b = a1 + 1;
            c = a2 + 1;
            D = d[a2][j].second + 1;
          }
        }
      }
    }
  }
  cout << a << " " << b << " " << c << " " << D << endl;

  return 0;
}