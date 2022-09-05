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
	string s;
    cin >> s;
    int n = s.length();
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) {
        string x;
        for(int j = 0; j <= i; ++j) {
            x += s[j];
        }
        string y = x;
        reverse(y.begin(), y.end() - 1);
        reverse(y.begin(), y.end());
        if(y < x) {
            ans[i] = 1;
            for(int j = 0; j <= i; ++j) {
                s[j] = y[j];
            }
            if(i) {
                ans[i-1] ^= 1;
            }
        }
    }
    //~ int pref = 0;
    //~ for(int i = n - 1; i >= 0; --i) {
        //~ pref ^= ans[i];
        //~ ans[i] = pref;
    //~ }
    for(int x : ans) {
        printf("%d ", x);
    }
    puts("");
    
}