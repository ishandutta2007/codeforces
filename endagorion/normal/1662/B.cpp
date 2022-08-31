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

int cnt[3][26];
int l[3];

int take_any(int j) {
    forn(i, 26) {
        if (cnt[j][i]) {
            --cnt[j][i];
            --l[j];
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, 3) {
        string s;
        cin >> s;
        l[i] = s.size();
        for (auto c: s) ++cnt[i][c - 'A'];
    }

    int ps = 0;
    vector<pii> ans;
    vi unm;
    forn(i, 26) {
        int S = 0, M = 0;
        forn(j, 3) S += cnt[j][i], uax(M, cnt[j][i]);
        int L = 1e9;
        while (L--) {
            vi v = {0, 1, 2};
            sort(all(v), [&](int x, int y){return cnt[x][i] < cnt[y][i];});
            if (!cnt[v[1]][i]) break;
            ans.pb(mp(i, -1));
            unm.pb(v[0]);
            for1(z, 2) --cnt[v[z]][i], --l[v[z]];
        }
    }

    forn(i, ans.size()) {
        ans[i].se = take_any(unm[i]);
        if (ans[i].se == -1) {
            int x = ans[i].fi;
            forn(z, 3) {
                if (z != unm[i]) {
                    ++l[z];
                    ++cnt[z][x];
                }
            }
        }
    }
    {
        vector<pii> nans;
        forn(i, ans.size()) {
            if (ans[i].se != -1) nans.pb(ans[i]);
        }
        ans = nans;
    }

    while (1) {
        vi v = {0, 1, 2};
        sort(all(v), [&](int x, int y){return l[x] > l[y];});
        if (!l[v[0]]) break;
        ans.pb(mp(take_any(v[0]), max(take_any(v[1]), 0)));
    }

    cout << ans.size() << '\n';
    for (auto [x, y]: ans) {
        cout << (char)('A' + x) << (char)('A' + y) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}