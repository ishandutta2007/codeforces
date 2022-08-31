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

const int maxn = 51000;
int n, st, x;
int ord[maxn], a[maxn], nxt[maxn];
void init(int n) {
    forn(i, n) ord[i] = i;
    random_shuffle(ord, ord + n);
    forn(i, n) a[ord[i]] = 2 * i + 1;
    forn(i, n - 1) nxt[ord[i]] = ord[i + 1] + 1;
    nxt[ord[n - 1]] = -1;
    st = ord[0];
    x = n;
}

int qs = 0;

pii query(int i) {
//    cerr << i << '\n';
    ++qs;
    if (i == -1) return {-1, -1};
//    return {a[i - 1], nxt[i - 1]};
    cout << "? " << i << endl;
    int val, nxt;
    cin >> val >> nxt;
    return {val, nxt};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n >> st >> x;
    srand(time(0));
//    cin >> n;
//    init(n);
    vector<pii> q = {{query(st).fi, st}};
    forn(i, 1000) {
        int p = 0;
        forn(j, 3) p = (p * (i64(RAND_MAX) + 1) + rand()) % n;
        ++p;
        q.pb({query(p).fi, p});
    }
    int i = 0;
    sort(all(q));
    while (i + 1 < q.size() && q[i + 1].fi < x) ++i;
    int j = q[i].se;
    while (j != -1) {
        pii p = query(j);
        if (p.fi >= x) break;
        j = p.se;
    }
    int ans = query(j).fi;
    cout << "! " << ans << '\n';
//    cerr << qs << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}