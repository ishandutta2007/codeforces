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

vector<int> read(int n) {
    vector<int> a(n);
    vector<int> diff;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(i != 0) {
            diff.push_back(a[i] - a[i-1]);
        }
    }
    sort(diff.begin(), diff.end());
    diff.push_back(a[0]);
    return diff;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a = read(n);
    vector<int> b = read(n);
    puts(a == b ? "Yes" : "No");
}