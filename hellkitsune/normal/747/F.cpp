#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(2e9) + 111;

int k, t;
int can[16];
int len;

int d[200];

int c[200][20];
void init() {
    forn(i, 20) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 200; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 20; ++j) {
            c[i][j] = min(INF, (LL)c[i - 1][j - 1] + c[i - 1][j]);
        }
    }
}

int solve() {
    memset(d, 0, sizeof d);
    d[0] = 1;
    forn(i, 16) {
        for (int j = len; j >= 0; --j) {
            if (d[j] == 0) {
                continue;
            }
            for (int k = 1; k <= can[i]; ++k) {
                d[j + k] = min(INF, d[j + k] + (LL)d[j] * c[j + k][k]);
            }
        }
    }
    return d[len];
}

char getChar(int val) {
    if (val < 10) {
        return char('0' + val);
    }
    return char('a' + (val - 10));
}

char ans[200];

void solve(int len, int dig) {
    ans[0] = getChar(dig);
    for (int i = 1; i < len; ++i) {
        forn(j, 16) if (can[j]) {
            --can[j];
            ::len = len - 1 - i;
            int cnt = solve();
            if (cnt >= k) {
                ans[i] = getChar(j);
                break;
            }
            ++can[j];
            k -= cnt;
        }
    }
    ans[len] = '\0';
    printf("%s\n", ans);
}

int main() {
    //freopen("input.txt", "r", stdin);
    init();
    scanf("%d%d", &k, &t);
    forn(i, 16) {
        can[i] = t;
    }
    for (int i = 0; ; ++i) {
        for (int j = 1; j < 16; ++j) {
            --can[j];
            len = i;
            int cnt = solve();
            if (cnt >= k) {
                solve(i + 1, j);
                return 0;
            }
            ++can[j];
            k -= cnt;
        }
    }
    assert(false);
    return 0;
}