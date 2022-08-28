#include <cstdio>

#include <functional>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> ed(n);
  long long ans = 0;
  vector<int> in(n), out(n);
  function<void(int, int)> insert = [&](int a, int b) {
    ans += out[b] + in[a];
    ++in[b];
    ++out[a];
  };
  function<void(int, int)> remove = [&](int a, int b) {
    --out[a];
    --in[b];
    ans -= out[b] + in[a];
  };
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b)
      swap(a, b);
    --a; --b;
    insert(a, b);
    ed[a].push_back(b);
  }
  printf("%lld\n", ans);
  int q;
  scanf("%d", &q);
  while (q--) {
    int u;
    scanf("%d", &u);
    --u;
    for (int v : ed[u])
      remove(u, v);
    for (int v : ed[u]) {
      insert(v, u);
      ed[v].push_back(u);
    }
    ed[u].clear();
    printf("%lld\n", ans);
  }
  return 0;
}