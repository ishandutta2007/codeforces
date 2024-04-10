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

string sh[256][3];

bool better(string s, string t) {
    if (s.size() != t.size()) return s.size() < t.size();
    return s < t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int x = 0xF0, y = 0xCC, z = 0xAA;
    forn(i, 256) forn(j, 3) sh[i][j] = string(1000, '?');
    vector<vpi> q(10000);
    q[1] = {{x, 2}, {y, 2}, {z, 2}};
    sh[x][2] = "x";
    sh[y][2] = "y";
    sh[z][2] = "z";
    forn(l, 100) forn(i, q[l].size()) {
        auto w = q[l][i];
        int m = w.fi, s = w.se;
//        cerr << l << ' ' << m << ' ' << s << ' ' << sh[m][s] << '\n';
        if (s == 2) {
            string t = '!' + sh[m][s];
            int mm = m ^ 255, ss = 2;
            if (better(t, sh[mm][ss])) {
//                cerr << mm << ' ' << ss << '\n';
                sh[mm][ss] = t;
                q[t.size()].pb({mm, ss});
            }
            forn(j, 256) {
                int mm = m & j, ss = 1;
                string t = sh[j][1] + '&' + sh[m][s];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
//            forn(j, 256)
            {
                int mm = m, ss = 1;
                string t = sh[m][s];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
//            }
        }
        if (s == 1) {
            {
                int mm = m, ss = 0;
                string t = sh[m][s];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
            forn(j, 256) {
                int mm = m & j, ss = 1;
                string t = sh[m][s] + '&' + sh[j][2];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
            forn(j, 256) {
                int mm = m | j, ss = 0;
                string t = sh[j][0] + '|' + sh[m][s];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
        }
        if (s == 0) {
            forn(j, 256) {
                int mm = m | j, ss = 0;
                string t = sh[m][s] + '|' + sh[j][1];
                if (better(t, sh[mm][ss])) {
                    sh[mm][ss] = t;
                    q[t.size()].pb({mm, ss});
                }
            }
            int mm = m, ss = 2;
            string t = '(' + sh[m][s] + ')';
            if (better(t, sh[mm][ss])) {
                sh[mm][ss] = t;
                q[t.size()].pb({mm, ss});
            }
        }
    }

    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        int m = 0;
        forn(i, 8) m |= (s[i] - '0') << i;
        cout << sh[m][0] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}