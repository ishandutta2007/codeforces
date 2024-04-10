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

int t[5001], l[5001], r[5001], d[5001];
int a[5001], b[5001];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    cin >> N >> M;

    forn(i, N) {
        b[i] = 1e9;
    }


    forn(i, M) {
        cin >> t[i] >> l[i] >> r[i] >> d[i];
        --l[i]; --r[i];
        if (t[i] == 1) {
            fore(j, l[i], r[i]) a[j] += d[i];
        } else {
            fore(j, l[i], r[i]) b[j] = min(b[j], d[i] - a[j]);
        }
    }

    forn(i, N) {
        a[i] = b[i];
    }


    bool ok = true;
    forn(i, M) {
        if (t[i] == 1) {
            fore(j, l[i], r[i]) a[j] += d[i];
        } else {
            int m = -1e9;
            fore(j, l[i], r[i]) m = max(m, a[j]);
            if (m != d[i]) {
                ok = false;
                cerr << i << '\n';
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        forn(i, N) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
      
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}