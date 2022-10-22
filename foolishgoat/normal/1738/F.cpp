#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  vector<long long> sum;
  Dsu(int n) : p(n, -1), sum(n) {}
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  long long getsum(int x) {
    return sum[find(x)];
  }
  int getcnt(int x) {
    return -p[find(x)];
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    sum[v] += sum[u];
    p[u] = v;
    return true;
  }
};


int ask(int x) {
  cout << "? " << x+1 << endl;
  int ret;
  cin >> ret;
  return --ret;
}

void solve() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    return d[l] > d[r];
  });
  Dsu dsu(n);
  for (int i = 0; i < n; ++i) {
    dsu.sum[i] = d[i];
  }
  vector<bool> processed(n, false);
  for (int v : id) {
    if (processed[v]) continue;
    processed[v] = true;
    for (int i = 0; i < d[v]; ++i) {
      int u = ask(v);
      if (processed[u]) {
        dsu.merge(u, v);
        break;
      }
      processed[u] = true;
      dsu.merge(u, v);
    }
  }
  cout << "!";
  for (int i = 0; i < n; ++i) {
    cout << " " << dsu.find(i) + 1;
  }
  cout << endl;
}

int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}