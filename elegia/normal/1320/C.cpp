#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

struct Node {
  int v, lazy;
  Node *ls, *rs;

  int get() const { return v + lazy; }

  void upd() {
    v = max(ls->get(), rs->get());
  }
};

const int N = 1000010;

int u[N];

Node* build(int l, int r) {
  static Node pool[N * 2], *top = pool;
  Node* p = top++;
  if (l == r) {
    p->v = u[l];
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->upd();
  return p;
}

void change(Node* o, int oL, int oR, int l, int x) {
  if (oL == l) {
    o->lazy += x;
    return;
  }
  int mid = (oL + oR) >> 1;
  if (l <= mid) {
    change(o->ls, oL, mid, l, x);
    o->rs->lazy += x;
  } else
    change(o->rs, mid + 1, oR, l, x);
  o->upd();
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, p;
  cin >> n >> m >> p;

  vector<int> a(n), ca(n), b(m), cb(m), x(p), y(p), z(p);
  for (int i = 0; i < n; ++i) cin >> a[i] >> ca[i];
  for (int i = 0; i < m; ++i) cin >> b[i] >> cb[i];
  for (int i = 0; i < p; ++i) cin >> x[i] >> y[i] >> z[i];
  int ans = numeric_limits<int>::min();
  fill(u + 1, u + 1000002, numeric_limits<int>::min());
  for (int i = 0; i < m; ++i)
    u[b[i]] = max(u[b[i]], -cb[i]);
  Node* segT = build(1, 1000001);
  vector<pair<int, int>> modify;
  for (int i = 0; i < n; ++i) modify.emplace_back(a[i], -i - 1);
  for (int i = 0; i < p; ++i) modify.emplace_back(x[i], i + 1);
  sort(modify.begin(), modify.end());
  for (const auto& pr : modify)
    if (pr.second < 0) {
      int i = -pr.second - 1;
      ans = max(ans, -ca[i] + segT->get());
    } else {
      int i = pr.second - 1;
      change(segT, 1, 1000001, y[i] + 1, z[i]);
    }
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}