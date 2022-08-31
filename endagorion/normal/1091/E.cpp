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
    ++n;
    vi64 a(n - 1);
    i64 s = 0;
    forn(i, n - 1) cin >> a[i], s += a[i];

    a.pb(1e9);
    a.pb(-1);
    sort(rall(a));
    int i = 0;
    vi64 ps(n + 1);
    for1(i, n) ps[i] = ps[i - 1] + a[i];
    vi64 minsuf(n + 1);
    minsuf[n] = 1e18;

    {
        multiset<i64> as;
        i64 asum = 0, z = 0;
        for (int k = n - 1; k >= 0; --k) {
            while (!as.empty()) {
                i64 y = *as.rbegin();
                if (y >= k + 1) {
                    asum -= y;
                    as.erase(as.find(y));
                    ++z;
                } else break;
            }
            minsuf[k] = min(minsuf[k + 1], -ps[k] + asum + z * (k + 1) + 1LL * k * (k + 1));
            as.insert(a[k]);
            asum += a[k];
        }
    }

    vi64 vals(n + 1);
    {
        multiset<i64> as;
        i64 asum = 0, z = 0;
        for (int k = n - 1; k >= 1; --k) {
            while (!as.empty()) {
                i64 y = *as.rbegin();
                if (y >= k) {
                    asum -= y;
                    as.erase(as.find(y));
                    ++z;
                } else break;
            }
            vals[k] = ps[k] - asum - z * k - 1LL * k * (k - 1);
            as.insert(a[k]);
            asum += a[k];
        }
    }

    i64 D = n - 1;
    if ((D + s) % 2) --D;

    int k = 0;
    i64 LB = -1e18;
    vi64 ans;
    for (; D >= 0; D -= 2) {
        while (a[k + 1] > D) {
            ++k;
//            cerr << k << ' ' << vals[k] << '\n';
            if (k < vals[k]) LB = 1e18;
            else uax(LB, vals[k]);
        }

//        cerr << D << ' ' << k << ' ' << LB << ' ' << minsuf[k] << '\n';
        if (D >= LB && D <= minsuf[k]) ans.pb(D);
    }
    sort(all(ans));
    if (ans.empty()) ans.pb(-1);
    for (i64 x: ans) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}