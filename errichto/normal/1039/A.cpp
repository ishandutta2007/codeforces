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

void NO() {
  puts("No");
  exit(0);
}

int main() {
  int n;
  ll t;
  scanf("%d%lld", &n, &t);
  vector<ll> a(n);
  for(ll & x : a) scanf("%lld", &x);
  vector<int> x(n);
  for(int & i : x) {
    scanf("%d", &i);
    --i;
  }
  if(x.back() != n - 1) NO();
  vector<ll> b(n);
  for(int i = 0; i < n; ++i) {
    if(i && x[i] < x[i-1]) NO();
    b[x[i]] = a[i] + t;
  }
  for(int i = 0; i < n - 1; ++i) {
    if(x[i] != i) {
      assert(b[i] <= a[i+1] + t);
      b[i] = a[i+1] + t;
    }
  }
  debug() << imie(b);
  for(int i = 1; i < n; ++i) {
    b[i] = max(b[i], b[i-1] + 1);
  }
  vector<int> pref(n);
  for(int i = 1; i < n; ++i) {
    pref[i] = pref[i-1];
    if(b[i-1] >= a[i] + t) ++pref[i];
  }
  debug() << imie(pref);
  auto get = [&] (int low, int high) {
    return high - low + 1 == pref[high] - (low ? pref[low-1] : 0);
  };
  for(int i = 0; i < n - 1; ++i) {
    //~ debug() << imie(i + 1) imie(x[i] + 1);
    if(x[i] != n - 1 && get(i + 1, x[i] + 1)) NO();
    //~ if(x[i] == i && b[i] <= a[i+1] + t) NO();
    //~ if(x[i] != n - 1 && b[x[i]+1] <= a[i] + t) NO();
  }
  puts("Yes");
  for(ll z : b) printf("%lld ", z);
  puts("");
}