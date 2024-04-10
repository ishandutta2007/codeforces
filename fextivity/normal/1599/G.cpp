#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = (int)2e5 + 5;
const double oo = 1e9 + 7;

struct pt {
  ll x, y;

  pt operator + (pt p) {return {x + p.x, y + p.y};}
  pt operator - (pt p) {return {x - p.x, y - p.y};}
  ll operator * (pt p) {return x * p.y - y * p.x;}
  ll operator | (pt p) {return x * p.x + y * p.y;}

  bool inline operator == (const pt &rhs) const {
    return x == rhs.x && y == rhs.y;
  }
};

struct line {
  pt v; ll c;
  line(pt p, pt q): v(q-p), c(v*p) {}
  bool is_on(pt p) {return v*p == c;}
};

int n, k;
pt p[MAXN];

line find_line() {
  for(int i = 0; i < 3; ++i) {
    for(int j = i+1; j < 3; ++j) {
      line l(p[i], p[j]);

      int cnt = 0;
      for(int t = 0; t < n; ++t)
        if (l.is_on(p[t])) ++cnt;

      if (cnt == n-1) 
        return l;      
    }
  }

  cerr << "Line not found" << endl;
  exit(0);
}

int main() {
  cin >> n >> k; --k;
  for(int i = 0; i < n; ++i)
    cin >> p[i].x >> p[i].y;

  pt save = p[k];

  // find the line with n-1 points
  line l = find_line();
  // swap the outlier to last
  for(int i = 0; i < n; ++i) {
    if (!l.is_on(p[i])) {      
      swap(p[i], p[n-1]);
      break;
    }
  }
  --n;

  // sort n-1 points by projection
  auto proj_cmp = [&] (pt p, pt q) {
    return (l.v | p) < (l.v | q);
  };
  sort(p, p+n, proj_cmp);

  // find answer (https://codeforces.com/contest/30/problem/D)   
  auto dist = [&] (int i, int j) {
    return hypot(p[i].x-p[j].x, p[i].y-p[j].y);
  };
  auto cover = [&] (int l, int r) {
    return min(dist(l, n), dist(r, n)) + dist(l, r);
  };

  for(int i = 0; i <= n; ++i) {
    if (p[i] == save) {
      k = i;
      break;
    }
  }

  // for(int i = 0; i < n; ++i)
  //   cout << "(" << p[i].x << ", " << p[i].y << ")" << endl;
  // cout << "k: " << k << endl;

  double ans = oo;
  if (k == n)
    ans = cover(0, n-1);
  else {
    for(int i = 0; i <= k; ++i) {
      double d = min(dist(k, i) + dist(n-1, n), dist(k, n-1) + dist(i, n)) + dist(i, n-1);
      if (i > 0)
        d += cover(0, i-1);
      ans = min(ans, d);
    }

    for(int i = k; i < n; ++i) {
      double d = min(dist(k, i) + dist(0, n), dist(k, 0) + dist(i, n)) + dist(0, i);
      if (i < n-1)
        d += cover(i+1, n-1);
      ans = min(ans, d);
    }
  }
 
  printf("%.15g\n", ans);

  return 0;
}