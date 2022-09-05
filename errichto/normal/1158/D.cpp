#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

struct P {
  ll x, y;
  int id;
  P operator -(const P& he) const {
    return P{x - he.x, y - he.y, id};
  }
  ll operator *(const P& he) const {
    return x * he.y - y * he.x;
  }
  void read() {
    cin >> x >> y;
  }
};

vector<P> get_hull(vector<P> w) {
  assert((int) w.size() >= 3);
  vector<P> hull;
  for(int rep = 0; rep < 2; ++rep) {
    int S = hull.size();
    for(P C : w) {
      while((int) hull.size() >= S + 2) {
        P A = hull.end()[-2];
        P B = hull.back();
        if((B - A) * (C - B) < 0) {
          break;
        }
        hull.pop_back();
      }
      hull.push_back(C);
    }
    hull.pop_back();
  }
  return hull;
};

int main() {
  int n;
  cin >> n;
  vector<P> w(n);
  for(int i = 0; i < n; ++i) {
    w[i].read();
    w[i].id = i + 1;
  }
  sort(w.begin(), w.end(), [&](const P& a, const P& b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
  });
  string s;
  cin >> s;
  P a = w[0];
  // vector<P> hull = get_hull(w);
  // P a = hull[0];
  // P b = hull[1];
  // if(s[0] == 'L') {
    // swap(a, b);
  // }
  // printf("%d %d ", a.id, b.id);
  printf("%d ", a.id);
  w.erase(w.begin());
  for(int ii = 0; ii < (int) s.size(); ++ii) {
    P best{-1, -1, -1};
    for(int i = 0; i < (int) w.size(); ++i) {
      if(w[i].id == a.id) {
        continue;
      }
      P maybe = w[i];
      if(best.id == -1) {
        best = maybe;
      }
      else {
        if((s[ii] == 'R') == ((maybe - a) * (best - a) < 0)) {
          best = maybe;
        }
      }
    }
    printf("%d ", best.id);
    for(int i = 0; i < (int) w.size(); ++i) {
      if(w[i].id == best.id) {
        w.erase(w.begin() + i);
      }
    }
    a = best;
  }
  assert((int) w.size() == 1);
  printf("%d\n", w[0].id);
}