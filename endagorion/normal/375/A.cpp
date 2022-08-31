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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s;
    cin >> s;
    bool s1 = false, s6 = false, s8 = false, s9 = false;
    string t;
    int m = 0;
    int zc = 0;
    forn(i, s.size()) {
        if (s[i] == '0') {
            ++zc;
        } else if (s[i] == '1' && !s1) {
            s1 = true;
        } else if (s[i] == '6' && !s6) {
            s6 = true;
        } else if (s[i] == '8' && !s8) {
            s8 = true;
        } else if (s[i] == '9' && !s9) {
            s9 = true;
        } else {
            t += s[i];
            m = (10 * m + s[i] - '0') % 7;
        }
    }

    cout << t;
    vector<int> a;
    a.pb(1);
    a.pb(6);
    a.pb(8);
    a.pb(9);
    while (true) {
        int mm = m;
        forn(i, 4) {
            mm = (10 * mm + a[i]) % 7;
        }
        if (mm == 0) {
            forn(i, 4) {
                cout << a[i];
            }
            break;
        }
        next_permutation(all(a));
    }
    forn(i, zc) {
        cout << '0';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}