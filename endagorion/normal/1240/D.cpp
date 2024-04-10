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
typedef unsigned long long ui64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

ui64 add(ui64 x, ui64 a) {
    return (11 * x + 11901) ^ (x << 13) ^ (x >> 11) ^ (a << 5) ^ ((x + 11) * (113 * a + 713));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        map<ui64, int> cnt;
        vector<ui64> sth = {0ULL};
        vi st;
        cnt[0] = 1;
        i64 ans = 0;
        for (int x: a) {
            if (st.empty() || st.back() != x) {
                st.pb(x);
                ui64 z = sth.back();
                sth.pb(add(z, x));
            } else st.pop_back(), sth.pop_back();
            ans += cnt[sth.back()];
            ++cnt[sth.back()];
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}