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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL k;
bool g[33554433] = {};

int main() {
    cin >> n >> k, ++k;
    int nOdd = n & 1;
    n >>= 1;
    int mx = (1 << (n - 1)) - 1;
    for (int mask = 0; mask <= mx; ++mask) {
         for (int odd = 0; odd <= nOdd; ++odd) {
            int cnt = (mx - mask + 1) << 1;
            cnt -= odd;
            if (k > cnt) {
                k -= cnt;
                continue;
            }
            int invMask = (1 << n) - 1;
            for (int i = mask; i <= mx; ++i) {
                int j = 0;
                REP(k, n) if (i & (1 << k)) {
                    j |= 1 << (n - 1 - k);
                }
                g[j] = true;
                if (i != mask || !odd) g[invMask & (~j)] = true;
            }
            for (int i = 0; i <= invMask; ++i) if (g[i] && --k == 0) {
                for (int j = n - 1; j >= 0; --j) if (mask & (1 << j)) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                if (nOdd) {
                    if (odd) cout << 1;
                    else cout << 0;
                }
                for (int j = n - 1; j >= 0; --j) if (i & (1 << j)) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                return 0;
            }
            assert(false);
        }
    }
    cout << -1 << endl;
    return 0;
}