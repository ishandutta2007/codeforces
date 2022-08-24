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
typedef unsigned long long ui64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxb = 2000;
typedef bitset<maxb> bs;

ui64 pw10[19];
ui64 repr[maxb / 18 + 1];

bs string_to_bin(string s) {
    forn(i, maxb / 18 + 1) repr[i] = 0;
    reverse(all(s));
    forn(i, s.size()) repr[i / 18] += ui64(s[i] - '0') * pw10[i % 18];
    __uint128_t b64 = __uint128_t(1) << 64;
    bs res;
    forn(t, maxb / 64 + 1) {
        __uint128_t x = 0;
        ford(i, maxb / 18 + 1) {
            x = x * pw10[18] + repr[i];
            repr[i] = x / b64;
            x %= b64;
        }
        forn(j, 64) {
            int p = t * 64 + j;
            if (p < maxb) res[p] = (x >> j) & 1;
        }
    }
    return res;
}

bs bt[maxb], indt[maxb];
int lbt[maxb];
int sz = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    pw10[0] = 1;
    forn(i, 18) pw10[i + 1] = pw10[i] * 10;

    int n;
    cin >> n;
    forn(i, n) {
        string s;
        cin >> s;
        bs b = string_to_bin(s);
        bs ind;
        ind[i] = 1;
        int lb = b._Find_first();
        forn(i, sz) {
            if (lb == lbt[i]) {
                b ^= bt[i];
                ind ^= indt[i];
                lb = b._Find_first();
            } else if (lb < lbt[i]) {
                swap(b, bt[i]);
                swap(ind, indt[i]);
                swap(lb, lbt[i]);
            }
        }
        if (b.any()) {
            cout << 0 << '\n';
            bt[sz] = b;
            indt[sz] = ind;
            lbt[sz] = lb;
            ++sz;
        } else {
            ind.flip(i);
            cout << ind.count();
            forn(i, maxb) if (ind[i]) cout << ' ' << i;
            cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}