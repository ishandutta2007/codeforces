#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int base;

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

	ll modExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

    hsh(int b) {
        base = b;
        p1 = 1000000007;
        p2 = 1000000009;
        val1 = 0;
        val2 = 0;
        inv2 = modExp(p2 - 2, p2);
        inv1 = modExp(p1 - 2, p1);
    }

    hsh(ll b, string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
        F0R(i, sz(S)) {
            push_back(S[i] - 'a');
        }
    }

    void push_back(ll v) {
        val1 *= base;
        val1 %= p1;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 %= p2;
        val2 += v;
        val2 %= p2;
    }

    pl get() {
        return {val1, val2};
    }
};

void prepHash() {
   base = uniform_int_distribution<int>(1000, MOD-2)(rng);
}



template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    prepHash();
    int N, K; cin >> N >> K;

    int D[K][N];
    int V[K];
    bool used[N]; F0R(i, N) used[i] = false;
    F0R(i, K) {
        V[i] = -1;
        F0R(j, N) {
            cin >> D[i][j];
            if (D[i][j] == 0) {
                if (V[i] != -1) {
                    cout << -1 << nl; return 0;
                }
                V[i] = j;
            }
        }
        if (V[i] == -1) {
            cout << -1 << nl; return 0;
        }
        if (used[V[i]]) {
            cout << -1 << nl; return 0;
        }
        used[V[i]] = true;
    }

    vector<vi> graph(N);

    bool proc[N]; F0R(i, N) proc[i] = false;
    proc[V[0]] = true;
    pl H[N];
    set<pair<pl, int> > hmap;
    hmap.ins({{2000000000, 2000000000}, -1});
    F0R(i, N) {
        hsh cur(base);
        F0R(j, K) {
            cur.push_back(D[j][i]);
        }
        H[i] = cur.get();
        hmap.ins({H[i], i});
    }

    hmap.erase({H[V[0]], V[0]});
    queue<int> q;
    q.push(V[0]);
    FOR(i, 1, K) {
        vi line(D[0][V[i]] + 1); F0R(j, D[0][V[i]] + 1) line[j] = -1;
        line[D[0][V[i]]] = V[i];
        line[0] = V[0];
        F0R(j, N) {
            if (D[0][j] + D[i][j] == D[0][V[i]]) {
                line[D[0][j]] = j;
            }
        }
        trav(a, line) {
            if (a == -1) {
                cout << -1 << nl; return 0;
            }
        }
        FOR(i, 1, sz(line)) {
            if (!proc[line[i]]) {
                proc[line[i]] = true;
                graph[line[i]].pb(line[i-1]); graph[line[i-1]].pb(line[i]);
                hmap.erase({H[line[i]], line[i]});
                q.push(line[i]);
            }
        }

    }


    hsh oneCur(base); F0R(i, K) oneCur.pb(1);
    pl oneHash = oneCur.get();

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        pl curHash = {H[cur].f + oneHash.f, H[cur].s + oneHash.s};
        curHash.f %= MOD; curHash.s %= MOD+2;
        while (hmap.lb({curHash, -1})->f == curHash) {
            int v = hmap.lb({curHash, -1})->s;
            hmap.erase(hmap.lb({curHash, -1}));
            q.push(v);
            graph[cur].pb(v); graph[v].pb(cur);
        }

    }

    hmap.erase(hmap.begin());
    if (!hmap.empty()) {
        cout << -1 << nl; return 0;
    }
    int dist[K][N];
    F0R(r, K) {
        F0R(i, N) {
            dist[r][i] = N+1;
        }
        dist[r][V[r]] = 0;
        q.push(V[r]);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            trav(a, graph[cur]) {
                if (dist[r][a] > dist[r][cur] + 1) {
                    dist[r][a] = dist[r][cur]+1;
                    q.push(a);
                }
            }

        }

    }
    F0R(i, K) {
        F0R(j, N) {
            if (dist[i][j] != D[i][j]) {
                cout << -1 << nl; return 0;
            }
        }
    }

    F0R(i, N) {
        trav(a, graph[i]) {
            if (a > i) continue;
            cout << i+1 << " " << a+1 << nl;
        }
    }


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343