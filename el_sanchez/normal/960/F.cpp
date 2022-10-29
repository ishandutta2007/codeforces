#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

struct edge {
    int from, to, w;
};

int n, m;
vector<edge> edges;

bool read() {
   /* 
    n = rand() % 5 + 1;
    m = rand() % 100 + 1;
    edges.clear();
    edges.resize(m);
    forn(i, m) {
        edges[i].from = rand() % n;
        edges[i].to = rand() % n;
        edges[i].w = rand() % n;
    }
    eprintf("n=%d m=%d\n", n, m);
    forn(i, m) {
        eprintf("%d %d %d\n", edges[i].from, edges[i].to, edges[i].w);
    }
    return 1;
*/
    if (!(cin >> n >> m)) {
        return 0;
    }
    edges.clear();
    edges.resize(m);
    forn(i, m) {
        edge e;
        cin >> e.from >> e.to >> e.w;
        e.from--, e.to--;
        edges[i] = e; 
    }
    return 1;
}

const int MAXN = (int)1e5 + 100;
const int MAXK = (int)131072;

int a[MAXN], t[MAXK * 2 + 3];

//!!!
//tree: numeration from 1
//array: numeration from 0

void tree_build() {
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n; i++)
        t[MAXK + i] = a[i];
    
    for (int v = MAXK - 1; v >= 1; v--) {
        if (t[2 * v] > t[2 * v + 1]) {
            t[v] = t[2 * v];
        } else {
            t[v] = t[2 * v + 1];
        }
    }
}

void update(int i, int value) {
    int v = MAXK + i;
    t[v] = max(t[v], value);
    while (v > 1) {
        v /= 2;
        if (t[2 * v] > t[2 * v + 1]) {
            t[v] = t[2 * v];
        } else {
            t[v] = t[2 * v + 1];
        }
    }
}

int get(int v, int l, int r, int lx, int rx) { //[lx, rx)
    if ((r <= lx) || (rx <= l))
        return -1;
    if ((lx <= l) && (r <= rx))
        return t[v];

    int t1 = get(2 * v, l, (l + r) >> 1, lx, rx);
    int t2 = get(2 * v + 1, (l + r) >> 1, r, lx, rx);
    if (t1 > t2)
        return t1;
    return t2;
}

int get(int l, int r) { //[l, r]
    if (l > r) {
        return -1;
    }
    return get(1, 1, MAXK + 1, l + 1, r + 2);
}

vi end_w[MAXN];
int L[MAXN];
int dp[MAXN];

void image(vi &a) {
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
}

int solve() {
    tree_build();
    forn(i, n) {
        end_w[i].clear();
    }
    forn(i, m) {
        end_w[edges[i].to].pb(edges[i].w);
    }
    forn(i, n) {
        image(end_w[i]);
    }
    L[0] = 0;
    for (int i = 1; i <= n; i++) {
        L[i] = L[i - 1] + sz(end_w[i - 1]);
    }
    forn(i, n) {
        eprintf("%d: [%d..%d)\n", i, L[i], L[i + 1]);
    }

    int ans = 1;
    forn(i, m) {
        dp[i] = 1;
        int from = edges[i].from;
        int pos = lower_bound(all(end_w[from]), edges[i].w) - end_w[from].begin();
        pos--;
        int qL = L[from], qR = L[from] + pos;
        eprintf("q: %d..%d\n", qL, qR);
        int mx = get(qL, qR);
        dp[i] = max(mx + 1, dp[i]);
        
        int to = edges[i].to;
        pos = lower_bound(all(end_w[to]), edges[i].w) - end_w[to].begin();
        assert(end_w[to][pos] == edges[i].w);
        update(L[to] + pos, dp[i]);

        eprintf("dp[%d]=%d\n", i, dp[i]);
    }

    forn(i, m) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int dummy() {
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    forn(i, m) {
        dp[i] = 1;
        forn(j, i) {
            if (edges[j].to == edges[i].from && edges[j].w < edges[i].w) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        int a1 = solve();
        cout << a1 << '\n';
        continue;

        int a2 = dummy();
        if (a1 != a2) {
            eprintf("FAIL!!!\n");
            eprintf("ans=%d opt=%d\n", a1, a2);
            return 0;
        }

        cout << a1 << '\n';
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}