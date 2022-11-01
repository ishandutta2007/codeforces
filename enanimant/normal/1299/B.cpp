// February 9, 2020
// https://codeforces.com/contest/1299/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


struct Point {
  int x, y;
};

long long dist2(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point vect(const Point &a, const Point &b) {
  return {b.x - a.x, b.y - a.y};
}

Point nvect(const Point &a, const Point &b) {
  // normalized direction vector
  Point res = {b.x - a.x, b.y - a.y};
  if (res.x < 0) {
    res.x = -res.x;
    res.y = -res.y;
  }
  int g = __gcd(res.x, res.y);
  res.x /= g;
  res.y /= g;
  return res;
}

vector<Point> res;

void add(int x, int y) {
  Point q = {x, y};
  while (res.size() >= 2) {
    int s = res.size();
    Point v1 = nvect(res[s - 1], res[s - 2]);
    Point v2 = nvect(q, res[s - 1]);
    if (v1.x == v2.x && v1.y == v2.y) {
      break;
    }
    res.pop_back();
  }
  res.push_back(q);
}

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
  if (n % 2 == 1) {
    cout << "no\n";
    return 0;
  }
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 0; i < n / 2; i++) {
    Point v1 = vect(p[i], p[i + 1]);
    Point v2 = vect(p[(i + n / 2 + 1) % n], p[i + n / 2]);
    if (v1.x != v2.x || v1.y != v2.y) {
      cout << "no\n";
      return 0;
    }
  }
  cout << "yes\n";
  // vector<Point> v(n);
  // for (int i = 0; i < n; i++) {
  //   int j = (i + 1) % n;
  //   v[i].x = p[j].x - p[i].x;
  //   v[i].y = p[j].y - p[i].y;
  // }
  // long long d = 0; // max distance from p[0]
  // int bid = -1;
  // for (int i = 1; i < n; i++) {
  //   if (dist(p[0], p[i]) > d) {
  //     d = dist(p[0], p[i]);
  //     bid = i;
  //   }
  // }
  // res.push_back(vect(p[0], p[bid]));



  return 0;
}