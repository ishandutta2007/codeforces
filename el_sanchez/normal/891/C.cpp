#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

const int MAXN = (int)5e5 + 55;

struct edge {
    int u, v, w, id;

    bool operator<(const edge &e) const {
        return w < e.w;
    }
};

struct DSU {
    int rk[MAXN], par[MAXN];
    vector<pair<int, pii>> events;
        
    DSU(int n = 0) {
        forn(i, n) {
            rk[i] = 0;
            par[i] = i;
        }
        events.clear();
    }
    
    int get_last() {
        return sz(events);   
    }
    
    void revert(int last_ptr) {
        while (sz(events) != last_ptr) {
            auto event = events.back();
            events.pop_back();
            
            int v = event.snd.fst;
            int val = event.snd.snd;
            
            if (event.fst == 0) {
                par[v] = val;  
            } else {
                rk[v] = val;  
            }
        }
    }
    
    int get_root(int v) {
        if (par[v] == v) {
            return v;
        }
        return get_root(par[v]);
    }
    
    void add_event(int t, int v, int val) {
        events.pb(mp(t, mp(v, val)));    
    }
    
    bool unite(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        
        if (u == v) {
            return false;
        }
        
        assert(par[u] == u);
        assert(par[v] == v);
        
        if (rk[u] > rk[v]) {
            swap(u, v);
        }
        
        if (rk[u] == rk[v]) {
            add_event(1, v, rk[v]);
            rk[v]++;    
        }
        
        add_event(0, u, u);
        par[u] = v;

        return true;        
    }
};

int n, m, k;
edge e[MAXN];

bool edge_cmp(int i1, int i2) {
    return e[i1].w < e[i2].w;    
}

int wnum;
int weights[MAXN];
vector<pair<int, vi>> buckets[MAXN];
vi queries[MAXN];

DSU dsu;
bool ans[MAXN];

bool read() {
    if (scanf("%d%d", &n, &m) < 2) {
        return 0;
    }
    forn(i, m) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        e[i].u--;
        e[i].v--;
        e[i].id = i;
    }
    
    scanf("%d", &k);
    queries[0].clear();
    forn(i, m) {
        queries[0].pb(i);
    }
    forn(i, k) {
        int s;
        scanf("%d", &s);
        queries[i + 1].clear();
        queries[i + 1].resize(s);
        forn(j, s) {
            scanf("%d", &queries[i + 1][j]);
            queries[i + 1][j]--;
        }
    }
    k++;
    
    return 1;
}

void solve() {
    wnum = 0;
    forn(i, m) {
        weights[i] = e[i].w;    
    }
    sort(weights, weights + m);
    wnum = unique(weights, weights + m) - weights;
    
    forn(i, m) {
        e[i].w = lower_bound(weights, weights + wnum, e[i].w) - weights;   
    }
    
    forn(i, m) {
        assert(0 <= e[i].w && e[i].w < wnum);
    }
    forn(i, k) {
        ans[i] = 1;   
    }
    
    // sort all buckets
    forn(i, k + 1) {
        sort(all(queries[i]), edge_cmp);
    }
    
    forn(i, wnum) {
        buckets[i].clear();    
    }
    
    // add all buckets
    pair<int, vi> bucket;
    forn(i, k + 1) {
        int L = 0;
        for (int j = 1; j <= sz(queries[i]); j++) {
            if (j == sz(queries[i]) || e[queries[i][L]].w != e[queries[i][j]].w) {
                int w = e[queries[i][L]].w;
                
                bucket.snd.clear();

                bucket.fst = i;
                for (int t = L; t < j; t++) {
                    bucket.snd.pb(queries[i][t]);
                }
                
                buckets[w].pb(bucket);
                
                L = j;
            }
        }
    }
    
    dsu = DSU(n);
    forn(i, wnum) {
        assert(!buckets[i].empty());
        assert(buckets[i][0].fst == 0);
        
        for (int id = 1; id < sz(buckets[i]); id++) {
            int ptr = dsu.get_last();
            int qid = buckets[i][id].fst;
            for (auto eid: buckets[i][id].snd) {
                ans[qid] &= dsu.unite(e[eid].u, e[eid].v);
            }
            dsu.revert(ptr);
        }
        
        for (auto eid: buckets[i][0].snd) {
            dsu.unite(e[eid].u, e[eid].v);
        }
    }
    
    // get answer
    forn(i, k - 1) {
        cout << (ans[i + 1] ? "YES" : "NO") << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif
   
    while (read()) {
        solve();
    }

    return 0;
}