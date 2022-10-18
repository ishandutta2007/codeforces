#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

const long double eps = 1e-8;
const long double eps2 = 1e-8;

struct Line {
  long double x, y, dx, dy;
  void read() {
    long double t1, t2;
    cin >> t1 >> x >> y >> t2 >> dx >> dy;
    dx = (dx - x) / (t2 - t1);
    dy = (dy - y) / (t2 - t1);
    x -= dx * t1;
    y -= dy * t1;
  }
};

struct Plane {
  Plane(long double a, long double b, long double c, long double d) : a(a), b(b), c(c), d(d) {};
  long double a, b, c, d;
};

bool operator < (const Plane& a, const Plane& b) {
  if (fabs(a.a - b.a) > eps) return a.a < b.a;
  else if (fabs(a.b - b.b) > eps) return a.b < b.b;
  else if (fabs(a.c - b.c) > eps) return a.c < b.c;
  return a.d < b.d;
}

bool operator == (const Plane& a, const Plane& b) {
  return fabs(a.a - b.a) < eps2 && fabs(a.b - b.b) < eps2 && fabs(a.c - b.c) < eps2 && fabs(a.d - b.d) < eps2;
}

long double dist(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int sgn(long double x) {
  return (x > 0) - (x < 0);
}

bool equal(long double a, long double b, long double c, long double d) {
  return fabs(a - c) < eps && fabs(b - d) < eps;
}

Line ln[1002];
int what[1002];
bool was[1002];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    ln[i].read();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      // if (fabs(dist(ln[i].x, ln[i].y, 0, ln[j].x, ln[j].y, 0) - dist(ln[i].x + 5 * ln[i].dx, ln[i].y + 5 * ln[i].dy, 5, ln[j].x + 5 * ln[j].dx, ln[j].y + 5 * ln[j].dy, 5)) < eps2) {
      //   what[i] = j;
      //   break;
      // }
      if ( fabs(ln[i].dx - ln[j].dx) < eps && fabs(ln[i].dy - ln[j].dy) < eps) { 
        what[i] = j;
        break;
      }
    }
    // cout << what[i] << endl;
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    memset(was, 0, sizeof(was));
    was[what[i]] = true;
    // int x = what[i];
    // for (int j = 0; j < n; ++j)
    //   if (what[j] == x)
    //     what[j] = i;
    vector<long double> tm;
    vector<Plane> v;
    int add = 1;
    for (int j = i; j < n; ++j) {
      if (i == j || what[j] == what[i]) continue;
      long double t = -1; bool ok = false;
      if (fabs(ln[i].dx - ln[j].dx) > eps) {
        t = (ln[i].x - ln[j].x) / (ln[j].dx - ln[i].dx);
        if (fabs(ln[i].x + ln[i].dx * t - ln[j].x - ln[j].dx * t) < eps &&
            fabs(ln[i].y + ln[i].dy * t - ln[j].y - ln[j].dy * t) < eps) {
          ok = true;
        }
      } else if (fabs(ln[i].dy - ln[j].dy) > eps) {
        t = (ln[i].y - ln[j].y) / (ln[j].dy - ln[i].dy);
        if (fabs(ln[i].x + ln[i].dx * t - ln[j].x - ln[j].dx * t) < eps &&
            fabs(ln[i].y + ln[i].dy * t - ln[j].y - ln[j].dy * t) < eps) {
          ok = true;
        }
      } else {
        // if (fabs(ln[i].x - ln[j].x) < eps && fabs(ln[i].y - ln[j].y) < eps) {
        //   ++add;
        // }
      }
      if (ok) {
        tm.push_back(t);
        long double x1 = ln[i].x, y1 = ln[i].y, z1 = 0, z2 = 12.0643, x2 = x1 + ln[i].dx * z2, y2 = y1 + ln[i].dy * z2;
        long double z3 = 17.324, x3 = ln[j].x + ln[j].dx * z3, y3 = ln[j].y + ln[j].dy * z3;
        // if (equal(x1, y1, x2, y2) || equal(x1, y1, x3, y3) || equal(x2, y2, x3, y3)) return -1;
        long double a = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1),
                    b = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1),
                    c = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1),
                    d = -x1 * a - y1 * b - z1 * c;
        long double g = sqrt(a * a + b * b + c * c);
        if (g > eps && !was[what[j]]) {
          if (fabs(a) > eps) g *= sgn(a);
          else if (fabs(b) > eps) g *= sgn(b);
          else g *= sgn(c); 
          a /= g; b /= g; c /= g; d /= g;
          // cout << a << "  " << b << " " << c << " " << d << " " << j << endl;
          if (fabs(a) > eps || fabs(b) > eps || fabs(c) > eps) {
            v.push_back(Plane(a, b, c, d));
            was[what[j]] = true;
          }
        }
      }
    }
    // cout << endl;
    if (tm.size()) {
      ans = max(ans, add + 1);
    }
    // cout << add << "  " << tm.size() << endl;
    sort(tm.begin(), tm.end());
    int cnt = 1;
    for (int j = 1; j < tm.size(); ++j) {
      if (fabs(tm[j] - tm[j - 1]) < eps) ++cnt;
      else {
        cnt = 1;
      }
      ans = max(ans, cnt + add);
    }
    sort(v.begin(), v.end());
    cnt = 1;
    for (int j = 1; j < v.size(); ++j) {
      if (v[j] == v[j - 1]) ++cnt;
      else {
        cnt = 1;
      }
      ans = max(ans, cnt + add);
    }
  }
  cout << ans << endl;
  return 0;
}