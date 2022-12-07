#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[25][25];

bool check(int i) {
    forn(j, m) if (a[i][j] != j + 1) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    forn(i, n) forn(j, m) cin >> a[i][j];
    bool ok = true;
    forn(i, n) {
        if (check(i)) continue;
        bool cur = false;
        forn(j, m) forn(k, j) {
            swap(a[i][j], a[i][k]);
            if (check(i)) {
                cur = true;
                swap(a[i][j], a[i][k]);
                break;
            }
            swap(a[i][j], a[i][k]);
        }
        if (!cur) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES" << endl;
        return 0;
    }
    forn(x, m) forn(y, x) {
        bool ok = true;
        forn(i, n) {
            swap(a[i][x], a[i][y]);
            if (check(i)) {
                swap(a[i][x], a[i][y]);
                continue;
            }
            bool cur = false;
            forn(j, m) forn(k, j) {
                swap(a[i][j], a[i][k]);
                if (check(i)) {
                    cur = true;
                    swap(a[i][j], a[i][k]);
                    break;
                }
                swap(a[i][j], a[i][k]);
            }
            swap(a[i][x], a[i][y]);
            if (cur) continue;

            forn(j, m) forn(k, j) {
                swap(a[i][j], a[i][k]);
                swap(a[i][x], a[i][y]);
                if (check(i)) {
                    cur = true;
                    swap(a[i][x], a[i][y]);
                    swap(a[i][j], a[i][k]);
                    break;
                }
                swap(a[i][x], a[i][y]);
                swap(a[i][j], a[i][k]);
            }

            if (!cur) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}