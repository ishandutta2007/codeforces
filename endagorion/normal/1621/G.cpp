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

const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    if (y < 0) y += P;
    x += y;
    if (x >= P) x -= P;
}

const int maxn = 210000;
i64 fenw[maxn];
i64 endat[maxn], startat[maxn];
i64 badstart[maxn];
int farm[maxn];

i64 fenw_sum(int i) {
    i64 res = 0;
    for (; i >= 0; i &= i + 1, --i) add(res, fenw[i]);
    return res;
}

void fenw_add(int i, i64 x) {
    for (; i < maxn; i |= i + 1) add(fenw[i], x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        {
            vi xs = a;
            sort(all(xs));
            xs.erase(unique(all(xs)), xs.end());
            forn(i, n) a[i] = lower_bound(all(xs), a[i]) - xs.begin();
        }

        forn(i, n) {
            endat[i] = (fenw_sum(a[i] - 1) + 1) % P;
            fenw_add(a[i], endat[i]);
        }

        forn(i, n) fenw_add(a[i], -endat[i]);
        ford(i, n) {
            startat[i] = (fenw_sum(maxn - 1) - fenw_sum(a[i]) + 1) % P;
            if (startat[i] < 0) startat[i] += P;
            fenw_add(a[i], startat[i]);
        }
        forn(i, n) fenw_add(a[i], -startat[i]);

        vi st;
        ford(i, n) {
            if (st.empty() || a[i] >= a[st.back()]) {
                if (st.empty() || a[i] > a[st.back()]) st.pb(i);
                farm[i] = -1;
            } else farm[i] = *upper_bound(all(st), i, [&](int i, int j){return a[i] < a[j];});
        }
        vvi byfarm(n);
        forn(i, n) if (farm[i] != -1) byfarm[farm[i]].pb(i);
        forn(i, n) {
            if (farm[i] != -1) continue;
            auto &v = byfarm[i];
//            if (v.empty()) continue;
            v.pb(i);
            reverse(all(v));
            for (int x: v) badstart[x] = 0;
            for (int x: v) {
                if (x == v[0]) badstart[x] = 1;
                else badstart[x] = (fenw_sum(maxn - 1) - fenw_sum(a[x])) % P;
                if (badstart[x] < 0) badstart[x] += P;
                (startat[x] -= badstart[x]) %= P;
                fenw_add(a[x], badstart[x]);
            }
            for (int x: v) fenw_add(a[x], -badstart[x]);
        }
/*        forn(i, n) {
            cerr << i << ' ' << farm[i] << ' ' << endat[i] << ' ' << startat[i] << ' ' << badstart[i] << '\n';
        }*/
        i64 ans = 0;
        forn(i, n) (ans += endat[i] * startat[i]) %= P;
        if (ans < 0) ans += P;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}