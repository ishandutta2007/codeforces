#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, k;
int a[200];
int d[101][51001], nd[101][51001];

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);

//    n = 200;
//    k = 1000;
//    forn(i, n) {
//        a[i] = 500;
//    }

    sort(a, a + n, greater<int>());
    d[0][0] = 1;
    forn(pos, n) {
        memset(nd, 0, sizeof nd);
        int val = a[pos];
        int mn = 0, mx = k;
        forn(i, min(pos + 1, n - pos + 1)) {
            if (i > 0) {
                mn += a[pos - i];
                mx += a[pos + i - 1];
            }
            for (int j = mn; j <= mx; ++j) if (d[i][j]) {
                nd[i][j] = (nd[i][j] + (LL)d[i][j] * (i + 1)) % MOD;
                if (i < 100 && j + val < 51001) {
                    modAdd(nd[i + 1][j + val], d[i][j]);
                }
                if (i > 0) {
                    modAdd(nd[i - 1][j - val], (LL)d[i][j] * i % MOD);
                }
            }
        }
        memcpy(d, nd, sizeof d);
    }
    int ans = 0;
    forn(i, k + 1) {
        modAdd(ans, d[0][i]);
    }
    cout << ans << endl;
    return 0;
}