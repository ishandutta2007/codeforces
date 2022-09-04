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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1000001; 

ll SZ = 262144*2; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (ckmin(seg[p += SZ], value) ; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = MX*10, resR = MX*10; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
int N, M;
vector<vector<bool>> A;
vector<vi> dp[2];
vector<vector<bool>> ok;
int X[400001];
vector<vi> hi;

int go(int x, int y, int d) {
    if (dp[d][x][y] != MX) return dp[d][x][y];
    dp[d][x][y] = MX+1;
    if (x != hi[x][y]) {
        if (hi[x][y] == N) return dp[d][x][y];
        return dp[d][x][y] = go(hi[x][y], y, d);
    }
    if (!A[x][y]) {
        if (x == N-1) return dp[d][x][y] = (X[y] == 0 ? y : MX+1);
        return dp[d][x][y] = go(x+1, y, d);
    } else {
        if (x > 0 && A[x-1][y]) {
            dp[d][x][y] =  go(x-1, y, d);
        } else if (d == 0 && y > 0 && ok[x][y]) {
            dp[d][x][y] = go(x, y-1, d);
        } else if (d == 1 && y < M-1 && ok[x][y]) {
            dp[d][x][y] = go(x, y+1, d);
            
        }
        if (ok[x][y] && dp[d][x][y] >= MX) {
            dp[d][x][y] = y;
        }
        return dp[d][x][y];
    }
}


vector < vector<int> > g(MX), gr(MX); //g stores graph, gr stores graph transposed
vector<bool> used;
vector<int> order, component;
int nc = 0;
vi SCC(MX);


void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

void findSCCs(int n) {

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            trav(a, component) {
                SCC[a] = nc;
            }
            nc++;
            component.clear();
        }
    }

}


void solve() {
    cin >> N >> M;
    F0R(i, 2) {
        dp[i] = vector<vi>(N, vi(M, MX));
    }
    F0R(i, 2*SZ) seg[i] = MX*10;
    A = vector<vector<bool>>(N, vector<bool>(M));
    F0R(i, N) F0R(j, M) {
        char C; cin >> C;
        A[i][j] = C == '#';
    }
    F0R(i, M) cin >> X[i];

    ok = vector<vector<bool>>(N, vector<bool>(M));
    //int bord[M]; F0R(i, M) bord[i] = M;
    F0R(i, M) {
        int rem = X[i];
        F0Rd(j, N) {
            if (rem) {
                if (A[j][i]) rem--;
            } 
            if (rem == 0) {
                ok[j][i] = true;
            }
        }
    }

    F0R(i, N) {
        F0R(j, M) {
            F0R(k, 4) {
                int x = i + dx[k], y = j + dy[k];
                if (valid(x, y, N, M) && (A[i][j] || k == 0)) {
                    //cout << i << " " << j << " to " << x << " " << y << nl;
                    g[i*M+j].pb(x*M+y);
                    gr[x*M+y].pb(i*M+j);
                }
            }
        }
    }
    hi = vector<vi>(N, vi(M));
    findSCCs(N*M);
    F0R(i, M) {
        int lst = N;
        int nxt = N-1;
        F0Rd(j, N) {
            while (nxt >= 0 && SCC[j*M+i] == SCC[nxt*M+i]) {
                if (A[nxt][i]) lst = nxt;
                nxt--;
            }
            hi[j][i] = lst;
        }
    }

    update(0, 0);

    F0R(i, M) {
        int L = go(0, i, 0), R = go(0, i, 1);
        //dbg(L,R);
        if (X[i] == 0) update(i+1, query(i, SZ-1));
        if (L >= MX || R >= MX) continue;
        update(R+1, query(L, SZ-1) + 1);
        
    }

    /*F0R(i, N) {
        F0R(j, M) {
            cout << ok[i][j];
        }
        cout << nl;
    }*/

    /*F0R(i, N) {
        F0R(j, M) {
            cout << dp[1][i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;*/
    /*F0R(i, N) {
        F0R(j, M) {
            cout << hi[i][j] << " ";
        }
        cout << nl;
    }*/


    cout << query(M, M) << nl;



}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}