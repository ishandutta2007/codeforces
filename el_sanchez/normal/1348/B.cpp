#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAXN = (int)1e4 + 100;

int k, n;
int a[MAXN];

void solve() {
    vi diffs;
    set<int> occ;
    forn(i, n) {
        if (occ.find(a[i]) == occ.end()) {
            occ.insert(a[i]);
            diffs.pb(a[i]);
        }
    }

    if ((int)occ.size() > k) {
        printf("-1\n");
        return;
    }
    diffs.resize(k, 1);
    printf("%d\n", (int)diffs.size() * n);
    forn(i, n) {
        forn(j, diffs.size()) {
            printf("%d%c", diffs[j], " \n"[(i == n - 1) && (j == (int)diffs.size() - 1)]);
        }
    }
}

bool read() {
    if (!(cin >> n >> k)) {
        return 0;
    }
    forn(i, n) {
        cin >> a[i];
    }
    return 1;
}

int main() {

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (read()) {
        solve();
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}