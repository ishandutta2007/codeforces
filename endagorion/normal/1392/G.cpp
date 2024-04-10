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

typedef bitset<20> bs;

int k;

bs applyInv(bs b, const vi &perm) {
    bs res;
    forn(i, k) res[perm[i]] = b[i];
    return res;
}

int minP[1 << 20], nminP[1 << 20], maxP[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    string s, t;
    cin >> n >> m >> k >> s >> t;
    bs init, target;
    forn(i, k) init[i] = s[i] - '0';
    forn(i, k) target[i] = t[i] - '0';
    vi perm(k);
    iota(all(perm), 0);
    forn(i, 1 << k) minP[i] = 1e9, maxP[i] = -1e9;
    minP[init.to_ulong()] = maxP[target.to_ulong()] = 0;
    forn(i, n) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        swap(perm[x], perm[y]);
        uin(minP[applyInv(init, perm).to_ulong()], i + 1);
        uax(maxP[applyInv(target, perm).to_ulong()], i + 1);
//        cerr << applyInv(init, perm).to_string() << ' ' << applyInv(target, perm).to_string() << '\n';
    }

    pii ans;
    int S = 0;
    bool done = false;
    while (1) {
        forn(i, 1 << k) if (maxP[i] - minP[i] >= m) {
            ans = {minP[i], maxP[i]};
            done = true;
        }
        if (done) break;
        ++S;
        forn(mask, 1 << k) nminP[mask] = minP[mask];
        forn(i, k) forn(mask, 1 << k) uin(nminP[mask], minP[mask ^ (1 << i)]);
        forn(mask, 1 << k) minP[mask] = nminP[mask];
    }

    cout << k - S << '\n';
    cout << ans.fi + 1 << ' ' << ans.se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}