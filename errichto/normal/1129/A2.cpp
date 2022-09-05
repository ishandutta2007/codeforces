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

const int INF = 1e9 + 5;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> cnt(n), small(n, INF);
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        ++cnt[a];
        int dist = b - a;
        if(dist < 0) {
            dist += n;
        }
        small[a] = min(small[a], dist);
    }
    for(int start = 0; start < n; ++start) {
        int answer = 0;
        for(int a = 0; a < n; ++a) {
            if(cnt[a]) {
                int dist = a - start;
                if(dist < 0) {
                    dist += n;
                }
                answer = max(answer, n * (cnt[a] - 1) + dist + small[a]);
            }
        }
        printf("%d ", answer);
    }
    puts("");
}