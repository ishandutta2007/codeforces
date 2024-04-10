#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> a[100000], b[100000];
int p[16];
int bad[16][16];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        a[i].resize(m);
        b[i].resize(m);
    }
    forn(i, n) forn(j, m) {
        a[i][j] = i * m + j;
    }
    bool ok = false;
    if (n >= 4) {
        int cnt = 0;
        for (int i = 1; i < n; i += 2) {
            forn(j, m) b[cnt][j] = a[i][j];
            ++cnt;
        }
        for (int i = 0; i < n; i += 2) {
            forn(j, m) b[cnt][j] = a[i][j];
            ++cnt;
        }
        if (n % 2 == 0) {
            for (int i = 1; i < m; i += 2) {
                forn(j, n / 2) swap(b[j][i], b[n - 1 - j][i]);
            }
        } else {
            for (int i = 1; i < m; i += 2) {
                int rem = b[0][i];
                forn(j, n - 1) b[j][i] = b[j + 1][i];
                b[n - 1][i] = rem;
            }
        }
        ok = true;
    } else if (m >= 4) {
        int cnt = 0;
        for (int i = 1; i < m; i += 2) {
            forn(j, n) b[j][cnt] = a[j][i];
            ++cnt;
        }
        for (int i = 0; i < m; i += 2) {
            forn(j, n) b[j][cnt] = a[j][i];
            ++cnt;
        }
        if (m % 2 == 0) {
            for (int i = 1; i < n; i += 2) {
                forn(j, m / 2) swap(b[i][j], b[i][m - 1 - j]);
            }
        } else {
            for (int i = 1; i < n; i += 2) {
                int rem = b[i][0];
                forn(j, m - 1) b[i][j] = b[i][j + 1];
                b[i][m - 1] = rem;
            }
        }
        ok = true;
    } else {
        forn(i, n) forn(j, m - 1) bad[a[i][j]][a[i][j + 1]] = true;
        forn(i, n) forn(j, m - 1) bad[a[i][j + 1]][a[i][j]] = true;
        forn(i, n - 1) forn(j, m) bad[a[i][j]][a[i + 1][j]] = true;
        forn(i, n - 1) forn(j, m) bad[a[i + 1][j]][a[i][j]] = true;
        int sz = n * m;
        forn(i, sz) p[i] = i;
        do {
            forn(i, n) forn(j, m) b[i][j] = p[a[i][j]];
            ok = true;
            forn(i, n) forn(j, m - 1) if (bad[b[i][j]][b[i][j + 1]]) {
                ok = false;
            }
            forn(i, n - 1) forn(j, m) if (bad[b[i][j]][b[i + 1][j]]) {
                ok = false;
            }
            if (ok) {
                break;
            }
        } while (next_permutation(p, p + sz));
    }
    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    forn(i, n) {
        forn(j, m) printf("%d ", b[i][j] + 1);
        printf("\n");
    }
    return 0;
}