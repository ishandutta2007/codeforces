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

bool is_pali(const string& s) {
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n - 1; ++i) {
        string a;
        for(int j = i + 1; j < n; ++j) {
            a += s[j];
        }
        for(int j = 0; j <= i; ++j) {
            a += s[j];
        }
        if(a != s && is_pali(a)) {
            puts("1");
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(s[i] != s[0] && !(n % 2 == 1 && i == n / 2)) {
            puts("2");
            return 0;
        }
    }
    puts("Impossible");
}