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

double dist(pii a, pii b) {
    return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int N, M;

bool iscor(pii a) {
    return a.first >= 0 && a.first <= N && a.second >= 0 && a.second <= M;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<pii> tr;
    for (int i = 0; i <= N; i += N - 2) {
        for (int j = 0; j <= M; j += M - 2) {
            forn(ii, 3) forn(jj, 3) {
                pii a = mp(i + ii, j + jj);
                if (iscor(a)) tr.pb(a);
            }
            if (M <= 2) break;
        }
        if (N <= 2) break;
    }
    sort(all(tr));
    tr.erase(unique(all(tr)), tr.end());
    double best = -1.0;
    vi a(4, -1);
    forn(i0, tr.size()) forn(i1, tr.size()) forn(i2, tr.size()) forn(i3, tr.size()) {
        set<int> s;
        s.insert(i0);
        s.insert(i1);
        s.insert(i2);
        s.insert(i3);
        if (s.size() != 4) continue;
        double d = dist(tr[i0], tr[i1]) + dist(tr[i1], tr[i2]) + dist(tr[i2], tr[i3]);
        if (d > best) {
            best = d;
            a.clear();
            a.pb(i0);
            a.pb(i1);
            a.pb(i2);
            a.pb(i3);
        }
    }
    forn(i, 4) {
        cout << tr[a[i]].first << ' ' << tr[a[i]].second << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}