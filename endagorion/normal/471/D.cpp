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
#endif

    ios::sync_with_stdio(false);
    int N, W;
    cin >> N >> W;
    vi a(N);
    forn(i, N) cin >> a[i];
    vi b(W);
    forn(i, W) cin >> b[i];
    if (W == 1) {
        cout << N << '\n';
        return 0;
    }

    vi s;
    forn(i, W - 1) s.pb(b[i + 1] - b[i]);
    s.pb(1e9);
    forn(i, N - 1) s.pb(a[i + 1] - a[i]);
    vi p(s.size());
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i) {
        p[i] = p[i - 1];
        while (p[i] && s[i] != s[p[i]]) p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]]) ++p[i];
        if (p[i] == W - 1) ++cnt;
    }
    cout << cnt << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}