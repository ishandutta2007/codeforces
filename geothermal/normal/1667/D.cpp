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
const int MX = 200001; 
vector<vi> graph(MX);
bool dp[MX][2];
bool isPoss(array<int, 4> &cnt) {
    int K = 0;
    F0R(i, 4) K += cnt[i];
    if (cnt[0] == 0 && cnt[1] + cnt[3] >= (K+1)/2 && cnt[2] + cnt[3] >= K/2) {
        return true;
    }
    return false;
}

void dfs(int v, int p) {
    array<int, 4> cnt;
    F0R(i, 4) cnt[i] = 0;
    trav(a, graph[v]) {
        if (a == p) continue;
        dfs(a, v);
        int x = 0; F0R(i, 2) if (dp[a][i]) x += 1 << i;
        cnt[x]++;
    }
    cnt[1]++;
    dp[v][0] = isPoss(cnt);
    cnt[1]--; cnt[2]++;
    dp[v][1] = isPoss(cnt);
}

void recon(int v, int p, int t) {
    vector<int> vals[4];
    int K = 0;
    trav(a, graph[v]) {
        if (a == p) continue;
        int x = 0; F0R(i, 2) if (dp[a][i]) x += 1 << i;
        vals[x].pb(a);
        K++;
    }
    if (t != -1) {
        K++;
    }
    int numOdds = (K+1)/2;
    int numEvens = K/2;
    if (t == 0) {
        numOdds--;
    } else numEvens--;
    trav(a, vals[3]) {
        if (sz(vals[1]) < numOdds) {
            vals[1].pb(a);
        } else vals[2].pb(a);
    }
    while (K) {
        if (K % 2 && t == 0) {
            cout << v+1 << " " << p+1 << nl;
            t = -1;
        } else if (K % 2 == 0 && t == 1) {
            cout << v+1 << " " << p+1 << nl;
            t = -1;
        } else if (K % 2) {
            int cur = vals[1].back(); vals[1].pop_back();
            recon(cur, v, 0);
        } else {
            int cur = vals[2].back(); vals[2].pop_back();
            recon(cur, v, 1);
        }
        K--;
    }

}

void solve() {
    int N; cin >> N;
    graph = vector<vi>(N);
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    dfs(0, -1);
    array<int, 4> cnt;
    F0R(i, 4) cnt[i] = 0;
    trav(a, graph[0]) {
        int x = 0; F0R(i, 2) if (dp[a][i]) x += 1<<i;
        cnt[x]++;
    }
    cout << (isPoss(cnt)?"YES":"NO") << nl;
    if (isPoss(cnt)) recon(0, -1, -1);


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}