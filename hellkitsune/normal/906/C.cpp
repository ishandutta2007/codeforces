#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[22];
int d[1 << 22], p[1 << 22], ind[1 << 22];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        a[u] |= 1 << v;
        a[v] |= 1 << u;
    }
    forn(i, 1 << n) d[i] = 1234;
    forn(mask, 1 << n) {
        if (__builtin_popcount(mask) <= 1) {
            d[mask] = 0;
            continue;
        }
        forn(i, n) if (mask & (1 << i)) {
            int need = mask ^ (1 << i);
            if (d[need] == 0 && (need & a[i]) == need) {
                d[mask] = 0;
            }
            break;
        }
    }
    forn(mask, 1 << n) if (d[mask] < 1234) {
        forn(i, n) if (mask & (1 << i)) {
            int nmask = mask | a[i];
            if (d[nmask] > d[mask] + 1) {
                d[nmask] = d[mask] + 1;
                p[nmask] = mask;
                ind[nmask] = i;
            }
        }
    }
    printf("%d\n", d[(1 << n) - 1]);
    vector<int> res;
    for (int mask = (1 << n) - 1; d[mask] > 0; mask = p[mask]) {
        res.pb(ind[mask]);
    }
    reverse(res.begin(), res.end());
    for (int x : res) printf("%d ", x + 1);
    puts("");
    return 0;
}