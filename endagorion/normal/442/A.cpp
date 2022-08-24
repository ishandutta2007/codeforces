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

int a[5][5];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string c = "RGBYW", d = "12345";
    forn(i, N) {
        string s;
        cin >> s;
        int p1, p2;
        forn(j, 5) {
            if (s[0] == c[j]) p1 = j;
            if (s[1] == d[j]) p2 = j;
        }
        a[p1][p2] = 1;
    }
    int ans = 100;
    forn(m1, 1 << 5) {
        forn(m2, 1 << 5) {
            bool ok = true;
            forn(i1, 5) forn(j1, 5) 
                forn(i2, 5) forn(j2, 5) {
                    if (i1 == i2 && j1 == j2) continue;
                    if (!a[i1][j1] || !a[i2][j2]) continue;
                    bool diff = false;
                    if (i1 != i2 && (((m1 >> i1) | (m1 >> i2)) & 1)) diff = true;
                    if (j1 != j2 && (((m2 >> j1) | (m2 >> j2)) & 1)) diff = true;
                    if (!diff) ok = false;
                }
            if (ok) {
                int res = 0;
                forn(i, 5) {
                    res += ((m1 >> i) & 1);
                    res += ((m2 >> i) & 1);
                }
                ans = min(ans, res);
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}