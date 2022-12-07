#include <cstdio>
#include <cmath>
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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
LL d[1024], d2[1024], ans = 0;
const int mod = 1e9 + 7;
LL twon[2005];
int sum0 = 0;
int a[2005];

int main() {
    cin >> n >> k;
    twon[0] = 1;
    for (int i = 1; i <= n; ++i)
        twon[i] = (twon[i - 1] << 1) % mod;
    k = (1 << (k - 1));
    REP(i, k)
        d[i] = 0;
    d[0] = 1;
    REP(q, n) {
        cin >> a[q];
        if (a[q] == 0)
            ++sum0;
    }
    REP(q, n) {
        int x = a[q];
        if (a[q] == 0)
            --sum0;
        x >>= 1;
        REP(i, k)
            d2[i] = 0;
        if (x == 0 || x == 1) {
            REP(i, k - 1) {
                d2[i + 1] = d[i];
            }
            ans = (ans + d[k - 1] * twon[sum0]) % mod;
        }
        if (x == 0 || x == 2) {
            REP(i, k) {
                int newi;
                if (i & 1)
                    newi = 2;
                else
                    newi = i + 2;
                if (newi < k)
                    d2[newi] = (d2[newi] + d[i]) % mod;
                else
                    ans = (ans + d[i] * twon[sum0]) % mod;
            }
        }
        REP(i, k)
            d[i] = d2[i];
    }
    cout << ans << endl;
    return 0;
}