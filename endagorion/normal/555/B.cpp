#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 210000;
i64 l[MAXN], r[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    forn(i, N) cin >> l[i] >> r[i];
    vi ans(N - 1, -1);
    vector< pair<i64, int> > ev;
    forn(i, N - 1) ev.pb(mp(l[i + 1] - r[i], -i - 1)), ev.pb(mp(r[i + 1] - l[i], i + M));
    forn(i, M) {
        i64 x;
        cin >> x;
        ev.pb(mp(x, i));
    }
    sort(all(ev));
    set< pair<i64, int> > s;
    for (auto p: ev) {
        int id = p.se;
        if (id < 0) {
            id = -id - 1;
            s.insert(mp(r[id + 1] - l[id], id));
        } else if (id < M) {
            auto it = s.lower_bound(mp(p.fi, 0));
            if (it != s.end()) {
                ans[it->se] = id;
                s.erase(it);
            }
        } else {
            id -= M;
            s.erase(mp(r[id + 1] - l[id], id));
        }
    }
    if (*min_element(all(ans)) < 0) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int x: ans) cout << x + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}