#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
  vector<long long> sum;
  Fenwick(int _n) : sum(_n + 4, 0) {
  }
  
  long long get(int x) {
    long long r = 0;
    for (++x; x; x -= x&-x)
      r += sum[x];
    return r;
  }

  void upd(int x, long long v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }
};

void solve() {
 int n, m;
  cin >> n >> m;
  vector<int> a(n * m);
  for (int i = 0; i < n * m; ++i) {
    cin >> a[i];
  }
  int tot = n * m;
  vector<int> id(tot);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int l, int r) {
    if (a[l] == a[r]) {
      return l < r;
    } else {
      return a[l] < a[r];
    }
  });
  for (int i = 0; i < tot; ) {
    int j = i;
    int limit = (i / m + 1) * m;
    while (j < limit && a[id[i]] == a[id[j]]) ++j;
    reverse(id.begin() + i, id.begin() + j);
    i = j;
  }
  vector<Fenwick> fens(n, Fenwick(m));
  long long ans = 0;
  vector<int> pos(tot);
  for (int i = 0; i < tot; ++i) {
    pos[id[i]] = i;
  }
  for (int i = 0; i < tot; ++i) {
    int p = pos[i];
    int row = p / m, col = p - row * m;
    ans += fens[row].get(col);
    fens[row].upd(col, +1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}