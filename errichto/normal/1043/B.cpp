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
	int n;
    scanf("%d", &n);
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<int> all;
    for(int k = 1; k <= n; ++k) {
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            int diff = a[i] - a[i-1];
            int j = (i - 1) % k;
            if(diff != a[j+1] - a[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            all.push_back(k);
        }
    }
    printf("%d\n", (int) all.size());
    for(int x : all) {
        printf("%d ", x);
    }
    puts("");
}