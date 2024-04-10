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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int p[30][100001];
int d[30][100001];

struct TEvent {
    int l, r, q;

    TEvent(int l = 0, int r = 0, int q = 0)
        : l(l)
        , r(r)
        , q(q)
    {
    }
};

vector<TEvent> evs[30];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    forn(i, M){
        int l, r, q;
        cin >> l >> r >> q;
        --l;
        forn(j, 30) {
            int x = (q >> j) & 1;
            evs[j].pb(TEvent(l, r, x));
            if (x == 1) {
                ++d[j][l];
                --d[j][r];
            }
        }
    }

    bool ok = true;
    forn(j, 30) {
        int b = 0;
        forn(i, N) {
            b += d[j][i];
            if (b) {
                p[j][i + 1] = p[j][i] + 1;
            } else {
                p[j][i + 1] = p[j][i];
            }
        }

        forn(i, evs[j].size()) {
            int s = p[j][evs[j][i].r] - p[j][evs[j][i].l];
            if ((s == evs[j][i].r - evs[j][i].l) != evs[j][i].q) ok = false;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    forn(i, N) {
        int x = 0;
        forn(j, 30) x += (p[j][i + 1] - p[j][i]) << j;
        cout << x << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}