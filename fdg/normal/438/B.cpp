#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

pair<int, int> arr[100005];
int val[100005];
vector<int> g[100005];

double ans = 0;

bool rem[100005];
int sz[100005];

int n;

int color[100005];
int S[100005];

int repr(int x) {
  return x == color[x] ? x : color[x] = repr(color[x]);
}

void join(int a, int b) {
  if (rand() & 1) swap(a, b);
  if (repr(a) != repr(b))
    S[repr(b)] += S[repr(a)];
  color[repr(a)] = repr(b);
}

void go(int v) {
  // cout << "V: " << v << endl;
  int cnt = 0;
  long long s = 0;
  set<int> f;
  for (int u : g[v]) {
    if (rem[u]) {
      int par = repr(u);
      if (!f.count(par)) {
        f.insert(par);
        sz[cnt++] = S[par];
        s += S[par];
        // cout << S[par] << endl;
      }
    }
  }
  double cur = 0;
  for (int i = 0; i < cnt; ++i) {
    cur += 1.0 * sz[i] * (s - sz[i]) / n;
  }
  cur += 2.0 * s / n;
  ans += val[v] * cur;
  // cout << v << "  " << ans << endl;
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
    val[i] = arr[i].first;
  }
  sort(arr, arr + n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) color[i] = i, S[i] = 1;
  for (int t = n - 1; t >= 0; --t) {
    int v = arr[t].second;
    go(v);
    rem[v] = true;
    for (int u : g[v])
      if (rem[u])
        join(u, v);
    // cout << ans / (n - 1) << endl;
  }
  printf("%.6lf\n", ans / (n - 1));
  return 0;
}