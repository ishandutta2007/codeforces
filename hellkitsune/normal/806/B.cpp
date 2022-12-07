#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 8;

int n;
int a[120][5];
int b[5];

int vec[5], svec[5];

void solve(int mid) {
    forn(i, 5) {
        int p = b[i];
        int q = n + mid;
        if (a[0][i] != -1 && (a[1][i] != -1 && a[1][i] < a[0][i])) {
            p += mid;
        }
        for (int j = 1; j <= 6; ++j) {
            int from = 1 << j;
            int to = from >> 1;
            bool can = false;
            if (j < 6) {
                if ((LL)p * from > q && (LL)p * to <= q) {
                    can = true;
                }
            } else {
                if ((LL)p * to <= q) {
                    can = true;
                }
            }
            if (can) {
                vec[i] = j;
                break;
            }
        }
    }
}

bool calc() {
    LL bal = 0;
    forn(i, 5) {
        int cur = 0;
        int j = vec[i];
        if (a[1][i] != -1 || a[0][i] != -1) {
            if (a[1][i] == -1) {
                cur = 2 * j * (250 - a[0][i]);
            } else if (a[0][i] == -1) {
                cur = 2 * j * (-250 + a[1][i]);
            } else {
                cur = 2 * j * (a[1][i] - a[0][i]);
            }
        } else {
            cur = 0;
        }
        bal += cur;
    }
    return bal > 0;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) forn(j, 5) scanf("%d", a[i] + j);
    forn(i, n) forn(j, 5) {
        if (a[i][j] != -1) {
            ++b[j];
        }
    }
    solve(0);
    if (calc()) {
        cout << 0 << endl;
        return 0;
    }
    forn(i, 5) svec[i] = vec[i];
    int pre = 0;
    while (true) {
        int lo = pre + 1, hi = INF, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            solve(mid);
            bool changed = false;
            forn(i, 5) if (svec[i] != vec[i]) {
                changed = true;
            }
            if (changed) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo == INF) {
            break;
        }
        pre = lo;
        solve(lo);
        forn(i, 5) svec[i] = vec[i];
        if (calc()) {
            cout << pre << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}