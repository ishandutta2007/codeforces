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

#define pc __builtin_popcount

void test_case(int n = 0) {
    if(n == 0) {
        scanf("%d", &n);
    }
    if(pc(n + 1) != 1) {
        int answer = 1;
        while(answer <= n) {
            answer *= 2;
        }
        printf("%d\n", answer - 1);
        return;
    }
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            printf("%d\n", n / i);
            return;
        }
    }
    puts("1");
}

int main() {
    //~ for(int i = 1; i <= 100; ++i) {
        //~ printf("%d: ", i);
        //~ test_case(i);
    //~ }
    int T;
    scanf("%d", &T);
    while(T--) {
        test_case();
    }
}