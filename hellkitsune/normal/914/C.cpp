#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int c[1005][1005];

int n, k;
int a[1005];
char buf[10005];

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
}

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int d[1005];

int main() {
    init();

    scanf("%s%d", buf, &k);
    n = strlen(buf);
    forn(i, n) a[i] = buf[i] - '0';

    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1) {
        cout << n - 1 << endl;
        return 0;
    }

    d[1] = 0;
    for (int i = 2; i < 1005; ++i) {
        d[i] = d[__builtin_popcount(i)] + 1;
    }

    int ans = 0;
    int cnt = 0;
    forn(i, n) if (a[i] == 1) {
        int rem = n - 1 - i;
        for (int j = 0; j <= rem; ++j) {
            if (cnt + j != 0 && d[cnt + j] + 1 == k) {
                modAdd(ans, c[rem][j]);
            }
        }
        ++cnt;
    }
    if (d[cnt] + 1 == k) {
        modAdd(ans, 1);
    }

    cout << ans << endl;
    return 0;
}