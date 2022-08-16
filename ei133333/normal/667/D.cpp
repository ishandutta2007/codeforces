#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;

vector< int > graph[3000], rgraph[3000];
int g[3000][3000];
set< Pi > qq[2][3000];
int main()
{
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    rgraph[v].push_back(u);
  }

  for(int l = 0; l < 2; l++, swap(graph, rgraph)) {
    memset(g, -1, sizeof(g));
    for(int i = 0; i < N; i++) {
      queue< int > que;
      que.push(i);
      g[i][i] = 0;
      while(!que.empty()) {
        int p = que.front(); que.pop();
        for(int to : graph[p]) {
          if(g[i][to] == -1) {
            que.push(to);
            g[i][to] = g[i][p] + 1;
            qq[l][i].insert({g[i][to], to});
            while(qq[l][i].size() > 3) qq[l][i].erase(qq[l][i].begin());
          }
        }
      }
    }
  }

  int ret = -114;
  int aa, bb, cc, dd;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j || g[j][i] == -1) continue;
      for(const Pi& a : qq[1][i]) {
        if(i == a.second || j == a.second) continue;
        for(const Pi& b : qq[0][j]) {
          if(i == b.second || j == b.second || a.second == b.second) continue;
          if(ret < g[j][i] + a.first + b.first) {
            ret = g[j][i] + a.first + b.first;
            aa = a.second, bb = i, cc = j, dd = b.second;
          }
        }
      }
    }
  }
  cout << aa + 1 << " " << bb + 1 << " " << cc + 1 << " " << dd + 1 << endl;
}