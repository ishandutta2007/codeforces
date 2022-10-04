#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 5e5 + 7;
ll t[4 * N];
ll mod[4 * N];
const ll Inf = 1e18;

void update(int v, ll x) {
  t[v] += x;
  mod[v] += x;
}

void push(int v) {
  if (mod[v]) {
    update(2 * v + 1, mod[v]);
    update(2 * v + 2, mod[v]);
    mod[v] = 0;
  }
}

void build(int l, int r, int v) {
  if (l == r) {
    t[v] = Inf;
  } else {
    int m = (l + r) >> 1;
    build(l, m, 2 * v + 1);
    build(m + 1, r, 2 * v + 2);
  }
}

void modify(int ql, int qr, ll val, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    update(v, val);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify(ql, qr, val, l, m, 2 * v + 1);
    modify(ql, qr, val, m + 1, r, 2 * v + 2);
  }
}

ll get(int id, int l, int r, int v) {
  if (l == r) return t[v];
  push(v);
  int m = (l + r) >> 1;
  if (id <= m) return get(id, l, m, 2 * v + 1);
  else return get(id, m + 1, r, 2 * v + 2);
}

void set_min(int id, ll val, int l, int r, int v) {
  if (l == r) {
    t[v] = min(t[v], val);
  } else {
    push(v);
    int m = (l + r) >> 1;
    if (id <= m) set_min(id, val, l, m, 2 * v + 1);
    else set_min(id, val, m + 1, r, 2 * v + 2);
  } 
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector <int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  int m;
  cin >> m;
  vector <int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  {
    int uk = 0;
    for (int i = 0; i < n; ++i) {
      if (uk < m && a[i] == b[uk]) ++uk;
    }
    if (uk != m) {
      cout << "NO\n";
      return 0;
    } else {
      cout << "YES\n";
    }
  } 
  vector <int> pos(n + 1, -1);
  for (int i = 0; i < m; ++i) { 
    pos[b[i]] = i;
  }
  build(0, n, 0);
  set_min(0, 0, 0, n, 0);

  for (int i = 0; i < n; ++i) {
    if (pos[a[i]] != -1) {
      ll val = get((pos[a[i]] == 0 ? 0 : b[pos[a[i]] - 1]), 0, n, 0);
      modify(0, a[i] - 1, p[i], 0, n, 0);
      if (p[i] < 0) {
        modify(a[i], n, p[i], 0, n, 0);
      }
      set_min(a[i], val, 0, n, 0);
    } else {
      modify(0, a[i] - 1, p[i], 0, n, 0);
      if (p[i] < 0) {
        modify(a[i], n, p[i], 0, n, 0);
      }
    }
  }
  cout << get(b[m - 1], 0, n, 0) << '\n';
}