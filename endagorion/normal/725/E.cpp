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

const int maxn = 210000;
int cnt[maxn], cl[maxn], ncl[maxn];

int z;

int eval_cl(int x) {
    if (ncl[x] == -1) return z;
    return ncl[x];
}

bool emul(int c) {
    int r = c;
    while (c) {
        r = eval_cl(min(c, r));
        if (!r) return false;
        int d = min(cnt[r], c / r);
        c -= d * r;
        --r;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int c, n;
    cin >> c >> n;
    forn(i, n) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for1(i, c) cl[i] = (cnt[i] ? i : cl[i - 1]);
    forn(i, c + 1) ncl[i] = cl[i];
    for1(i, c) {
        z = i;
        if (!cnt[i] && ncl[i] != -1) {
            for (int j = i; j <= c && !cnt[j]; ++j) ncl[j] = -1;
        }

        ++cnt[i];
        if (!emul(c)) {
            cout << i << '\n';
            return 0;
        }
        --cnt[i];
        if (ncl[i] == -1) ncl[i] = cl[i];
    }
    cout << "Greed is good\n";


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}