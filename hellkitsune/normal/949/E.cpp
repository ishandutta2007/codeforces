#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool a[20][2][1 << 17];
int ans = 1234, ami, apl;

void solve(int ind, int mx, int mi, int pl, int res) {
    if (ind > 18) {
        return;
    }
    if (mx == 0) {
        if (res < ans) {
            ans = res;
            ami = mi;
            apl = pl;
        }
        return;
    }
    forn(j, 2) forn(i, mx + 1) {
        a[ind + 1][j][i] = false;
    }
    bool ok = true;
    forn(j, 2) for (int i = 1; i <= mx; i += 2) if (a[ind][j][i]) {
        ok = false;
    }
    int nmx = 0;
    if (ok) {
        forn(j, 2) forn(i, mx + 1) if (a[ind][j][i]) {
            int ni = i >> 1;
            if (ni != 0) {
                a[ind + 1][j][ni] = true;
                nmx = max(nmx, ni);
            }
        }
        solve(ind + 1, nmx, mi, pl, res);
    } else {
        forn(i, mx + 1) if (a[ind][0][i]) {
            int ni = i >> 1;
            if (ni != 0) {
                a[ind + 1][0][ni] = true;
                nmx = max(nmx, ni);
            }
        }
        forn(i, mx + 1) if (a[ind][1][i]) {
            int ni = i;
            if (ni & 1) {
                ++ni;
            }
            ni >>= 1;
            if (ni != 0) {
                a[ind + 1][1][ni] = true;
                nmx = max(nmx, ni);
            }
        }
        solve(ind + 1, nmx, mi, pl | (1 << ind), res + 1);

        nmx = 0;
        forn(j, 2) forn(i, mx + 1) {
            a[ind + 1][j][i] = false;
        }
        forn(i, mx + 1) if (a[ind][1][i]) {
            int ni = i >> 1;
            if (ni != 0) {
                a[ind + 1][1][ni] = true;
                nmx = max(nmx, ni);
            }
        }
        forn(i, mx + 1) if (a[ind][0][i]) {
            int ni = i;
            if (ni & 1) {
                ++ni;
            }
            ni >>= 1;
            if (ni != 0) {
                a[ind + 1][0][ni] = true;
                nmx = max(nmx, ni);
            }
        }
        solve(ind + 1, nmx, mi | (1 << ind), pl, res + 1);
    }
}

int main() {
    scanf("%d", &n);
    int mx = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (x > 0) {
            a[0][0][x] = true;
            mx = max(mx, x);
        }
        if (x < 0) {
            a[0][1][-x] = true;
            mx = max(mx, -x);
        }
    }
    solve(0, mx, 0, 0, 0);
    printf("%d\n", ans);
    forn(i, 20) if (apl & (1 << i)) {
        printf("%d ", 1 << i);
    } else if (ami & (1 << i)) {
        printf("%d ", -(1 << i));
    }
    return 0;
}