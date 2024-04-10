#include <cmath>
#include <cstring>

#include <algorithm>
#include <iomanip>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 1000000007;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}

int x, y;
// 0 < 1/(x+y) < 1/x

// 0, 0 + 1/(x+y), 0 + 1/x
// 1/(x+y) + 0, 1/(x+y) + 1/(x+y)
// 1/x + 0
struct Dat {
  double m[3][3];
  Dat() { fill(m[0], m[0] + 9, -1e18); }
  Dat(double a) {
    fill(m[0], m[0] + 3, 0);
    m[1][0] = m[1][1] = a / (x + y);
    m[2][0] = a / x;
    m[1][2] = m[2][1] = m[2][2] = -1e18;
  }
  Dat operator*(const Dat& rhs) const {
    Dat ret = Dat();
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          ret.m[i][j] = max(ret.m[i][j], m[i][k] + rhs.m[k][j]);
        }
      }
    }
    return ret;
  }
} T[1 << 19];

int a[1 << 18];
void build(int o, int l, int r) {
  if (l == r) {
    T[o] = Dat(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  T[o] = T[o << 1] * T[o << 1 | 1];
}
void upd(int o, int l, int r, int k) {
  if (l == r) {
    T[o] = Dat(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid) upd(o << 1, l, mid, k);
  else upd(o << 1 | 1, mid + 1, r, k);
  T[o] = T[o << 1] * T[o << 1 | 1];
}
Dat qry(int o, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return T[o];
  int mid = (l + r) >> 1;
  if (qr <= mid) return qry(o << 1, l, mid, ql, qr);
  else if (ql > mid) return qry(o << 1 | 1, mid + 1, r, ql, qr);
  else return qry(o << 1, l, mid, ql, mid) * qry(o << 1 | 1, mid + 1, r, mid + 1, qr);
}

double tmp[3];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  int n, q; cin >> n >> q >> x >> y;
  if (x < y) swap(x, y);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n - 1);
  cout << fixed << setprecision(10);
  while (q--) {
    int op, u, v; cin >> op >> u >> v;
    if (op == 1) {
      a[u] = v;
      if (u < n) upd(1, 1, n - 1, u);
    } else {
      Dat res = qry(1, 1, n - 1, u, v - 1);
      tmp[1] = a[v] / double(x + y);
      tmp[2] = a[v] / double(x);
      double ans = -1e18;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          ans = max(ans, res.m[i][j] + tmp[j]);
        }
      }
      cout << ans << '\n';
    }
  }

  return 0;
}