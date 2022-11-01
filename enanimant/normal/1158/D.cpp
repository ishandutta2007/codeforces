/*
 * author:  ADMathNoob
 * created: 08/05/21 11:48:43
 * problem: https://codeforces.com/contest/1158/problem/D
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

  TPoint& operator+=(const TPoint& rhs) { x += rhs.x; y += rhs.y; return *this; }
  TPoint& operator-=(const TPoint& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
  TPoint& operator*=(const TPoint& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
  TPoint& operator/=(const TPoint& rhs) { x /= rhs.x; y /= rhs.y; return *this; }

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

template <typename T> TPoint<T> operator+(const TPoint<T>& lhs, const TPoint<T>& rhs) { return TPoint<T>(lhs) += rhs; }
template <typename T> TPoint<T> operator-(const TPoint<T>& lhs, const TPoint<T>& rhs) { return TPoint<T>(lhs) -= rhs; }
template <typename T> TPoint<T> operator*(const TPoint<T>& lhs, const TPoint<T>& rhs) { return TPoint<T>(lhs) *= rhs; }
template <typename T> TPoint<T> operator/(const TPoint<T>& lhs, const TPoint<T>& rhs) { return TPoint<T>(lhs) /= rhs; }

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

bool LeftTurn(const Point& p, const Point& q, const Point& r) {
  return cross(q - p, r - q) > 0;
}

bool RightTurn(const Point& p, const Point& q, const Point& r) {
  return cross(q - p, r - q) < 0;
}

bool Colinear(const Point& p, const Point& q, const Point& r) {
  return cross(q - p, r - p) == 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].id = i;
  }
  Point start = p[0];
  for (int i = 1; i < n; i++) {
    if (p[i] < start) {
      start = p[i];
    }
  }
  string dir;
  cin >> dir;
  vector<Point> ret(1, start);
  vector<bool> alive(n, true);
  alive[ret[0].id] = false;
  for (int it = 0; it < n - 1; it++) {
    Point last = ret[it];
    Point best;
    bool left = (it == n - 1 || dir[it] == 'L');
    for (int i = 0; i < n; i++) {
      if (alive[i]) {
        if (best.id == -1) {
          best = p[i];
        } else {
          long long c = cross(best - last, p[i] - last);
          if ((left && c < 0) || (!left && c > 0)) {
            best = p[i];
          }
        }
      }
    }
    ret.push_back(best);
    alive[best.id] = false;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ret[i].id + 1;
  }
  cout << '\n';
  return 0;
}