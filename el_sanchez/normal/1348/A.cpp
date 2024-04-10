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


int n;

ll solve() {
    ll x = 0;
    x = 1ll << n;
    for (int i = 1; i < n / 2; i++) {
        x += 1ll << i;
    }
    for (int i = n / 2; i < n; i++) {
        x -= 1ll << i;
    }
    return x;
}

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (read()) {
        cout << solve() << '\n';
    }
#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}