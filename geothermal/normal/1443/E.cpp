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

vector<vi> perms;
int cp, cp2;
vi perm;

const int K = 9;
void solve() {
    ll N, Q; cin >> N >> Q;
    vi curPerm; F0R(i, K) curPerm.pb(i);
    perms.pb(curPerm);
    while (next_permutation(all(curPerm))) {
        perms.pb(curPerm);
    }
    F0R(i, N) perm.pb(i+1);
    cp = 0;
    cp2 = 0;



    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            ll L, R; cin >> L >> R;
            ll ans = 0;
            ll l1 = L, r1 = min(R, N-2*K);
            if (l1 <= r1) {
                ans += (l1 + r1) * (r1 - l1 + 1) / 2;
            }
            ll l2 = max(L, N-2*K+1), r2 = min(R, N-K);
            if (l2 <= r2) {
                FOR(i, l2, r2+1) {
                    ans += perm[N-2*K  +perms[cp2][i-N-1+2*K]];
                }
            }
            ll l3 = max(L, N-K+1), r3 = min(R, N);
            if (l3 <= r3) {
                FOR(i, l3, r3+1) {
                    ans += perm[N-K+perms[cp][i-N-1+K]];
                }
            }
            cout << ans << nl;
        } else if (T == 2) {
            ll V; cin >> V;
            cp += V;
            F0R(i, cp / sz(perms)) {
                //dbg("TEST");
                reverse(perm.end()-min((ll)K, N), perm.end());
                //dbg(perm);
                next_permutation(perm.end() - min((ll) 2*K, N), perm.end());
                //dbg(perm);
                //dbg("DONE");
            }
            //cp2 += cp / sz(perms);
            cp %= sz(perms);
        }
    }
    //dbg(cp, perms[cp]);
    //dbg(cp2, perms[cp2]);
    //dbg(perm);


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