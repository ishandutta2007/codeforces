#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
const int MX = 100001; 

vi L;
vpi t1[26], t2[26][26], t3[26][26][26];

void go(vi cur) {
    int p = sz(L);
    L.pb(sz(cur));
    F0R(i, sz(cur)) {
        t1[cur[i]].pb({p, i});
    }
    F0R(i, sz(cur) - 1) {
        t2[cur[i]][cur[i+1]].pb({p, i});
    }
    F0R(i, sz(cur) - 2) {
        t3[cur[i]][cur[i+1]][cur[i+2]].pb({p, i});
    }
}

void solve() {
    int dist[sz(L)];
    F0R(i, sz(L)) dist[i] = 0;
    int N; cin >> N;
    string T[N]; F0R(i, N) cin >> T[i];
    F0R(i, N) {
        string S = T[i];
        vi cur; trav(a, S) cur.pb(a-'a');
        vpi trans;
        if (sz(cur) == 1) {
            trans = t1[cur[0]];
        } else if (sz(cur) == 2) {
            trans = t2[cur[0]][cur[1]];
        } else {
            trans = t3[cur[0]][cur[1]][cur[2]];
        }
        trav(a, trans) {
            if (dist[a.f] >= a.s) {
                ckmax(dist[a.f], a.s+sz(cur));
                if (dist[a.f] == L[a.f]) {
                    cout << "YES" << nl; return;
                }
            }
        }
    }

    cout << "NO" << nl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F0R(i, 26) {
        go({i});
        go({i, i});
        F0R(j, 26) {
            go({i, j, j, i});
            go({i, j, i});
            F0R(k, 26) {
                go({i, j, k, k, j, i});
                go({i, j, k, j, i});

            }
        }
    }
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}