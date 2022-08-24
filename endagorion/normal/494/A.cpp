#include <iostream>
#include <vector>
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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

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

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    cin >> s;
    int b = 0;
    int cnt = 0, last = -1;
    forn(i, s.size()) {
        if (s[i] == '(') ++b;
        else if (s[i] == ')') --b;
        else {
            ++cnt;
            last = i;
        }
    }
    int bb = 0;
    bool ok = b >= cnt;
    forn(i, s.size()) {
        if (s[i] == '(') ++bb;
        else if (s[i] == ')') --bb;
        else if (i != last) --bb;
        else bb -= b - cnt + 1;
        ok &= bb >= 0;
    }
    if (ok) {
        forn(i, cnt - 1) cout << 1 << '\n';
        cout << b - cnt + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}