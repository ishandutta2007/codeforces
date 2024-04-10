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

const int mod = 1e9 + 7;

long long mod2;

bool is_prime(long long p) {
    for(long long i = 2; i * i <= p && i <= 5000LL * 1000; ++i) {
        if(p % i == 0) {
            return false;
        }
    }
    return p;
}

void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}

int answer = 0;

unordered_set<long long> secik[3005];

void f(const vector<bool>& s) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        int mask = 0;
        for(int j = i; j <= i + 3 && j < n; ++j) {
            mask = 2 * mask + int(s[j]);
            if(j == i + 3 && (mask == 15 || mask == 7 || mask == 10 || mask == 12)) {
                continue;
            }
            add_self(dp[j+1], dp[i]);
        }
    }
    long long h = mod2 * 2 / 3;
    for(int i = 0; i < n; ++i) {
        h = 2 * h + int(s[i]);
        while(h >= mod2) {
            h -= mod2;
        } //) % mod2;
        //~ assert(h < mod2);
        if(secik[i].insert(h).second) {
            add_self(answer, dp[i+1]);
        }
    }
        
    //~ for(int i = 1; i <= n; ++i) {
        //~ add_self(answer, dp[i]);
    //~ }
    printf("%d\n", answer);
}

int main() {
    auto tmp = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    //~ cout << tmp;
    mod2 = 50 * 1000LL * 1000 * 990 * 1000 * 1000 + tmp % (10 * 1000 * 1000);
    while(!is_prime(mod2)) {
        ++mod2;
    }
    debug() << imie(mod2);
    int n;
    scanf("%d", &n);
    vector<bool> w;
    while(n--) {
        char ch;
        scanf(" %c", &ch);
        w.push_back(ch == '1');
        vector<bool> s = w;
        reverse(s.begin(), s.end());
        f(s);
    }
}