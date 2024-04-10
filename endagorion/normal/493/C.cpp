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

i64 ba, bb;
void relax(i64 a, i64 b) {
    if (a - b > ba - bb || (a - b == ba - bb && a > ba)) {
        ba = a; bb = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N;
    vi a(N);
    forn(i, N) cin >> a[i];
    cin >> M;
    vi b(M);
    forn(i, M) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ba = -1, bb = 1e18;
    relax(2 * a.size(), 2 * b.size());
    relax(3 * a.size(), 3 * b.size());
    forn(i, a.size()) {
        int ca = upper_bound(all(a), a[i]) - a.begin();
        int cb = upper_bound(all(b), a[i]) - b.begin();
        relax(2LL * ca + 3LL * (a.size() - ca), 2LL * cb + 3LL * (b.size() - cb));
    }
    forn(i, b.size()) {
        int ca = upper_bound(all(a), b[i]) - a.begin();
        int cb = upper_bound(all(b), b[i]) - b.begin();
        relax(2LL * ca + 3LL * (a.size() - ca), 2LL * cb + 3LL * (b.size() - cb));
    }
    cout << ba << ':' << bb << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}