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
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
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

const int MAXN = 110001;
int a[MAXN];
int cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) cin >> a[i];
    set<int> q;
    forn(i, N) {
        if (q.count(a[i])) q.erase(a[i]);
        else q.insert(a[i]);
    }
    if (q.size() > 1) {
        cout << 0 << '\n';
        return 0;
    }

    bool eq = true;
    for (int i = 0; i < N / 2; ++i) {
        if (a[i] != a[N - i - 1]) {
            eq = false;
            break;
        }
    }    
    if (eq) {
        cout << 1LL * N * (N + 1) / 2 << '\n';
        return 0;
    }

    i64 ans = 0;
    int l = 0;
    while (a[l] == a[N - l - 1]) ++l;
    int r = (N - 1) / 2;
    while (a[r] == a[N - r - 1]) --r;
    int nzc = 0;
    for (int i = l; i < N / 2; ++i) {
        int x = a[i];
        if (cnt[x] != 0) --nzc;
        ++cnt[x];
        if (cnt[x] != 0) ++nzc;

        x = a[N - i - 1];
        if (cnt[x] != 0) --nzc;
        --cnt[x];
        if (cnt[x] != 0) ++nzc;
    }
    if (nzc == 0) {
        cout << 2LL * (l + 1) * (N - r) - 1LL * (l + 1) * (l + 1) << '\n';
        return 0;
    }
    forn(i, MAXN) cnt[i] = 0;
    int nc = 0;
    forn(i, N) {
        if (cnt[a[i]] == 0) ++nc;
        --cnt[a[i]];
    }
    int i1, i2;
    for (int i = 0; i < N; ++i) {
        if (cnt[a[i]] < 0) --nc;
        cnt[a[i]] += 2;
        if (cnt[a[i]] < 0) ++nc;
        if (nc == 0) {
            i1 = i;
            break;
        }
    }

    forn(i, MAXN) cnt[i] = 0;
    nc = 0;
    forn(i, N) {
        if (cnt[a[i]] == 0) ++nc;
        --cnt[a[i]];
    }
    ford(i, N) {
        if (cnt[a[i]] < 0) --nc;
        cnt[a[i]] += 2;
        if (cnt[a[i]] < 0) ++nc;
        if (nc == 0) {
            i2 = i;
            break;
        }        
    }
    cout << 1LL * (l + 1) * (N - i1) + 1LL * (l + 1) * (i2 + 1) - 1LL * (l + 1) * (l + 1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}