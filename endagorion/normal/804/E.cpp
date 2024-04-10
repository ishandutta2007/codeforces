#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
#define mt make_tuple
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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vector<pii> ans4 = {{0, 1}, {0, 2}, {1, 3}, {0, 3}, {1, 2}, {2, 3}};
vector<pii> ans5 = {{0, 1},
{0, 2},
{0, 3},
{1, 2},
{1, 4},
{2, 4},
{0, 4},
{2, 3},
{1, 3},
{3, 4}};
int sh44[] = {0, 3, 1, 2};
vector<pii> ans44;
vector<pii> ans45;

vector<pii> ans;

void sh(vi v, vector<pii> p) {
    for (pii q: p) ans.pb({v[q.fi], v[q.se]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, 4) forn(j, 4) ans44.pb({j, 4 + (j + sh44[i]) % 4});

    int n;
    cin >> n;
    int m = n % 4;
    if (m != 0 && m != 1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n - 1; i += 4) {
        vi v;
        forn(j, 4) v.pb(i + j);
        if (n % 4) v.pb(n - 1);
        sh(v, n % 4 ? ans5 : ans4);
        for (int j = 0; j < i; j += 4) {
            vi u;
            forn(k, 4) u.pb(i + k);
            forn(k, 4) u.pb(j + k);
            sh(u, ans44);
        }
    }

    cout << "YES\n";
    for (pii p: ans) {
        if (p.fi > p.se) swap(p.fi, p.se);
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }

/*    vi a(n);
    forn(i, n) a[i] = i;
    vi c = a;
    for (pii p: ans) {
        assert(p.fi != p.se);
        swap(a[p.fi], a[p.se]);
    }
    assert(set<pii>(all(ans)).size() == n * (n - 1) / 2);
    assert(a == c);*/

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}