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

i64 cost[1 << 20];

struct TPart {
    i64 a, b;
    int m;

    TPart(i64 a = 0, i64 b = 0, int m = 0)
        : a(a)
        , b(b)
        , m(m)
    {
    }

    bool operator<(const TPart &p) const {
        return b > p.b;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    i64 B;
    cin >> N >> M >> B;
    vector<TPart> a(N);
    forn(i, N) {
        int x;
        cin >> a[i].a >> a[i].b >> x;
        forn(j, x) {
            int y;
            cin >> y;
            a[i].m += 1 << (y - 1);
        }
    }
    forn(i, 1 << M) {
        cost[i] = 3e18;
    }
    sort(all(a));
    forn(i, N) {
        cost[0] = a[i].b * B;
        forn(j, 1 << M) {
            cost[j | a[i].m] = min(cost[j | a[i].m], cost[j] + a[i].a);
        }
    }
    if (cost[(1 << M) - 1] > 2e18) {
        cout << -1 << '\n';
    } else {
        cout << cost[(1 << M) - 1] << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}