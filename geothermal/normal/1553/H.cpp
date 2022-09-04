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
const int MX = 1 << 20; 
const int INF = 1 << 24;

int best[20];
int L[MX], R[MX], lo[MX], hi[MX];
int K;

void pull(int X) {
    best[X] = INF;
    FOR(i, 1 << X, 1 << (X+1)) {
        lo[i] = min(lo[L[i]], lo[R[i]] + (1 << (K-X-1)));
        hi[i] = max(hi[L[i]], hi[R[i]] + (1 << (K-X-1)));
        ckmin(best[X], lo[R[i]] + (1 << (K-X-1)) - hi[L[i]]);
    }

}

void flip(int X) {
    FOR(i, 1 << X, 1 << (X+1)) {
        swap(L[i], R[i]);
    }
    F0Rd(i, X+1) {
        pull(i);
    }
}

void solve() {
    int N; cin >> N >> K;
    F0R(i, 1 << (K+1)) {
        L[i] = 2*i; R[i] = 2*i+1;
        lo[i] = INF;
        hi[i] = -INF;
    }

    F0R(i, 20) best[i] = INF;
    F0R(i, N) {
        int X; cin >> X;
        lo[(1<<K)+X] = 0;
        hi[(1<<K)+X] = 0;
    }
    F0Rd(i, K) pull(i);
    /*FOR(i, 1, 1 << (K+1)) {
        dbg(i, L[i], R[i], lo[i], hi[i]);
    }*/
    vpi ord;
    F0R(i, 1 << K) {
        int X = i;
        int res = 0;
        F0R(j, K) {
            res *= 2; res += X%2; X /= 2;
        }
        ord.pb({res, i});
    }
    sort(all(ord));
    int res[1<<K]; 
    F0R(it, 1 << K) {
        int i = ord[it].s;
        //dbg(i);
        if (it > 0) {
            int lst = ord[it-1].s;
            lst ^= i;
            F0R(j, K) {
                if (lst & (1 << j)) {
                    flip(K-1-j);
                }
            }
        }
        int ans = INF;
        F0R(j, K) ckmin(ans, best[j]);
        res[i] = ans;
    }
    F0R(i, 1 << K) {
        cout << res[i] << " ";
    }
    cout << nl;

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