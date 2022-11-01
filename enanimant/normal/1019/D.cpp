/*
 * author:  ADMathNoob
 * created: 08/08/21 23:32:53
 * problem: https://codeforces.com/contest/1019/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }
  
  friend T dot(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }

  friend T cross(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }

  inline T abs2() const {
    return x * x + y * y;
  }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};

template <typename T>
T TwiceArea(int n, const vector<TPoint<T>>& v) {
  T res = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    res += v[i].x * v[j].y - v[i].y * v[j].x;
  }
  return res;
}

template <typename T>
T TwiceArea(const vector<TPoint<T>>& v) {
  return TwiceArea((int) v.size(), v);
}

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  string res = "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
  if (p.id != -1) {
    res = "id " + to_string(p.id) + ": " + res;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long S;
  cin >> n >> S;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = Point(x, y);
  }
  
  // prepare for angle sweep
  sort(p.begin(), p.end());
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  vector<int> pos(n);
  iota(pos.begin(), pos.end(), 0);

  // events (when two points swap positions in the order)
  vector<tuple<Point, int, int>> slopes;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      slopes.emplace_back(p[j] - p[i], i, j);
    }
  }
  sort(slopes.begin(), slopes.end(), [&](auto a, auto b) {
    Point m1 = get<0>(a);
    Point m2 = get<0>(b);
    int c = m1.cmp_polar(m2);
    return (c == -1);
  });

  int beg = 0;
  int E = (int) slopes.size();
  vector<Point> res;
  while (beg < E) {
    int end = beg;
    Point slope = get<0>(slopes[beg]);
    while (end < E && cross(slope, get<0>(slopes[end])) == 0) {
      end += 1;
    }
    
    vector<int> changed;
    for (int z = beg; z < end; z++) {
      const auto [_, i, j] = slopes[z];
      // in case of multiple colinear points
      --pos[j];
      ++pos[i];
      changed.push_back(i);
      changed.push_back(j);
    }
    for (int i : changed) {
      order[pos[i]] = i;
    }
    
    for (int z = beg; z < end; z++) {
      int i, j;
      tie(ignore, i, j) = slopes[z];
      auto Get = [&](int k) {
        // what is "structured binding cannot be captured"?
        // forces the usage of tie(...)
        vector<Point> t = {p[i], p[j], p[k]};
        return TwiceArea(t);
      };
      int low = pos[j], high = n - 1;
      while (low < high) {
        int mid = (low + high) / 2;
        long long area = Get(order[mid]);
        if (area < 2 * S) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      if (Get(order[low]) == 2 * S) {
        res = {p[i], p[j], p[order[low]]};
      }
    }
    beg = end;
  }
  if (res.empty()) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
    for (const Point& pt : res) {
      cout << pt.x << ' ' << pt.y << '\n';
    }
  }
  return 0;
}