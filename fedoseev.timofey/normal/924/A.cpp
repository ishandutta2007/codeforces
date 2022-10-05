#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define REP(i, st, n) for (int i = (st); i < (n); ++i)

typedef long long ll;

template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) { if (y < x) x = y; };
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) { if (y > x) x = y; };

int n, m;
int a[51][51];

bool interrow(int x1, int x2) {
    for (int y = 0; y < m; ++y) {
        if (a[x1][y] == a[x2][y] && a[x1][y]) return true;
    }
    return false;
}
bool intercol(int y1, int y2) {
    for (int x = 0; x < n; ++x) {
        if (a[x][y1] == a[x][y2] && a[x][y1]) return true;
    }
    return false;
}


bool eqrow(int x1, int x2) {
    for (int y = 0; y < m; ++y) {
        if (a[x1][y] != a[x2][y]) return false;
    }
    return true;
}
bool eqcol(int y1, int y2) {
    for (int x = 0; x < n; ++x) {
        if (a[x][y1] != a[x][y2]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
#ifdef DEBUG
    freopen("A.in", "r", stdin);
#endif // DEBUG

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = (s[j] == '.' ? 0 : 1);
        }
    }

    bool ok = true;
    for (int x = 0; x < n - 1; ++x) {
        for (int x1 = x + 1; x1 < n; ++x1) {
            if (interrow(x, x1)) {
                ok &= eqrow(x, x1);
            }
        }
    }
    for (int y = 0; y < m - 1 ; ++y) {
        for (int y1 = y + 1; y1 < m; ++y1) {
            if (intercol(y, y1)) {
                ok &= eqcol(y, y1);
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}