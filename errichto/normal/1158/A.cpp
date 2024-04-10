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



int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n), b(m);
  for(int& x : a) {
    scanf("%d", &x);
  }
  for(int& x : b) {
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if(a.back() > b[0]) {
    puts("-1");
    return 0;
  }
  long long answer = 0;
  for(int x : a) {
    answer += (long long) x * m;
  }
  for(int x : b) {
    answer += x - a.back();
  }
  // debug() << imie(answer) imie(a) imie(a.end()[-2]) imie(a.back());
  if(b[0] > a.back()) {
    // debug() << imie(a.back()) imie(a.end()[-2]) imie(a.back() + a.end()[-2]);
    answer += a.back() - a.end()[-2];
  }
  cout << answer << endl;
}