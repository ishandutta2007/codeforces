#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

int toStr(const string &s) {
    int ans = 0;
    forn(i, s.size()) {
        int d = (s[i] == '?' ? 9 : s[i] - '0');
        ans = 10 * ans + d;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    vector<string> s(N);
    forn(i, N) cin >> s[i];
    int p = 0;

    bool ok = true;
    forn(i, N) {
        forn(j, s[i].size()) {
            if (s[i][j] == '?') {
                forn(d, 10) {
                    if (j == 0 && d == 0) continue;
                    s[i][j] = (char)('0' + d);
                    if (toStr(s[i]) > p) break;
                }
                if (toStr(s[i]) <= p) ok = false;
            }
        }
        ok &= toStr(s[i]) > p;
        p = toStr(s[i]);

    }
    if (ok) {
        cout << "YES\n";
        forn(i, N) cout << s[i] << '\n';
    }
    else cout << "NO\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}