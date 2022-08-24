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
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXT = 500001;
int mu[MAXT + 1], q[MAXT + 1];
vi divs[MAXT + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, MAXT) {
        for (int j = i; j <= MAXT; j += i) divs[j].pb(i);
    }

    for1(i, MAXT) {
        int z = i;
        mu[i] = 1;
        for (int d: divs[i]) {
            if (d == 1) continue;
            if (z % d == 0) {
                z /= d;
                mu[i] = -mu[i];
                if (z % d == 0) {
                    mu[i] = 0;
                    break;
                }
            }
        }
    }

    int N, Q;
    cin >> N >> Q;
    vi a(N), t(N);
    forn(i, N) cin >> a[i];
    i64 total = 0;
    forn(z, Q) {
        int x;
        cin >> x;
        --x;
        int y = (t[x] ? -1 : 1);
        t[x] ^= 1;
        for (int d: divs[a[x]]) {
            total -= 1LL * mu[d] * q[d] * (q[d] - 1) / 2;
            q[d] += y;
            total += 1LL * mu[d] * q[d] * (q[d] - 1) / 2;
        }
        cout << total << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}