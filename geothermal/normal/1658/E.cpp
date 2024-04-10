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
    int N, K; cin >> N >> K;
    bool win[N][N]; F0R(i, N) F0R(j, N) win[i][j] = false;
    bool ok[N][N]; F0R(i, N) F0R(j, N) ok[i][j] = true;
    vpi posA, posB;
    F0R(i, N) {
        F0R(j, N) {
            posA.pb({i, j});
            posB.pb({i, j});
        }
    }
    sort(all(posA), [](const pi &a, const pi &b) {
            return a.f+a.s < b.f+b.s;
            });
    sort(all(posB), [](const pi &a, const pi &b) {
            return a.f-a.s < b.f-b.s;
            });

    int A[N][N]; F0R(i, N) F0R(j, N) cin >> A[i][j];
    vector<pair<int, pi>> pos;
    F0R(i, N) {
        F0R(j, N) {
            pos.pb({A[i][j], {i, j}});
        }
    }
    sort(all(pos));
    reverse(all(pos));

    int p1l = 0, p1r = N*N-1, p2l = 0, p2r = N*N-1;

    //dbg(posA, posB);
    trav(a, pos) {
        int x = a.s.f, y = a.s.s;
        if (ok[x][y]) {
            win[x][y] = true;

            while (p1l <= p1r && posA[p1l].f + posA[p1l].s < x + y - K) {
                ok[posA[p1l].f][posA[p1l].s] = false;
                p1l++;
            }
            while (p1l <= p1r && posA[p1r].f + posA[p1r].s > x+y+K) {
                ok[posA[p1r].f][posA[p1r].s] = false;
                p1r--;
            }
            while (p2l <= p2r && posB[p2l].f - posB[p2l].s < x - y - K) {
                ok[posB[p2l].f][posB[p2l].s] = false;
                p2l++;
            }
            while (p2l <= p2r && posB[p2r].f - posB[p2r].s > x-y+K) {
                ok[posB[p2r].f][posB[p2r].s] = false;
                p2r--;
            }

            
        }

        /*cout << x << " " << y << nl;
        F0R(i, N) {
            F0R(j, N) {
                cout << ok[i][j];
            }
            cout << nl;
        }*/


    }

    F0R(i, N) {
        F0R(j, N) {
            if (win[i][j]) {
                cout << 'M';
            } else cout << 'G';
        }
        cout << nl;
    }



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