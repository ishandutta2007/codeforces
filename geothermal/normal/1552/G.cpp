#include <bits/stdc++.h>
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
const int MX = 11; 

set<pair<ll, int>> done;
vl vals[MX];
int cnt[MX];
int N, K; 
set<ll> ok;

void dfs(ll m, int p) {
    /*pair<ll, int> cur = {m, p};
    if (done.count(cur)) return;
    //dbg(m, p);
    done.ins(cur);*/
    if (p == K) {
        if (!ok.count(m)) {
            cout << "REJECTED" << nl; exit(0);
        }
        return;
    }
    ll M = vals[p][sz(vals[p])-1];
    int lo = __builtin_popcountll(m&M);
    int hi = lo + cnt[p];
    FOR(i, lo, hi+1) {
        dfs((m&(~M))|vals[p][i], p+1);
    }
}

void solve() {
    cin >> N >> K;
    vector<vi> A(K);
    bool found[N]; F0R(i, N) found[i] = false;
    F0R(i, K) {
        int Q; cin >> Q;
        A[i] = vi(Q);
        ll cm = 0;
        vals[i].pb(0);
        F0R(j, Q) {
            cin >> A[i][j]; A[i][j]--;
            if (!found[A[i][j]]) {
                found[A[i][j]] = true;
                cnt[i]++;
            }
        }
        F0Rd(j, Q) {
            cm |= 1ll<<A[i][j];
            vals[i].pb(cm);
        }
    }
    if (N == 1) {
        cout << "ACCEPTED" << nl; return;
    }
    F0R(i, N) {
        if (!found[i]) {
            cout << "REJECTED" << nl; return;
        }
    }
    ll cur = 0;
    ok.ins(0);
    F0Rd(i, N) {
        cur += (1ll << i);
        ok.ins(cur);
    }

    dfs(0, 0);

    cout << "ACCEPTED" << endl;
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