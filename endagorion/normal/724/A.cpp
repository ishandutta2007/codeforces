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

string ss[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int getWN(string s) {
    forn(i, 7) {
        if (s == ss[i]) return i;
    }
    return -1;
}

int ms[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void nxt(int &d, int &dw, int &m) {
    ++d; ++dw; dw %= 7;
    if (d == ms[m]) d = 0, ++m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s, t;
    cin >> s >> t;
    int a = getWN(s), b = getWN(t);
    bool ok = false;
    forn(i, 7) {
        int d = 0, m = 0, dw = i;
        vi v;
        while (m < 12) {
            if (!d) v.pb(dw);//, cerr << dw << ' ';
            nxt(d, dw, m);
        }
//        cerr << '\n';
        forn(i, 11) ok |= v[i] == a && v[i + 1] == b;
    }
    cout << (ok ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}