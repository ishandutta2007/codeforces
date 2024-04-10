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

vi query(vector<pii> a) {
    vi res(a.size());
    vector<pii> acta;
    vi ind;
    forn(i, a.size()) {
        if (a[i].fi == a[i].se) res[i] = 1;
        else ind.pb(i), acta.pb(a[i]);
    }
    if (acta.empty()) return res;
    cout << "Q " << acta.size();
    for (auto w: acta) cout << ' ' << w.fi + 1 << ' ' << w.se + 1;
    cout << endl;
    string s;
    cin >> s;
    vi ans(s.size());
    forn(i, s.size()) ans[ind[i]] = s[i] - '0';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        assert(n != -1);

        vi diff(n);
        forn(t, 2) {
            vector<pii> q;
            for (int i = t; i + 1 < n + t; i += 2) q.pb({i, (i + 1) % n});
            vi res = query(q);
            forn(i, q.size()) diff[q[i].fi] = res[i];
        }

        if (n % 2) diff[n - 1] = query({{n - 1, 0}})[0];
        vvi parts(1);
        parts[0] = {0};
        for1(i, n - 1) {
            if (!diff[i - 1]) parts.pb({});
            parts.back().pb(i);
        }
        if (diff[n - 1] && parts.size() > 1) {
            for (int x: parts.back()) parts[0].pb(x);
            parts.pop_back();
        }

        int K = parts.size();
        vi asked(K);
        if (K <= 2) asked = vi(K, 1);
        else if (K == 3) asked = vi(K, 0);
        else {
            forn(t, 2) {
                vector<pii> q;
                vi pos;
                forn(i, K) {
                    if (i % 4 / 2 != t || i + 2 >= K) continue;
                    q.pb({parts[i][0], parts[i + 2][0]});
                    pos.pb(i);
                }
                vi res = query(q);
                forn(i, q.size()) asked[pos[i]] = res[i];
            }

            vector<pii> q;
            vi pos;
            forn(i, K) {
                if (i + 2 >= K) q.pb({parts[i][0], parts[i + 2 - K][0]}), pos.pb(i);
            }
            vi res = query(q);
            forn(i, q.size()) asked[pos[i]] = res[i];
        }

        vvi ans(3);
        if (asked == vi(K, 1)) {
            assert(K % 2 == 0 || K == 1);
            forn(i, K) for (int x: parts[i]) ans[i % 2].pb(x);
        } else {
            int i = min_element(all(ans)) - ans.begin();
            vi num(K);
            forn(j, 2) num[(i + j) % K] = j;
            forn(j, K) {
                int ii = (i + j) % K;
                num[(ii + 2) % K] = asked[ii] ? num[ii] : 3 ^ num[ii] ^ num[(ii + 1) % K];
            }
            forn(i, K) for (int x: parts[i]) ans[num[i]].pb(x);
        }

        forn(i, 3) sort(all(ans[i]));
        cout << "A";
        forn(i, 3) cout << ' ' << ans[i].size();
        cout << '\n';
        forn(i, 3) {
            for (int x: ans[i]) cout << x + 1 << ' ';
            cout << '\n';
        }
        cout.flush();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}