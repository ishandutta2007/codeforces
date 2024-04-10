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

const int maxn = 210;
i64 cost[maxn], trcost[maxn];
int tr[26][maxn];
string st[maxn];
map<string, int> en;

int tc = 2;

void add(string s) {
    int r = 1;
//    for (char c: s) {
    forn(i, s.size()) {
        int cc = s[i] - 'a';
        if (!tr[cc][r]) tr[cc][r] = tc++;
        r = tr[cc][r];
        st[r] = string(s.begin(), s.begin() + i + 1);
        en[st[r]] = r;
    }
}

int move(int r, int d) {
    string a = st[r];
    for (int l = a.size(); l >= 0; --l) {
        string b = string(a.end() - l, a.end());
        if (!en.count(b)) continue;
        int z = en[b];
        if (tr[d][z]) return tr[d][z];
    }
    return 0;
}

vvi64 mul(vvi64 a, vvi64 b) {
    int n = a.size();
    vvi64 c(n, vi64(n, -1));
    forn(i, n) forn(j, n) forn(k, n) {
        if (a[i][k] < 0 || b[k][j] < 0) continue;
        uax(c[i][j], a[i][k] + b[k][j]);
    }
    return c;
}

vvi64 deg(vvi64 a, i64 d) {
    int n = a.size();
    vvi64 c(n, vi64(n, -1));
    forn(i, n) c[i][i] = 0;
    while (d) {
        if (d & 1) c = mul(c, a);
        a = mul(a, a);
        d /= 2;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    i64 L;
    cin >> n >> L;
    forn(i, n) cin >> cost[i];
    vector<string> a(n);
    en[""] = 1;
    forn(i, n) cin >> a[i], add(a[i]);
    
    int K = tc - 1;
    vvi64 m(K, vi64(K, -1));
    forn(i, tc) {
        forn(j, n) {
            int l = a[j].size();
            if (st[i].size() >= l && string(st[i].end() - l, st[i].end()) == a[j]) trcost[i] += cost[j];
        }
    }

    forn(i, K) {
        forn(d, 26) {
            int j = move(i + 1, d) - 1;
            uax(m[i][j], trcost[j + 1]);
        }
    }

/*    forn(i, K) {
        forn(j, K) cerr << m[i][j] << ' ';
        cerr << '\n';
    }*/
    vvi64 mm = deg(m, L);
    i64 ans = 0;
    forn(i, K) uax(ans, mm[0][i]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}