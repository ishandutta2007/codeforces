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
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

void solveQ(ld a, ld b, ld c, ld &x1, ld &x2) {
    ld D = sqrt(max((ld)0.0, b * b - 4 * a * c));
    x1 = (-b + D) * 0.5;
    x2 = (-b - D) * 0.5;
}

const int maxn = 110000;
ld minp[maxn], maxp[maxn], p1[maxn], p2[maxn];
ld pminp[maxn];

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
    forn(i, n) cin >> maxp[i];
    forn(i, n) cin >> minp[i];
    ford(i, n) pminp[i] = pminp[i + 1] + minp[i];
    ld s = 0, t = 1;
    ld s1 = 0.0, s2 = 0.0;
    forn(i, n) {
        s += maxp[i];
//        t = pminp[i + 1];
        t -= minp[i];
        ld ns1, ns2;
        solveQ(1.0, t - 1.0 - s, s, ns1, ns2);
        if (ns1 < ns2) swap(ns1, ns2);
        p1[i] = ns1 - s1;
        p2[i] = ns2 - s2;
        s1 = ns1; s2 = ns2;
    }
    forn(i, n) cout << (double)p1[i] << ' ';
    cout << '\n';
    forn(i, n) cout << (double)p2[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}