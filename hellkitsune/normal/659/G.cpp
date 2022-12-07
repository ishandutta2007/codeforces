#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int h[1000000];
const int MOD = 1e9 + 7;
int ans = 0;
int a[1000000], c[1000000];
int tot[1000000];

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", h + i), --h[i];
    a[0] = 0;
    c[0] = h[0];
    tot[0] = h[0];
    for (int i = 1; i < n; ++i) if (h[i] >= h[i - 1]) {
        tot[i] = ((LL)tot[i - 1] * h[i - 1] + h[i]) % MOD;
        a[i] = tot[i - 1];
        c[i] = h[i - 1];
    } else {
        a[i] = ((LL)(a[i - 1] + 1) * min(c[i - 1], h[i]) + max(0, h[i] - c[i - 1])) % MOD;
        c[i] = h[i];
        tot[i] = (LL)(a[i] + 1) * h[i] % MOD;
    }
    REP(i, n) modAdd(ans, tot[i]);
    printf("%d\n", ans);
    return 0;
}