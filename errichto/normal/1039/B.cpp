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
 
 int ope;
bool query(ll low, ll high) {
    assert(++ope <= 400);
  printf("%lld %lld\n", low, high);
  fflush(stdout);
  char sl[10];
  scanf("%s", sl);
  if(sl[0] == 'B') assert(false);
  if(sl[0] == 'Y') {
    if(low == high) exit(0);
    return true;
  }
  if(sl[0] == 'N') return false;
  assert(false);
}
 
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
  ll n;
  int k;
  scanf("%lld%d", &n, &k);
  ll low = 1, high = n;
  while(low < high) {
    if(abs(low - high) <= 60) {
      int i = rand() % (high - low + 1);
      assert(!query(low + i, low + i));
    }
    else {
      ll mid = (low + high) / 2;
      if(query(low, mid)) high = mid;
      else low = mid + 1;
    }
    low = max(1LL, low - k);
    high = min(n, high + k);
  }
  query(low, high);
  assert(false);
}