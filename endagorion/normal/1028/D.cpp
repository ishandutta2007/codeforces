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

const i64 P = 1000000000 + 7;

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
    set<int> l, m, r;
    i64 ans = 1;
    forn(i, n) {
        string s;
        int p;
        cin >> s >> p;
        if (s == "ADD") {
            if (!l.empty() && p < *--l.end()) l.insert(p);
            else if (!r.empty() && p > *r.begin()) r.insert(p);
            else m.insert(p);
        } else {
            if (l.count(p)) {
                if (p != *--l.end()) {
                    ans = 0;
                    break;
                }
                l.erase(p);
                for (int x: m) r.insert(x);
                m.clear();
            } else if (r.count(p)) {
                if (p != *r.begin()) {
                    ans = 0;
                    break;
                }
                r.erase(p);
                for (int x: m) l.insert(x);
                m.clear();
            } else {
                (ans *= 2) %= P;
                m.erase(p);
                for (int x: m) (x < p ? l : r).insert(x);
                m.clear();
            }
        }
    }

    (ans *= i64(m.size() + 1)) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}