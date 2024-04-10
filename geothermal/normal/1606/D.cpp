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
const int MX = 1000001; 

void solve() {
    int N, M; cin >> N >> M;
    int A[N][M]; F0R(i, N) F0R(j, M) cin >> A[i][j];
    int suffMax[N][M], suffMin[N][M];
    F0Rd(i, M) {
        F0R(j, N) {
            suffMax[j][i] = A[j][i];
            if (i < M-1) ckmax(suffMax[j][i], suffMax[j][i+1]);
            suffMin[j][i] = A[j][i];
            if (i < M-1) ckmin(suffMin[j][i], suffMin[j][i+1]);
        }
    }

    set<int> reds; F0R(i, N) reds.ins(i);
    multiset<int> maxRedAfter[M], minBlueAfter[M];
    multiset<int> smallReds, largeBlues;
    F0R(i, N) {
        F0R(j, M) {
            maxRedAfter[j].ins(suffMax[i][j]);
        }
    }

    vector<pair<int, pi>> vals;
    F0R(i, N) {
        F0R(j, M) {
            vals.pb({A[i][j], {i, j}});
        }
    }

    sort(all(vals));
    F0R(it, sz(vals)) {
        int x = vals[it].s.f, y = vals[it].s.s;
        int v = vals[it].f;
        //dbg(x, y, v);
        if (y == 0) {
            //x is blue now
            //previously was large red, now is small blue
            reds.erase(x);
            F0R(i, M) {
                maxRedAfter[i].erase(maxRedAfter[i].find(suffMax[x][i]));
                minBlueAfter[i].ins(suffMin[x][i]);
            }
            //dbg("TESTYTEST", smallReds);
            FOR(i, 1, M) {
                if (A[x][i] >= v) {
                    largeBlues.ins(i);
                } else if (A[x][i] < v) {
                    smallReds.erase(smallReds.find(i));
                }
            }
        }
        //dbg("TEST");
        if (reds.count(x)) {
            smallReds.ins(y);
        } else if (y != 0) {
            largeBlues.erase(largeBlues.find(y));
        }
        //dbg("TEST2", smallReds);
        
        if (sz(reds) != 0 && sz(reds) != N && (it == sz(vals) - 1 || v != vals[it+1].f)) {
            int cut = M;
            if (sz(smallReds)) ckmin(cut, *smallReds.begin());
            if (sz(largeBlues)) ckmin(cut, *largeBlues.begin());
            int mra = *maxRedAfter[cut].rbegin();
            int mba = *minBlueAfter[cut].begin();
            if (cut != 0 && cut != M && mra < mba) {
                //dbg(maxRedAfter[cut], minBlueAfter[cut]);
                cout << "YES" << nl;
                string S; F0R(i, N) S += "B";
                trav(a, reds) S[a] = 'R';
                cout << S << " " << cut << nl;
                return;
            }
        }
        //dbg("TEST3");
    }
    cout << "NO" << nl;


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