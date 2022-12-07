#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;

int n;
char s[5005];
int d[5005][5005] = {};
int ls[5005][5005] = {}, eq[5005][5005] = {};

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

inline void modSub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%s", &n, s);
    //n = 5000;
    //REP(i, n) s[i] = rand() % 10 + '0';
    //if (s[0] == '0') s[0] = '1';
    REP(i, n) REP(j, n) {
        if (s[i] < s[j]) ls[i][j] |= 1;
        if (s[i] == s[j]) eq[i][j] |= 1;
    }
    REP(z, 12) {
        int tot = n - (2 << z) + 1;
        REP(i, tot) REP(j, tot) {
            if ((ls[i][j] & (1 << z)) || ((eq[i][j] & (1 << z)) && (ls[i + (1 << z)][j + (1 << z)] & (1 << z)))) {
                ls[i][j] |= 1 << (z + 1);
            }
            if ((eq[i][j] & (1 << z)) && (eq[i + (1 << z)][j + (1 << z)] & (1 << z))) {
                eq[i][j] |= 1 << (z + 1);
            }
        }
    }
    REP(i, n) d[0][i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == '0') {
                d[i][j] = d[i - 1][j];
                continue;
            }
            int len = j - i + 1;
            int ind = i - len;
            if (ind >= 0) {
                int rem = len;
                int jnd = i;
                bool ok = false;
                for (int z = 12; z >= 0; --z) if ((1 << z) <= rem) {
                    if (ls[ind][jnd] & (1 << z)) {
                        ok = true;
                        break;
                    } else if (!(eq[ind][jnd] & (1 << z))) {
                        break;
                    }
                    ind += 1 << z;
                    jnd += 1 << z;
                    rem -= 1 << z;
                }
                if (ok) {
                    d[i][j] = d[i - len][i - 1];
                    if (i - len) modSub(d[i][j], d[i - len - 1][i - 1]);
                }
            }
            int from = max(0, i - len + 1);
            modAdd(d[i][j], d[i - 1][i - 1]);
            if (from) modSub(d[i][j], d[from - 1][i - 1]);
            modAdd(d[i][j], d[i - 1][j]);
        }
    }
    printf("%d\n", d[n - 1][n - 1]);
    return 0;
}