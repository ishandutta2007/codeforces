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

const pair<pi, int> BAD = {{-1, -1}, -1};

void solve() {
    int N, M; cin >> N >> M;
    pair<pi, int> v2[10][10], v3[10][10][10];
    F0R(i, 10) {
        F0R(j, 10) {
            v2[i][j] = BAD;
            F0R(k, 10) v3[i][j][k] = BAD;
        }
    }
    F0R(i, N) {
        string S; cin >> S;
        F0R(j, M-1) {
            v2[S[j]-'0'][S[j+1]-'0'] = {{j+1, j+2}, i+1};
        }
        F0R(j, M-2) {
            v3[S[j]-'0'][S[j+1]-'0'][S[j+2]-'0'] = {{j+1, j+3}, i+1};
        }
    }

    string S; cin >> S;
    N = sz(S);
    int lst[N+1]; F0R(i, N+1) lst[i] = -1;
    lst[0] = 0;
    F0R(i, N) {
        if (lst[i] == -1) continue;
        if (i < N-1 && v2[S[i]-'0'][S[i+1]-'0'] != BAD) {
            lst[i+2] = i;
        }
        if (i < N-2 && v3[S[i]-'0'][S[i+1]-'0'][S[i+2]-'0'] != BAD) {
            lst[i+3] = i;
        }
    }

    if (lst[N] == -1) {
        cout << -1 << nl; return;
    }
    vector<pair<pi, int>> ans;
    int cur = N;
    while (cur > 0) {
        if (lst[cur] == cur-2) {
            cur = cur-2;
            ans.pb(v2[S[cur]-'0'][S[cur+1]-'0']);
        } else {
            cur = cur - 3;
            ans.pb(v3[S[cur]-'0'][S[cur+1]-'0'][S[cur+2]-'0']);
        }
    }
    reverse(all(ans));
    cout << sz(ans) << nl;
    F0R(i, sz(ans)) {
        cout << ans[i].f.f << " " << ans[i].f.s << " " << ans[i].s << nl;
    }

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