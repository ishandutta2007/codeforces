#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[1005];
int a[2005][2005], b[2005][2005] = {};
int hor[4][2005][2005] = {}, ver[4][2005][2005];
PII ans = mp(0, 0);
const long double RAT = log((long double) 3) / log((long double) 2);
const int MOD = 1e9 + 7;

PII cmp(int a, int b, int c, int d) {
    if (a >= c && b >= d) return mp(a, b);
    if (a <= c && b <= d) return mp(c, d);
    if (a < c) {
        swap(a, c);
        swap(b, d);
    }
    if (RAT * (d - b) < a - c) return mp(a, b);
    return mp(c, d);
}

void solve() {
    REP(z, 4) if (z != 1) REP(i, n) REP(j, n) {
        hor[z][i][j + 1] = hor[z][i][j] + (a[i][j] == z);
        ver[z][i + 1][j] = ver[z][i][j] + (a[i][j] == z);
    }
    REP(i, n) REP(j, n) if (a[i][j] != 0 && a[i][j] != -1) {
        int lo = 0, mid, hi = min(min(i, n - 1 - i), min(j, n - 1 - j));
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (hor[0][i][j + mid + 1] - hor[0][i][j - mid] > 0 || ver[0][i + mid + 1][j] - ver[0][i - mid][j] > 0) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        int c = hor[2][i][j + lo + 1] - hor[2][i][j - lo] + ver[2][i + lo + 1][j] - ver[2][i - lo][j] - (a[i][j] == 2);
        int d = hor[3][i][j + lo + 1] - hor[3][i][j - lo] + ver[3][i + lo + 1][j] - ver[3][i - lo][j] - (a[i][j] == 3);
        ans = cmp(ans.first, ans.second, c, d);
    }
}

void rot() {
    memset(b, -1, sizeof b);
    int o = (n + 1) % 2;
    REP(i, 2 * n - 1) REP(j, 2 * n - 1) if (((i + j) & 1) == o) {
        b[i][j] = 0;
    }
    REP(i, n) REP(j, n) {
        b[n - 1 + i - j][i + j] = a[i][j];
    }
    memcpy(a, b, sizeof a);
    n = 2 * n - 1;
//    REP(i, n) {
//        REP(j, n) if (a[i][j] != -1) cout << a[i][j];
//        else cout << "-";
//        cout << endl;
//    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        REP(j, n) a[i][j] = buf[j] - '0';
    }
    bool ok = false;
    REP(i, n) REP(j, n) if (a[i][j]) ok = true;
    if (!ok) {
        printf("0\n");
        return 0;
    }
    solve();
    rot();
    solve();
    int res = 1;
    REP(i, ans.first) res = 2ll * res % MOD;
    REP(i, ans.second) res = 3ll * res % MOD;
    printf("%d\n", res);
    return 0;
}