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

const int maxn = 210000;
i64 fenw[maxn];
int cross[maxn], inside[maxn];

void addF(int i, int x) {
    for (; i < maxn; i |= i + 1) fenw[i] += x;
}

i64 sumF(int i) {
    i64 res = 0;
    for (; i >= 0; i &= i + 1, --i) res += fenw[i];
    return res;
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
    cin >> n;
    vector<pii> p(n);
    forn(i, n) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        p[i] = {a, b};
    }

    vi ordL(n), ordR(n);
    iota(all(ordL), 0);
    ordR = ordL;
    sort(all(ordL), [&](int i, int j){return p[i].fi < p[j].fi;});
    sort(all(ordR), [&](int i, int j){return p[i].se < p[j].se;});

    for (int i: ordL) {
        int l = p[i].fi, r = p[i].se;
        cross[i] += sumF(r) - sumF(l);
        addF(r, 1);
    }
    forn(i, maxn) fenw[i] = 0;
    reverse(all(ordR));
    for (int i: ordR) {
        int l = p[i].fi, r = p[i].se;
        cross[i] += sumF(r) - sumF(l);
        addF(l, 1);
    }
    reverse(all(ordR));
    forn(i, maxn) fenw[i] = 0;
    for (int i: ordR) {
        int l = p[i].fi, r = p[i].se;
        inside[i] += sumF(r) - sumF(l);
        addF(l, 1);        
    }

    i64 ans = 1LL * n * (n - 1) * (n - 2) / 3;
    forn(i, n) {
        ans -= 1LL * cross[i] * (n - 2);
        ans += 1LL * cross[i] * (cross[i] - 1);
        int non_cross = n - 1 - cross[i];
        ans -= 2LL * inside[i] * (non_cross - inside[i]);
//        cerr << p[i].fi << ' ' << p[i].se << ' ' << cross[i] << ' ' << inside[i] << '\n';
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}