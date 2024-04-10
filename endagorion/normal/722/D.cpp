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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vi norm(vi a, int T) {
    int n = a.size();
    forn(i, n) {
        while (a[i] > T) a[i] /= 2;
    }
    map<int, vi> cnt;
    forn(i, n) cnt[a[i]].pb(i);
    while (!cnt.empty() && cnt.rbegin()->fi) {
        vi p = cnt.rbegin()->se;
        p.pop_back();
        for (int x: p) {
            a[x] /= 2;
            cnt[a[x]].pb(x);
        }
        cnt.erase(--cnt.end());
    }
    if (cnt.empty()) return a;
    return vi();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    int L = 0, R = 2e9;
    while (R - L > 1) {
        int T = L + (R - L) / 2;
        vi b = norm(a, T);
        (b.empty() ? L : R) = T;
    }
    vi b = norm(a, R);
    for (int x: b) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}