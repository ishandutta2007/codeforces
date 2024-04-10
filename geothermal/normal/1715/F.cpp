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

const string eps = "0.000000000000001";

vd getPoly(int N, int M) {
    vd res;
    res.pb(0); res.pb(0);
    F0R(i, N-1) {
        res.pb(i); res.pb(M);
        res.pb(i+1); res.pb(-1);
    }
    res.pb(N-1); res.pb(M);
    res.pb(N); res.pb(0);
    return res;
}

ld get(ld over, int N) {
    ld lo = 0, hi = N-1;
    F0R(iter, 100) {
        ld mid = (lo+hi)/2;
        ld lh = 1-mid/N;
        ld hh = 1-(mid+1)/N;
        if ((lh+hh)/2 > over) {
            lo = mid;
        } else hi = mid;
    }
    return lo;
}

void solve() {
    int N, M; cin >> N >> M;
    cout << fixed;
    cout << setprecision(15);
    vd p1 = getPoly(N, M);
    cout << "? " << sz(p1)/2 << endl;
    F0R(i, sz(p1) / 2) {
        if (p1[i*2] < -0.5) {
            cout << eps << " ";
        } else cout << p1[i*2] << " ";
        if (p1[i*2+1] < -0.5) {
            cout << eps << endl;
        } else cout << p1[i*2+1] << endl;

    }

    ld a1; cin >> a1;
    ld x = get(a1, M);
    vd p2 = getPoly(M, N);
    cout << "? " << sz(p2) / 2 << endl;
    F0R(i, sz(p2) / 2) {
        if (p2[i*2+1] < -0.5) {
            cout << eps << " ";
        } else cout << p2[i*2+1] << " ";
        if (p2[i*2] < -0.5) {
            cout << eps << endl;
        } else cout << p2[i*2] << endl;

    }
    ld a2; cin >> a2;
    ld y = get(a2, N);
    cout << "! " << y << " " << x << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}