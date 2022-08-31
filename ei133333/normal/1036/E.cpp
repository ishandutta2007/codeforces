#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using Point = pair< int64, int64 >;
using Segment = pair< Point, Point >;

Point sub(const Point &p1, const Point &p2) {
  return Point(p1.first - p2.first, p1.second - p2.second);
}

int64 cross(const Point &a, const Point &b) {
  return a.first * b.second - a.second * b.first;
}

Point mul(const Point &p, int64 d) {
  return Point(p.first * d, p.second * d);
}

int64 dot(const Point &a, const Point &b) {
  return a.first * b.first + a.second * b.second;
}

int ccw(const Point &a, Point b, Point c) {
  b = sub(b, a), c = sub(c, a);
  if(cross(b, c) > 0) return +1;  // "COUNTER_CLOCKWISE"
  if(cross(b, c) < 0) return -1; // "CLOCKWISE"
  if(dot(b, c) < 0) return +2;      // "ONLINE_BACK"
  if(b.first * b.first + b.second * b.second < c.first * c.first + c.second * c.second) return -2;  // "ONLINE_FRONT"
  return 0;                         // "ON_SEGMENT"
}

const Point INF(1LL << 60, 1LL << 60);

Point crosspoint(const Segment &l, const Segment &m) {
  int64 A = cross(sub(l.second, l.first), sub(m.second, m.first));
  int64 B = cross(sub(l.second, l.first), sub(l.second, m.first));
  if(abs(A) == 0 && abs(B) == 0) return m.first;
  auto p = mul(sub(m.second, m.first), B);
  if(p.first % A == 0 && p.second % A == 0) return Point(m.first.first + p.first / A, m.first.second + p.second / A);
  return INF;
}

bool intersect(const Segment &s, const Segment &t) {
  return ccw(s.first, s.second, t.first) * ccw(s.first, s.second, t.second) <= 0 &&
         ccw(t.first, t.second, s.first) * ccw(t.first, t.second, s.second) <= 0;
}


int main() {
  int N, A[1000], B[1000], C[1000], D[1000];
  cin >> N;
  int64 add = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    add += __gcd((int) abs(C[i] - A[i]), (int) abs(D[i] - B[i])) + 1;
  }
  for(int i = 0; i < N; i++) {
    vector< Point > p;
    for(int j = 0; j < i; j++) {
      auto s1 = Segment(Point(A[i], B[i]), Point(C[i], D[i]));
      auto s2 = Segment(Point(A[j], B[j]), Point(C[j], D[j]));
      if(intersect(s1, s2)) {
        auto it = crosspoint(s1, s2);
        if(it != INF) p.emplace_back(it);
      }
    }
    sort(begin(p), end(p));
    p.erase(unique(begin(p), end(p)), end(p));
    add -= p.size();
  }
  cout << add << endl;

}