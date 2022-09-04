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

void solve() {
    int N; cin >> N;
    vector<vi> G(N*2);
    F0R(i, N*2) {
        int X, Y; cin >> X >> Y; X--; Y--;
        G[X].pb(Y); G[Y].pb(X);
    }

    bool vis[2*N]; F0R(i, 2*N) vis[i] = false;
    vector<vi> cyc;
    F0R(i, N) {
        if (vis[i]) continue;
        int v = i;
        vi cur; cur.pb(v);
        vis[v] = true;
        v = G[v][0];
        while (v != i) {
            cur.pb(v);
            vis[v] = true;
            if (G[v][0] == cur[sz(cur) - 2]) {
                v = G[v][1];
            } else v = G[v][0];
        }
        cyc.pb(cur);
    }
    //dbg(cyc);

    ll ans = 0;
    trav(c, cyc) {
        int K = sz(c);
        F0R(i, K) {
            int hx = -1, lx = MX, hy = -1, ly = MX;
            F0R(d, K) {
                int j = i + d;
                if (d == K-1 && i != 0) break;
                int p = j%K;
                if (c[p] < N) {
                    ckmax(hx, c[p]);
                    ckmin(lx, c[p]);
                } else {
                    ckmax(hy, c[p] - N);
                    ckmin(ly, c[p] - N);
                }
                int blx = -1, bhx = N, bhy = N, bly = -1;
                vi pos = {(j+1)%K, (i+K-1)%K};
                if (d != K-1) {
                    trav(b, pos) {
                        int a = c[b];
                        if (a < N) {
                            if (lx < a && a < hx) goto done;
                            if (lx > a) ckmax(blx, a);
                            if (a > hx) ckmin(bhx, a);
                        } else {
                            a -= N;
                            if (ly < a && a < hy) goto done;
                            if (ly > a) ckmax(bly, a);
                            if (a > hy) ckmin(bhy, a);
                        }
                    }
                }
                /*if (i == 0 && j == 1) {
                    dbg(lx, hx, ly, hy, blx, bhx, bly, bhy, pos);
                }*/
                if (d > 0 && blx < lx && bhx > hx && bly < ly && bhy > hy) {
                    ans += ((ll) d+1)/2 * (lx-blx) * (bhx - hx) * (ly - bly) * (bhy - hy);
                }

                done:
                ;
            }
        }
    }
    cout << ans << nl;

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