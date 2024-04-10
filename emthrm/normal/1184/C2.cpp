#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)

const int INF = 0x3f3f3f3f;
/*-------------------------------------------------*/
template <typename T>
void rot(T &x, T &y, int angle) {
  if (angle == 45) {
    T tmp_x = x, tmp_y = y;
    x = tmp_x - tmp_y;
    y = tmp_x + tmp_y;
  } else if (angle == 90) {
    swap(x, y);
    x *= -1;
  } else {
    assert(false);
  }
}

template <typename Monoid>
struct StarrySky {
  StarrySky(int sz, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    init(sz);
    dat.assign((n << 1) - 1, DEFAULT);
  }

  StarrySky(const vector<Monoid> &a, const Monoid &UNITY, const Monoid &DEFAULT = 0) : UNITY(UNITY), DEFAULT(DEFAULT) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    REP(i, a_sz) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void add(int a, int b, Monoid value) { add(a, b, value, 0, 0, n); }

  Monoid query(int a, int b) { return query(a, b, 0, 0, n); }

  Monoid value(int idx) {
    idx += n - 1;
    Monoid res = added[idx];
    while (idx > 0) {
      idx = (idx - 1) >> 1;
      res += added[idx];
    }
    return res;
  }

private:
  int n = 1;
  const Monoid UNITY, DEFAULT;
  vector<Monoid> dat, added;

  void init(int sz) {
    while (n < sz) n <<= 1;
    added.assign((n << 1) - 1, DEFAULT);
  }

  void add(int a, int b, Monoid value, int node, int left, int right) {
    if (right <= a || b <= left) return;
    if (a <= left && right <= b) {
      added[node] += value;
    } else {
      add(a, b, value, (node << 1) + 1, left, (left + right) >> 1);
      add(a, b, value, (node << 1) + 2, (left + right) >> 1, right);
      dat[node] = max(dat[(node << 1) + 1] + added[(node << 1) + 1], dat[(node << 1) + 2] + added[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b, int node, int left, int right) {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node] + added[node];
    return max(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right)) + added[node];
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, r; cin >> n >> r;
  vector<int> x(n), y(n);
  REP(i, n) {
    cin >> x[i] >> y[i];
    rot(x[i], y[i], 45);
  }
  int mn_x = INF, mn_y = INF;
  REP(i, n) {
    mn_x = min(mn_x, x[i]);
    mn_y = min(mn_y, y[i]);
  }
  int mx_x = 0, mx_y = 0;
  REP(i, n) {
    x[i] -= mn_x;
    mx_x = max(mx_x, x[i]);
    y[i] -= mn_y;
    mx_y = max(mx_y, y[i]);
  }
  vector<vector<int> > dot(mx_x + 1);
  REP(i, n) dot[x[i]].emplace_back(y[i]);
  StarrySky<int> ss(mx_y + 1, -INF);
  REP(c, 2 * r) {
    if (c > mx_x) break;
    for (int tate : dot[c]) {
      int left = max(tate - r, 0), right = min(tate + r, mx_y);
      ss.add(left, right + 1, 1);
    }
  }
  int ans = ss.query(0, mx_y + 1);
  FOR(c, 2 * r, mx_x + 1) {
    for (int tate : dot[c]) {
      int left = max(tate - r, 0), right = min(tate + r, mx_y);
      ss.add(left, right + 1, 1);
    }
    ans = max(ans, ss.query(0, mx_y + 1));
    for (int tate : dot[c - 2 * r]) {
      int left = max(tate - r, 0), right = min(tate + r, mx_y);
      ss.add(left, right + 1, -1);
    }
  }
  cout << ans << '\n';
  return 0;
}