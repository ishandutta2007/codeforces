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
	int n, k;
    scanf("%d%d", &n, &k);
    int spec = (1 << k) - 1;
    int pref = 0;
    map<int, int> mapka;
    ++mapka[0];
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        pref ^= x;
        int maybe = pref ^ spec;
        if(mapka[maybe] < mapka[pref]) {
            pref = maybe;
            ++mapka[maybe];
        }
        else {
            ++mapka[pref];
        }
    }
    long long answer = 0;
    for(pair<int,int> p : mapka) {
        int x = p.second;
        answer += (long long) x * (x - 1) / 2;
    }
    answer = (long long) n * (n + 1) / 2 - answer;
    printf("%lld\n", answer);
}