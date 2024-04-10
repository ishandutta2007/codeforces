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

using ll = long long;

void solve(ll k) {
    for(ll c = 1900; c >= 1; --c) {
        ll diff = k / c + 1;
        ll x = diff * c - k;
        ll b = diff + x;
        if(1 <= b && b <= 1000 * 1000 && 1 <= x && x <= 1000 * 1000) {
            debug() << imie(b) imie(x) imie(c);
            printf("%lld\n", c + 1);
            printf("%lld", -x);
            for(int i = 0; i < c; ++i) {
                printf(" %lld", b);
            }
            puts("");
            return;
        }
    }
    assert(false);
}

int main() {
    //~ for(ll k = 1000 * 1000 * 1000; true; --k) {
        //~ cerr << imie(k);
        //~ solve(k);
    //~ }
    ll k;
    cin >> k;
    solve(k);
}