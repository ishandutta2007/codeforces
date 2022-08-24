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

const int maxq = 100001;
const int bord = 500;

vi xs[maxq];

bool exists(int x, int y) {
    if (x >= maxq) return false;
    return binary_search(all(xs[x]), y);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    forn(i, N) {
        int x, y;
        scanf("%d%d", &x, &y);
        xs[x].pb(y);
    }
    forn(i, maxq) {
        sort(all(xs[i]));
    }

    i64 ans = 0;
    forn(x, maxq) {
        if (xs[x].size() < bord) {
            forn(i, xs[x].size()) {
                for (int j = i + 1; j < xs[x].size(); ++j) {
                    int d = xs[x][j] - xs[x][i];
                    if (exists(x + d, xs[x][i]) && exists(x + d, xs[x][j])) {
                        ++ans;
                    }
                }
            }
        } else {
            for (int xx = x + 1; xx < maxq; ++xx) {
                forn(i, xs[xx].size()) {
                    int yy = xs[xx][i];
                    int d = xx - x;
                    if (exists(x, yy) && exists(x, yy + d) && exists(xx, yy + d)) {
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}