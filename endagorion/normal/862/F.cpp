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

const int maxn = 110000, B = 100;
string s[maxn];
int lcp[maxn];
set<int> ls;

int get_lcp(int i) {
    for (size_t j = 0; ; ++j) if (j >= min(s[i].size(), s[i + 1].size()) || s[i][j] != s[i + 1][j]) return j;
}

int large_ans(int L, int R) {
    vector<pii> st;
    int li = -100;
    int ans = 0;
    for (int i: ls) {
        if (i < L || i >= R) continue;
        if (i - li > 1 && !st.empty()) {
            int j = li + 1;
            while (!st.empty()) {
                auto [k, h] = st.back();
                uax(ans, (j - k) * h);
                st.pop_back();
            }
        }
        int lim = i ? lcp[i - 1] : 0;
        int pk = -1;
        while (!st.empty() && st.back().se > lim) {
            auto [k, h] = st.back();
            uax(ans, (i - k) * h);
            pk = k;
            st.pop_back();
        }
        if (pk != -1) st.pb(mp(pk, lim));
        int nh = (int)s[i].size();
        st.pb(mp(i, nh));
//        cerr << L << ' ' << R << ' ' << i << ' ' << s[i] << ' ' << ans << '\n';
//        for (auto [x, y]: st) cerr << x << ' ' << y << '\n';
        li = i;
    }
    if (!st.empty()) {
        int j = li + 1;
        while (!st.empty()) {
            auto [k, h] = st.back();
            uax(ans, (j - k) * h);
            st.pop_back();
        }
    }
//    cerr << ans << '\n';
    return ans;
}

struct TRes {
    int ans;
    int L, R;
    int minh;
    int pref[B], suf[B];

    TRes operator+(const TRes &r) const {
        if (R == L) return r;
        if (r.R == r.L) return *this;
        TRes res;
        res.ans = max(ans, r.ans);
        res.L = L;
        res.R = r.R;
        res.minh = min(minh, r.minh);
        uin(res.minh, lcp[R - 1]);
        forn(i, B) {
            if (i <= lcp[R - 1]) uax(res.ans, i * (suf[i] + r.pref[i]));
            res.pref[i] = (i <= lcp[R - 1] && pref[i] == R - L ? R - L + r.pref[i] : pref[i]);
            res.suf[i] = (i <= lcp[R - 1] && r.suf[i] == r.R - r.L ? r.R - r.L + suf[i] : r.suf[i]);
        }
        return res;
    }
};

TRes single(int i) {
    TRes res;
    res.ans = s[i].size();
    res.L = i;
    res.R = i + 1;
    res.minh = res.ans;
    forn(h, B) res.pref[h] = res.suf[h] = (h <= res.ans ? 1 : 0);
    return res;
}

TRes empty() {
    TRes res;
    res.L = res.R = 0;
    return res;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) n.res = single(L);
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

TRes query(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res;
    return query(n.l, L, R) + query(n.r, L, R);
}

void update(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = single(i);
        return;
    }
    update(n.l, i);
    update(n.r, i);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    forn(i, n) cin >> s[i];
    forn(i, n - 1) lcp[i] = get_lcp(i);
    forn(i, n) if ((int)s[i].size() >= B) ls.insert(i);

    int root = buildTree(0, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            cin >> L >> R;
            --L;
            cout << max(query(root, L, R).ans, large_ans(L, R)) << '\n';
        } else {
            int i;
            cin >> i;
            --i;
            cin >> s[i];
            ls.erase(i);
            if ((int)s[i].size() >= B) ls.insert(i);
            if (i) lcp[i - 1] = get_lcp(i - 1);
            if (i + 1 < n) lcp[i] = get_lcp(i);
            update(root, i);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}