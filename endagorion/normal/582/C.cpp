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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    scanf("%d", &N);
    vi a(N);
    forn(i, N) scanf("%d", &a[i]);
    vi divs;
    vvi byd;
    vvi dd;
    map<int, int> en;
    for1(k, N) {
        if (N % k) continue;
        en[k] = divs.size();
        divs.pb(k);
        vi d(N);
        forn(i, k) {
            int mx = 0;
            forn(j, N / k) uax(mx, a[i + j * k]);
            forn(j, N / k) if (a[i + j * k] == mx) d[i + j * k] = 1;
        }
        dd.pb(d);
    }
    byd.resize(divs.size());
    for1(k, N - 1) byd[en[gcd(k, N)]].pb(k);
    i64 ans = 0;
    forn(i, divs.size()) {
        if (*min_element(all(dd[i])) == 1) {
            ans += 1LL * N * byd[i].size();
            continue;
        }
        vi res(N + 1);
        int l = 0;
        int q = 0;
        for1(j, N) {
            if (l < byd[i].size() && byd[i][l] == j) ++q, ++l;
            res[j] = q;
        }
        if (dd[i][0]) {
            l = 1;
            ford(x, N) {
                if (dd[i][x]) ++l;
                else break;
            }
        } else l = 0;
        forn(j, N) {
            ans += res[l];
            if (!dd[i][(j + 1) % N]) l = 0;
            else ++l;
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}