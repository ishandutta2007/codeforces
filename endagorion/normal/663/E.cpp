#include <iostream>
#include <tuple>
#include <sstream>
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
#define mt make_tuple
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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 100001;
int a[maxn];
int cnt[20][1 << 10];
int pc[1 << 21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, 1 << 20) {
        pc[i] = pc[i & (i - 1)] + 1;
    }

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) a[j] |= (s[j] - '0') << i;
    }
    int BUBEN = min(14, n);
    uax(BUBEN, 0);
    int res = 1e9;
    forn(i, 1 << BUBEN) {
        forn(j, BUBEN + 1) forn(k, 1 << (n - BUBEN)) cnt[j][k] = 0;
        forn(j, m) {
            ++cnt[pc[(a[j] ^ i) & ((1 << BUBEN) - 1)]][a[j] >> BUBEN];
        }
        forn(j, 1 << (n - BUBEN)) {
            int ans = 0;
            forn(k, BUBEN + 1) forn(l, 1 << (n - BUBEN)) {
                int z = k + pc[j ^ l];
                uin(z, n - z);
                ans += cnt[k][l] * z;
            }
            uin(res, ans);
        }
    }
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}