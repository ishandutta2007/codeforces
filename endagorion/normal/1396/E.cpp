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

const int maxn = 110000;
vi e[maxn];
int w[maxn], lb[maxn], ub[maxn], par[maxn];
int as[maxn];
int n;
i64 k, L, U;
vi lst[maxn];

struct TComp {
    bool operator()(int i, int j) const {
        return mp(lst[i].size(), i) > mp(lst[j].size(), j);
    }
};

void merge(int i, int j) {
    if (lst[i].size() < lst[j].size()) lst[i].swap(lst[j]);
    for (int x: lst[j]) lst[i].pb(x);
    lst[j].clear();
}

void dfs0(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        par[u] = v;
        dfs0(u, v);
        w[v] += w[u];
        lb[u] = w[u] % 2;
        ub[u] = min(w[u], n - w[u]);
        L += lb[u];
        U += ub[u];
    }
}

vector<pii> ans;
void dfs1(int v, int p) {
    lst[v] = {v};
    set<int, TComp> q = {v};
    int T = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs1(u, v);
        T += lst[u].size();
        q.insert(u);
    }
    while (T > as[v]) {
        assert(q.size() > 1);
        int a = *q.begin();
        q.erase(a);
        int b = *q.begin();
        q.erase(b);
        assert(!lst[a].empty() && !lst[b].empty());
        ans.pb(mp(lst[a].back(), lst[b].back()));
        lst[a].pop_back(); lst[b].pop_back();
        q.insert(a);
        q.insert(b);
        T -= 2;
    }
    for (int u: e[v]) {
        if (u == p) continue;
        merge(v, u);
    }
    assert(lst[v].size() == as[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs0(0, -1);
    if (k < L || k > U || k % 2 != L % 2) {
        cout << "NO\n";
        return 0;
    }

    int l = -1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        i64 S = 0;
        for1(i, n - 1) {
            if (lb[i] > m) S += lb[i];
            else if (ub[i] <= m) S += ub[i];
            else {
                int x = m;
                if (x % 2 != lb[i] % 2) --x;
                while (x <= m) x += 2;
                S += x;
            }
        }
        (S <= k ? l : r) = m;
    }

    i64 S = 0;
    for1(i, n - 1) {
        if (lb[i] > l) as[i] = lb[i];
        else if (ub[i] <= l) as[i] = ub[i];
        else {
            as[i] = l;
            if (as[i] % 2 != lb[i] % 2) --as[i];
            while (as[i] <= l) as[i] += 2;
        }
        k -= as[i];
    }

    for1(i, n - 1) {
        if (!k) break;
        if (as[i] == r && as[i] + 2 <= ub[i]) as[i] += 2, k -= 2;
    }
    assert(k == 0);
    dfs1(0, -1);
    cout << "YES\n";
    for (auto w: ans) cout << w.fi + 1 << ' ' << w.se + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}