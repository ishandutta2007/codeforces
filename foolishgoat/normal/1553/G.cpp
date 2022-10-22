#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int _n) : p(_n, -1) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
  }
};

const int A = 1e6 + 6, P = 78505;
int fp[A];

vector<int> primes;
set<int> g[P];

void solve() {
  for (int i = 2; i < A; ++i) {
    if (fp[i]) continue;
    primes.push_back(i);
    for (int j = i; j < A; j += i) {
      if (fp[j] == 0)
        fp[j] = i;
    }
  }
  assert((int)primes.size() < P);
  int n;
  scanf("%d", &n);
  int q;
  scanf("%d", &q);
  vector<int> a(n);
  auto find_id = [&](int x) {
    return lower_bound(primes.begin(), primes.end(), x) - primes.begin();
  };
  Dsu dsu(primes.size());
  for (int i = 0; i < n; ++i) {
    int now;
    scanf("%d", &now);
    a[i] = now;
    int x = find_id(fp[now]);
    while (now > 1) {
      int p = fp[now];
      while ((now % p) == 0) {
        now /= p;
      }
      dsu.merge(x, find_id(p));
    }
  }
  for (int i = 0; i < n; ++i) {
    set<int> added;
    added.insert(dsu.find(find_id(fp[a[i]])));
    int now = a[i] + 1;
    while (now > 1) {
      int p = fp[now];
      while ((now % p) == 0) {
        now /= p;
      }
      int v = dsu.find(find_id(p));
      added.insert(v);
    }
    for (int u : added) {
      for (int v : added) {
        g[u].insert(v);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    a[i] = dsu.find(find_id(fp[a[i]]));
  }
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    if (a[u] == a[v]) {
      puts("0");
      continue;
    }
    if (g[a[u]].count(a[v])) {
      puts("1");
      continue;
    }
    puts("2");
  }
}

int main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}