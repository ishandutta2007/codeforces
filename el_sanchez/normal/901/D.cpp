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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

#define FILE_NAME "a"

const int MAXN = (int)2e5 + 100;
const int INF = (int)1e9;

struct edge {
    int id, u, v;
    
    void read(int id_) {
        scanf("%d%d", &u, &v);
        u--, v--;
        id = id_;   
    }
    
    int to(int x) {
        return (v ^ u) ^ x;   
    }
};

int n, m;
int c[MAXN];
ll cur[MAXN];
edge e[MAXN];
int used[MAXN], h[MAXN], eused[MAXN], fedge[MAXN], deg[MAXN];
vi g[MAXN], t[MAXN];
ll ans[MAXN];

void apply(int eid, ll x) {
    //cout << "applying " << eid << ' ' << e[eid].u << ' ' << e[eid].v << ' ' << x << endl;
    ans[eid] += x;
    cur[e[eid].u] += x;
    cur[e[eid].v] += x;
}

bool read() {
    if (scanf("%d%d", &n, &m) < 2) {
        return 0;
    }
    
    forn(i, n) {
        g[i].clear();   
    }
    forn(i, n) {
        scanf("%d", &c[i]);   
    }
    forn(i, m) {
        eused[i] = 0;
        e[i].read(i);     
        g[e[i].u].pb(i);
        g[e[i].v].pb(i);
    }
    return 1;
}

void dfs(int v) {
    used[v] = 1;        
    
    for (auto i: g[v]) {
        int to = e[i].to(v);
        if (!used[to]) {
            t[v].pb(i);
            t[to].pb(i);
            
            eused[i] = 1;
            
            fedge[to] = i;
            deg[v]++;
            
            h[to] = h[v] + 1;
            dfs(to);               
        }
    }
}

bool dfsct(int v, int aim, ll add) {
    if (v == aim) {
        return 1;    
    }
    
    used[v] = 1;

    for (auto i: t[v]) {
        int to = e[i].to(v);
        if (!used[to]) {
            if (dfsct(to, aim, -add)) {
                apply(i, add);
                return 1;
            }
        }
    }
  
    return 0;
}

bool solve() {
    memset(used, 0, sizeof(used));
    memset(eused, 0, sizeof(eused));
    forn(i, n) {
        fedge[i] = -1;
        t[i].clear(); 
        cur[i] = 0;
        deg[i] = 0;
    }
    forn(i, m) {
        ans[i] = 0;   
    }
    
    h[0] = 0;
    dfs(0);

    int cool = -1;
    
    forn(i, m) {
        if (!eused[i]) {
            int u = e[i].u;
            int v = e[i].v;
            if ((h[u] + h[v]) % 2 == 0) {
                cool = i;
                break;    
            }
        } else {
//            cout << "GOOD " << i << endl;   
        }
    }
    
    queue<int> q;
    forn(i, n) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == 0) {
            break;
        }
        
        //cout << "look " << v << endl;
        ll need_add = (0ll + c[v] - cur[v]);
        apply(fedge[v], need_add);
        
        int to = e[fedge[v]].to(v);
        deg[to]--;
        
        if (deg[to] == 0) {
            q.push(to);   
        }
    }
    
    if (c[0] == cur[0]) {
        return 1;
    }
    
//    cout << "!!! " << cool << endl;
    if (cool == -1) {
        return 0;    
    }
    
    ll need_add = (0ll + c[0] - cur[0]);
    assert(need_add % 2 == 0);
    
    int u = e[cool].u;
    int v = e[cool].v;
    
    ll cycle_add = (h[v] % 2 == 0 ? +(need_add / 2) : -(need_add / 2));
    apply(cool, cycle_add);

    memset(used, 0, sizeof(used));
    dfsct(v, u, +cycle_add);    

    cycle_add *= 2;
        
    while (v != 0) {
        cycle_add *= -1;
        apply(fedge[v], cycle_add);
        v = e[fedge[v]].to(v);
    }
    
    assert(c[0] == cur[0]);
    
    return 1;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    // freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        if (!solve()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            forn(i, m) {
                printf("%I64d\n", ans[i]);
            }
        }
    }

#ifdef LOCAL
    eprintf("Time: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif

    return 0;
}