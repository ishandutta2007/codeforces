#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")
#include <bits/stdc++.h>

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

const int maxn = 2000;
typedef bitset<maxn> bs;

bs pref[maxn + 1];
bs a[maxn + 2];
int cnt[maxn + 2];
int dif[maxn + 2][2];

bs adjp;

//int ord[maxn + 1], invord[maxn + 1];

int n, m;

/*bool swap_with_next(int i) {
    int j = ord[invord[i] + 1];
    if (cnt[j] >= cnt[i]) return false;
    swap(invord[i], invord[j]);
    swap(ord[invord[i]], ord[invord[j]]);
    return true;
}*/

struct TComp {
    bool operator()(int i, int j) const {
        if (cnt[i] != cnt[j]) return cnt[i] < cnt[j];
        return i < j;
    };
};

set<int, TComp> qs;

void update_dif(int i) {
    if (i == -1) return;
    int j = *++qs.find(i);
    dif[i][0] = (a[i] & ~a[j])._Find_first();
    dif[i][1] = (a[j] & ~a[i])._Find_first();
    adjp[i] = int(max(dif[i][0], dif[i][1]) < maxn);
}

void print_ans(int i) {
    int x1 = i, x2 = *++qs.find(i);
    int y1 = dif[i][0], y2 = dif[i][1];
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
}

void qs_erase(int i) {
    auto it = --qs.find(i);
    qs.erase(i);
    update_dif(*it);
}

void qs_insert(int i) {
    qs.insert(i);
    int prv = *--qs.find(i);
    update_dif(i);
    update_dif(prv);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxn) {
        pref[i + 1] = pref[i];
        pref[i + 1][i] = 1;
    }

    int n, m, q;
    cin >> n >> m >> q;
//    forn(i, n + 1) ord[i] = invord[i] = i;
    a[n] = pref[m];
    cnt[n] = m;
    forn(i, n + 2) qs.insert(i);
    forn(i, n) update_dif(i);

    while (q--) {
        int i, l, r;
        cin >> i >> l >> r;
        --i; --l;
        a[i] ^= pref[l] ^ pref[r];
        qs_erase(i);
        cnt[i] = a[i].count();
        qs_insert(i);

        int ansi = adjp._Find_first();
        if (ansi >= maxn) cout << -1 << '\n';
        else print_ans(ansi);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}