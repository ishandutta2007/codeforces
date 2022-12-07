#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int m, n;
char buf[1005];
int c[1005][1005];
int d[1005];

void init() {
    forn(i, 1005) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 1005; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 1005; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    d[0] = 1;
    for (int i = 1; i < 1005; ++i) {
        d[i] = 0;
        forn(j, i) {
            d[i] = (d[i] + (LL)d[i - 1 - j] * c[i - 1][j]) % MOD;
        }
    }
}

LL b[1005];

int main() {
    init();
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    forn(i, n) {
        scanf("%s", buf);
        forn(j, m) if (buf[j] == '1') {
            b[j] ^= 1ll << i;
        }
    }
    sort(b, b + m);
    int ans = 1;
    for (int beg = 0; beg < m; ) {
        int end = beg + 1;
        while (end < m && b[beg] == b[end]) ++end;
        int cnt = end - beg;
        ans = (LL)ans * d[cnt] % MOD;
        beg = end;
    }
    cout << ans << endl;
    return 0;
}