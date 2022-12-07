#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, aa, bb, n;
int v[100000];
int cnt = 0;
int mul[1 << 22];
int pre[123123];

int main() {
    scanf("%d%d%d%d%d", &a, &b, &aa, &bb, &n);
    forn(i, n) scanf("%d", v + i);
    if ((aa >= a && bb >= b) || (bb >= a && aa >= b)) {
        cout << 0 << endl;
        return 0;
    }
    sort(v, v + n, greater<int>());
    int nn = 0;
    LL x = aa, y = bb;
    forn(i, n) {
        if (v[i] == 2) {
            cnt = n - i;
            nn = i;
            break;
        }
        if (x < a) x *= v[i];
        else y *= v[i];
        ++nn;
        if (x >= a && y >= b) {
            break;
        }
    }
    n = nn;
    assert(n <= 22);
    mul[0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        forn(i, n) if (mask & (1 << i)) {
            mul[mask] = min((LL)mul[mask ^ (1 << i)] * v[i], 123123ll);
            break;
        }
    }
    int have = 1;
    int res = 0;
    for (int i = 1; i < 123123; ++i) {
        if (have < i) {
            have *= 2;
            ++res;
        }
        pre[i] = res;
    }
    int ans = 1234;
    for (int c = 0; c <= n; ++c) {
        int full = (1 << c) - 1;
        forn(mask, 1 << c) {
            int x = min((LL)aa * mul[mask], 123123ll);
            int y = min((LL)bb * mul[full ^ mask], 123123ll);
            int need = 0;
            need += pre[(a + x - 1) / x];
            need += pre[(b + y - 1) / y];
            if (need <= cnt) {
                ans = min(ans, c + need);
            }
            need = 0;
            need += pre[(b + x - 1) / x];
            need += pre[(a + y - 1) / y];
            if (need <= cnt) {
                ans = min(ans, c + need);
            }
        }
    }
    if (ans == 1234) ans = -1;
    cout << ans << endl;
    return 0;
}