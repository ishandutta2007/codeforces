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

const int maxn = 100001;

int px[maxn], py[maxn], pz[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s;
    cin >> s;
    forn(i, s.size()) {
        px[i + 1] = px[i];
        py[i + 1] = py[i];
        pz[i + 1] = pz[i];
        if (s[i] == 'x') {
            ++px[i + 1];
        }
        if (s[i] == 'y') {
            ++py[i + 1];
        }
        if (s[i] == 'z') {
            ++pz[i + 1];
        }
    }
    int M;
    cin >> M;
    forn(i, M) {
        int l, r;
        cin >> l >> r;
        --l;
        if (r - l <= 2) {
            cout << "YES\n";
            continue;
        }
        int x = px[r] - px[l], y = py[r] - py[l], z = pz[r] - pz[l];
        bool ok;
        if ((r - l) % 3 == 0) {
            ok = x == y && x == z;
        } else {
            ok = (max(x, max(y, z)) - min(x, min(y, z)) == 1);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}