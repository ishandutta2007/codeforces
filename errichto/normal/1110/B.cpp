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



int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> gaps;
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        if(i != 0) {
            gaps.push_back(b[i] - b[i-1]);
        }
    }
    sort(gaps.rbegin(), gaps.rend());
    int answer = b.back() - b[0];
    for(int i = 0; i < min(k - 1, (int) gaps.size()); ++i) {
        answer -= gaps[i];
    }
    printf("%d\n", answer + k);
}