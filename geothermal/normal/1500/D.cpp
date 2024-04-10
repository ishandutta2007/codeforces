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
const int MX = 1500; 
int N;
int nxtI[MX][MX][11], nxtJ[MX][MX][11], nxtG[MX][MX][11];

int cost(int p1, int p2) {
    return max(p2/(N+1)-p1/(N+1), p2%(N+1)-p1%(N+1));
}

void solve() {
    int Q; cin >> N >> Q;
    F0R(i, N) F0R(j, N) F0R(k, Q+1) {
        nxtI[i][j][k] = N;
        nxtJ[i][j][k] = N;
        nxtG[i][j][k] = (N+1)*N+N;
    }
    int A[(N+1)*(N+1)]; 
    F0R(i, (N+1)*(N+1)) A[i] = -1;
    F0R(i, N) F0R(j, N) cin >> A[i*(N+1)+j];
    int ans[N]; F0R(i, N) ans[i] = 0;
    bool found[N*N+1]; F0R(i, N*N+1) found[i] = false;
    F0Rd(i, N) {
        F0Rd(j, N) {
            //dbg("START");
            
            //step 1: nxtI
            nxtI[i][j][0] = i;
            int np = 1;
            if (i < N-1) {
                F0R(k, Q+1) {
                    if (np <= Q && A[nxtI[i+1][j][k]*(N+1)+j] != A[i*(N+1)+j]) {
                        nxtI[i][j][np] = nxtI[i+1][j][k]; np++;
                    }
                }
            }
            //dbg("DONE I");
            nxtJ[i][j][0] = j;
            np = 1;
            if (j < N-1) {
                F0R(k, Q+1) {
                    if (np <= Q && A[nxtJ[i][j+1][k] + i * (N+1)] != A[i*(N+1)+j]) {
                        nxtJ[i][j][np] = nxtJ[i][j+1][k]; np++;
                    }
                }
            }
            //dbg("DONE J");
            np = 0;
            int p1 = 0, p2 = 0, p3 = 0;
            while (np <= Q) {
                //dbg("STA");
                int c1 = N+2, c2 = N+2, c3 = N+2;

                if (p1 <= Q) {
                    c1 = nxtI[i][j][p1] - i;
                }
                if (p2 <= Q) {
                    c2 = nxtJ[i][j][p2] - j;
                }
                if (p3 <= Q && i < N-1 && j < N-1) {
                    c3 = cost(i*(N+1)+j, nxtG[i+1][j+1][p3]);
                }
                /*if (i == 1 && j == 0 && np == 2) {
                    dbg(c1, c2, c3);
                    dbg(p3, nxtG[i+1][j+1][p3]/(N+1), nxtG[i+1][j+1][p3]%(N+1));
                }*/
              //dbg("FC");
                int mc = min(c1, min(c2, c3));
                if (mc == N+2) break;
                int v = -1;
                if (c1 == mc) {
                    v = nxtI[i][j][p1]*(N+1)+j;
                    p1++;
                } else if (c2 == mc) {
                    v = nxtJ[i][j][p2]+i*(N+1);
                    p2++;
                } else {
                    v = nxtG[i+1][j+1][p3];
                    p3++;
                }
                //dbg("IDV", v, A[v]);
                /*if (i == 2 && j == 2) {

                    dbg(v/(N+1), v%(N+1), A[v], found[A[v]]);
                }*/
                if (A[v] != -1 && !found[A[v]]) {
                    found[A[v]] = true;
                    nxtG[i][j][np] = v;
                    /*if (i == 2 && j == 2) {
                        dbg("FOUND");
                    }*/
                    np++;
                }

            }
            //dbg("DONE MERGE");
            F0R(k, p1) found[A[nxtI[i][j][k]*(N+1)+j]] = false;
            F0R(k, p2) found[A[nxtJ[i][j][k]+i*(N+1)]] = false;
            F0R(k, p3) found[A[nxtG[i+1][j+1][k]]] = false;
            //dbg("DONE LAST");

            int cp = nxtG[i][j][Q];
            //dbg(i, j, cp/(N+1), cp%(N+1), min(max(cp/(N+1)-i, cp%(N+1)-j), min(N-i, N-j)));
            ans[min(max(cp/(N+1)-i,cp%(N+1)-j), min(N-i, N-j))-1]++;
        }
    }

    /*F0R(i, Q+1) {
        dbg(nxtG[1][0][i]/(N+1), nxtG[1][0][i]%(N+1), A[nxtG[1][0][i]]);
        dbg(nxtJ[1][0][i], A[nxtJ[1][0][i]+N+1]);
    }*/


    int res[N];
    int cs = 0;
    F0Rd(i, N) {
        cs += ans[i]; res[i] = cs;
    }
    F0R(i, N) {
        cout << res[i] << nl;
    }

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