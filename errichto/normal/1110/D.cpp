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

const int nax = 1e6 + 5;
int dp[nax][5][5];
// dp[x][A][B] - now we consider position 'x', and the remaining value at x-2 is A,
// and at x-1 is B
const int INF = 1e9 + 5;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> cnt(m + 1);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    for(int i = 0; i <= m + 1; ++i) {
        for(int A = 0; A <= 4; ++A) {
            for(int B = 0; B <= 4; ++B) {
                dp[i][A][B] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i <= m; ++i) {
        for(int A = 0; A <= 4; ++A) {
            for(int B = 0; B <= 4; ++B) {
                int me = dp[i][A][B];
                if(me < 0) {
                    continue;
                }
                // c - the number of times we use a triple (i-2, i-1, i)
                for(int rem = 0; rem <= min(7, cnt[i]); ++rem) {
                    if((cnt[i] - rem) % 3) {
                        continue;
                    }
                    int extra = (cnt[i] - rem) / 3;
                    for(int c = 0; c <= min({A, B, rem, 2}); ++c) {
                        int A2 = B - c;
                        int B2 = min(4, rem - c);
                        dp[i+1][A2][B2] = max(dp[i+1][A2][B2], me + c + extra);
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int A = 0; A <= 4; ++A) {
        for(int B = 0; B <= 4; ++B) {
            answer = max(answer, dp[m+1][A][B]);
        }
    }
    printf("%d\n", answer);
}