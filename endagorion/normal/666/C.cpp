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

const int K = 300;
const int maxn = 100000;
const i64 P = 1000000000 + 7;
i64 sm[K + 1][maxn + 1];
i64 l[maxn + 1];
i64 d_26[maxn + 1], d26[maxn + 1], d25[maxn + 1], fact[maxn + 1], tcaf[maxn + 1];

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

i64 cnk(int n, int k) {
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

int k;

void recount() {
    if (k <= K) return;
    forn(i, maxn + 1) l[i] = 0;
    for (int i = k; i <= maxn; ++i) {
        l[i] = (l[i - 1] + d_26[i] * d25[i - k] % P * cnk(i - 1, k - 1)) % P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = tcaf[0] = d25[0] = d_26[0] = d26[0] = 1;
    for1(i, maxn) {
        fact[i] = i * fact[i - 1] % P;
        tcaf[i] = deg(fact[i], -1);
        d25[i] = d25[i - 1] * 25 % P;
        d_26[i] = d_26[i - 1] * deg(26, -1) % P;
        d26[i] = d26[i - 1] * 26 % P;
    }

    for1(k, K) for (int i = k; i <= maxn; ++i) {             
        sm[k][i] = (sm[k][i - 1] + d_26[i] * d25[i - k] % P * cnk(i - 1, k - 1)) % P;
    }

    int m;
    string s;
    cin >> m >> s;
    k = s.size();
    recount();
    forn(i, m) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> s;
            k = s.size();
            recount();
        } else {
            int n;
            cin >> n;
            cout << d26[n] * (k <= K ? sm[k][n] : l[n]) % P << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}