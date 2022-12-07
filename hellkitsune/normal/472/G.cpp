#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef unsigned long long ULL;
typedef pair<int, int> PII;

string s, t;
ULL a[64 << 12] = {}, b[64 << 12] = {};
int n, m, N, M;
int pre[1 << 16];

void go(string s, ULL (&a)[64 << 12]) {
    REP(i, s.length()) if (s[i] == '1')
        a[i >> 6] |= (ULL)1 << (i & 63);
    for (ULL i = 1; i < 64; ++i) {
        REP(j, 3141) a[(i << 12) | j] = a[((i - 1) << 12) | j];
        ULL mem = 0, tmp;
        for (int j = 3140; j >= 0; --j) {
            tmp = a[(i << 12) | j] & 1;
            a[(i << 12) | j] >>= 1;
            a[(i << 12) | j] |= mem << 63;
            mem = tmp;
        }
    }
}

inline int countBits(ULL x) {
    return pre[x & 65535] + pre[(x >> 16) & 65535] + pre[(x >> 32) & 65535] + pre[(x >> 48) & 65535];
}

int q;

int main() {
    REP(i, 1 << 16) pre[i] = __builtin_popcount(i);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    go(s, a);
    go(t, b);
    n = (int)s.length();
    N = (n + 100) / 64;
    m = (int)t.length();
    M = (m + 100) / 64;
    cin >> q;
    REP(query, q) {
        int x, y, len;
        cin >> x >> y >> len;
        int apos = (x & 63) << 12;
        int bpos = (y & 63) << 12;
        int as = x >> 6;
        int bs = y >> 6;
        apos += as;
        bpos += bs;
        int cnt = len >> 6;
        int ans = 0;
        for (int i = 0; i < cnt; ++i)
            ans += countBits(a[apos + i] ^ b[bpos + i]);
        int rem = len & 63;
        if (rem > 0) {
            ans += countBits((a[apos + cnt] ^ b[bpos + cnt]) & (((ULL)1 << rem) - 1));
        }
        cout << ans << '\n';
    }
    return 0;
}