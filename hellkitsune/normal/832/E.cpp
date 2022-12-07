#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

char s[505];
int n, m, q;
int a[500][500];
int inv[5] = {0, 1, 3, 2, 4};
int b[500];
int can[500];

int pre() {
    memset(can, -1, sizeof can);
    int row = 0;
    forn(col, m) {
        bool found = false;
        for (int i = row; i < n; ++i) if (a[i][col] != 0) {
            forn(j, m) swap(a[i][j], a[row][j]);
            found = true;
            break;
        }
        if (!found) {
            continue;
        }
        can[col] = row;
        int mul = inv[a[row][col]];
        forn(j, m) {
            a[row][j] = mul * a[row][j] % 5;
        }
        forn(i, n) if (i != row && a[i][col] > 0) {
            mul = 5 - a[i][col];
            forn(j, m) {
                a[i][j] = (a[i][j] + mul * a[row][j]) % 5;
            }
        }
        if (++row == n) {
            break;
        }
    }
    int ans = 1;
    while (row != n) {
        ans = 5ll * ans % MOD;
        ++row;
    }
    return ans;
}

int solve() {
    forn(i, m) if (b[i] != 0 && can[i] != -1) {
        while (b[i] != 0) {
            forn(j, m) {
                b[j] += a[can[i]][j];
                if (b[j] >= 5) b[j] -= 5;
            }
        }
    }
    forn(i, m) if (b[i] != 0) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", s);
        forn(j, m) a[i][j] = s[j] - 'a';
    }
    scanf("%d", &q);
    int mul = pre();
    forn(i, q) {
        scanf("%s", s);
        forn(j, m) b[j] = s[j] - 'a';
        printf("%d\n", mul * solve());
    }
    return 0;
}