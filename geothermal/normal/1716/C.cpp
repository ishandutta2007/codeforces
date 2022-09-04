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


const ll MOD = 1e15;
const char nl = '\n';
const int MX = 100001; 

void solve() {
    int M; cin >> M;
    ll A[2][M]; F0R(i, 2) F0R(j, M) cin >> A[i][j];
    ll res = MOD;
    ll cur = 2*M-1;
    A[0][0] = -MOD;
    ll nvis = 0;
    ll suffMax[2][M+1], suffMin[2][M+1];
    F0R(i, 2) {
        suffMax[i][M] = -MOD;
        suffMin[i][M] = -MOD;
        F0Rd(j, M) {
            suffMax[i][j] = max(suffMax[i][j+1], A[i][j] + j);
            suffMin[i][j] = max(suffMin[i][j+1], A[i][j] - j);
        }
    }
    F0R(j, M) {
        vi ord = {0, 1};
        if (j % 2) ord = {1, 0};
        trav(i, ord) {
            ckmax(cur, 2*M-nvis+A[i][j]);
            nvis++;
            ll cans = cur;
            //cout << i << " " << j << " cur " << cans << nl;
            ll visInOther = j;
            if (i == ord[1]) visInOther++;
            ckmax(cans, 2*M-visInOther+suffMin[i][j]);
            //cout << i << " " << j << " " << 2*M-visInOther+suffMin[i][j] << nl;
            ckmax(cans, suffMax[1-i][visInOther]-visInOther + 1);
            //cout << i << " " << j << " " << suffMax[1-i][visInOther] - visInOther << nl;
            ckmin(res, cans);
        }

    }
    cout << res << nl;

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