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

int N;
ll A, B, C;
string S;

ll go() {
    ll cur = 0;
    vi comps;
    int fp = N, lp = N;
    int numOnes = 0;
    F0R(i, N) {
        if (S[i] == '1') {
            if (fp == N) fp = i;
            lp = i;
            if (i > 0 && S[i-1] == '1') numOnes++;
        }
    }
    if (fp == N) return (N>1?A:0);

    int cnt = 0;
    FOR(i, fp, lp+1) {
        if (S[i] == '1') {
            if (cnt) {
                comps.pb(cnt);
                cnt = 0;
            }
        } else cnt++;
    }
    sort(all(comps));
    comps.pb(fp);
    comps.pb(N - lp - 1);
    int numEx = 0;
    int numBo = 0;
    ll bst = 0;

    int p = 0;
    while (true) {
        while (p < sz(comps) && comps[p] <= 1) {
            if (p < sz(comps) - 2) { 
                numEx++;
            } else if (comps[p]) numBo++;
            p++;
        }
        if (p < sz(comps) && numOnes) {
            cur += A + B;
            numOnes--;
            comps[p]--;
        } else {
            if (p < sz(comps)) {
                ckmax(bst, cur + A);
            }
            if (numEx) {
                cur += B - C;
                numEx--;
            } else if (numBo && numOnes) {
                cur += B - C;
                numBo--;
                numOnes--;
            } else {
                break;
            }
        }
        ckmax(bst, cur);
    }
    return bst;

}

void solve() {
    cin >> N;
    cin >> A >> B >> C;
    cin >> S;
    
    ll ans = 0;
    ans = go();
    bool ok = false;
    F0R(i, N-1) {
        if (S[i] == '1' && S[i+1] == '1') {
            string T;
            F0R(j, i+1) T += S[j];
            FOR(j, i+2, N) T += S[j];
            S = T;
            N--;
            ok = true;
            break;
        }
    }
    if (ok) ckmax(ans, go() + B);
    cout << ans << nl;

    

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}