#include <iostream>
#include <tuple>
#include <sstream>
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

const int maxa = 200002;
vi occ[maxa];
vi divs[maxa];
int a[maxa], cnt[maxa];

i64 sum;
set<pair<int, int> > b;

void erase(set<pair<int, int> >::iterator it) {
    set<pair<int, int> >::iterator w1 = it, w2 = it;
    --w1; ++w2;
    sum -= 1LL * (it->fi - w1->fi) * (it->se - w2->se);
    b.erase(it);
}

void erase(int i, int d) {
    if (!b.count(mp(i, d))) return;
    erase(b.lower_bound(mp(i, d)));
}



void insert(int i, int d) {
    if (b.lower_bound(mp(i, d))->se >= d) return;
    while (1) {
        set<pair<int, int> >::iterator it = --b.lower_bound(mp(i, d));
        if (it->se <= d) erase(it);
        else break;
    }
    b.insert(mp(i, d));
    set<pair<int, int> >::iterator it = b.lower_bound(mp(i, d));
    set<pair<int, int> >::iterator w1 = it, w2 = it;
    --w1; ++w2;
    sum += 1LL * (it->fi - w1->fi) * (it->se - w2->se);
}

int val(int p) {
    return b.lower_bound(mp(p, 0))->se;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, maxa - 1) for (int j = i; j < maxa; j += i) divs[j].pb(i);

    int n;
    cin >> n;
    forn(i, n) cin >> a[i];
    for1(d, maxa - 1) occ[d].pb(n);
    ford(i, n) {
        for (int d: divs[a[i]]) {
            if (occ[d].size() == 3) continue;
            occ[d].pb(i);
        }
    }
    for1(i, maxa - 1) while (occ[i].size() < 3) occ[i].pb(-1);
    b.insert(mp(-1, maxa - 1));
    b.insert(mp(n + 1, 0));
    for1(i, maxa - 2) {
        int p = occ[i][2];
//        cerr << i << ' ' << p << '\n';
        insert(p, i);
    }
    i64 ans = 0;
    forn(i, n) {
/*        cerr << i << '\n';
        for (auto w: b) {
            cerr << w.fi << ' ' << w.se << '\n';
        }
        cerr << '\n';*/
        i64 v = sum - 1LL * (i + 1) * val(i);
        ans += v;
//        cerr << i << ' ' << v << '\n';
        for (int d: divs[a[i]]) {
            if (cnt[d] == 2) continue;
            erase(occ[d][2 - cnt[d]], d);
            ++cnt[d];
            insert(occ[d][2 - cnt[d]], d);
        }
        while (1) {
            auto it = b.lower_bound(mp(0, 0));
            if (it->first <= i) erase(it);
            else break;
        }
    }
    cout << ans << '\n';
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}