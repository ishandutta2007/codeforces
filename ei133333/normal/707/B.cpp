#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct edge
{
  int to, cost;
};

int main()
{
  int N, M, K;
  vector< edge > graph[100000];
  bool f[100000] = {};

  scanf("%d %d %d", &N, &M, &K);

  while(M--) {
    int u, v, l;
    scanf("%d %d %d", &u, &v, &l);
    --u, --v;
    graph[u].push_back((edge){v, l});
    graph[v].push_back((edge){u, l});
  }
  while(K--) {
    int a;
    scanf("%d", &a);
    f[--a] = true;
  }

  int ret = INF;
  for(int i = 0; i < N; i++) {
    if(!f[i]) {
      for(auto& e : graph[i]) {
        if(f[e.to]) ret = min(ret, e.cost);
      }
    }
  }

  if(ret == INF) puts("-1");
  else printf("%d\n", ret);
}