#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define rall(x) (x).rbegin(), (x).rend()
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1000001;
const int BUBEN = 80;
int dps[maxn];
int cnt[BUBEN + 1];
bitset<maxn> dpl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    vi p(n);
    forn(i, n) cin >> p[i], --p[i];
    vi lens;
    forn(i, n) {
        if (p[i] == -1) continue;
        int x = 0;
        for (int j = i; p[j] != -1; ) {
            ++x;
            int k = p[j];
            p[j] = -1;
            j = k;
        }
        lens.pb(x);
    }
    int m2 = 0, m = 0;
    for (int x: lens) m2 += x / 2, m += (x + 1) / 2;

    int max_ans = min(m2, k) + min(m, k);
    
    dps[0] = 1;
    dpl[0] = 1;
    for (int x: lens) {
        if (x <= BUBEN) ++cnt[x];
        else dpl |= dpl << x;
    }
    for1(l, BUBEN) {
        forn(i, l) {
            int d = 1e9;
            for (int j = i; j <= n; j += l) {
                if (dps[j]) d = 0;
                if (d <= cnt[l]) dps[j] = 1;
                ++d;
            }
        }
    }

    bool can = false;
    forn(i, k + 1) can |= dps[i] && dpl[k - i];
    int min_ans = k + (can ? 0 : 1);

    cout << min_ans << ' ' << max_ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}