#include <bits/stdc++.h>

using namespace std;


struct Point {
  int x, y;
};

class FenwickTree {
public:
  int n;
  vector<int> fenw;

  FenwickTree(int _n) : n(_n) {
    fenw.resize(n + 1, 0);
  }

  void add(int k, int v) {
    k++;
    while (k <= n) {
      fenw[k] += v;
      k += k & -k;
    }
  }

  void assign(int k, int v) {
    add(k, v - sum(k, k));
  }

  int sum(int k) {
    k++;
    int s = 0;
    while (k >= 1) {
      s += fenw[k];
      k -= k & -k;
    }
    return s;
  }

  int sum(int ll, int rr) {
    return sum(rr) - sum(ll - 1);
  }
};


const int INF = 2e9;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<Point> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
    return a.x < b.x;
  });
  unordered_map<int, int> mm;
  for (int i = 0; i < n; i++) {
    if (!mm.count(pts[i].x)) {
      int sz = mm.size();
      mm[pts[i].x] = sz;
    }
  }
  sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
    if (a.y != b.y) {
      return a.y > b.y;
    }
    return a.x < b.x;
  });
  int c = 0;
  FenwickTree ft(n);
  long long ans = 0;
  while (c < n) {
    int e = c;
    while (e < n && pts[e].y == pts[c].y) {
      int x = mm[pts[e++].x];
      ft.assign(x, 1);
    }
    // [c, e) have equal y-coord
    for (int i = c; i < e; i++) {
      int x = mm[pts[i].x];
      int last = (i == c ? -1 : mm[pts[i - 1].x]);
      int l = ft.sum(last + 1, x);
      int r = ft.sum(x, n - 1);
      ans += (long long) l * r;
    }
    c = e;
  }
  cout << ans << '\n';


  return 0;
}