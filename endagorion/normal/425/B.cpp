#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int a[101][101];
int p[101][101];

int N, M, K;

int basedx(int i) {
    int res = 0;
    forn(x, N) {
        int r = 0;
        forn(y, M) {
            if (a[i][y] == a[x][y]) ++r;
        }
        res += min(r, M - r);
    }
    return res;
}

int basedy(int j) {
    int res = 0;
    forn(y, M) {
        int r = 0;
        forn(x, N) {
            if (a[x][y] == a[x][j]) ++ r;
        }
        res += min(r, N - r);
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> N >> M >> K;
    forn(i, N) forn(j, M) cin >> a[i][j];
    int ans = 1e9;
    if (N <= 5 && M <= 5) {
        int b[5];
        forn(i, M) {
            b[i] = a[0][i];
        }
        forn(m, (1 << M)) {
            int r = 0;
            forn(i, M) {
                a[0][i] = (m >> i) & 1;
                if (a[0][i] != b[i]) {
                    ++r;
                }
            }
            r += basedx(0);
            ans = min(ans, r);
        }
        cout << (ans <= K ? ans : -1) << '\n';
        return 0;
    }
    if (N > 5) {
        forn(i, N) {
            ans = min(ans, basedx(i));
            forn(j, M) {
                a[i][j] ^= 1;
                ans = min(ans, basedx(i) + 1);
                a[i][j] ^= 1;
            }
        }
    } else if (M > 5) {
        forn(j, M) {
            ans = min(ans, basedy(j));
            forn(i, N) {
                a[i][j] ^= 1;
                ans = min(ans, basedy(j) + 1);
                a[i][j] ^= 1;
            }
        }
    }
    cout << (ans <= K ? ans : -1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}