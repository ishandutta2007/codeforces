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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
void solve() {
    int N; cin >> N; int K; cin >> K;
    int dist[(K+1)*(K+1)]; F0R(i, K+1) F0R(j, K+1) dist[i*(K+1)+j] = MOD;

    int cost[(K+1)*(K+1)][4]; 
    F0R(i, (K+1)*(K+1)) F0R(j, 4) cost[i][j] = 0;
    F0R(i, N) {
        int A, B, C, D; cin >> A >> B >> C >> D;
        if (A != C) {
            if (A > C) swap(A, C);
            cost[A*(K+1)+B-1][1]++;
            cost[A*(K+1)+B][3]++;
        } else {
            if (B > D) swap(B, D);
            cost[(A-1)*(K+1)+B][0]++;
            cost[A*(K+1)+B][2]++;
        }
    }

    int nops = 0;
    pqg<pi> q;
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().s;
        int d = q.top().f;
        nops++;
        //assert(nops < (K+1)*(K+1)*20);
        q.pop();
        if (d != dist[v]) continue;
        F0R(i, 4) {
            int x = v / (K+1);
            int y = v % (K+1);
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny, K+1, K+1) && ckmin(dist[nx*(K+1)+ny], d + cost[v][i] + cost[(K-x)*(K+1)+(K-y)][(i+2)%4])) {
                q.push({dist[nx*(K+1)+ny], nx*(K+1)+ny});
            }
        }

    }
    /*F0R(i, K+1) {
        F0R(j, K+1) {
            cout << dist[i*(K+1)+j] << " ";
        }
        cout << nl;
    }

    F0R(i, K+1) {
        F0R(j, K+1) {
            cout << i << " " << j << " ";
            F0R(k, 4) {
                cout << cost[i*(K+1)+j][k] << " ";
            }
            cout << nl;
        }
    }*/
    cout << N - dist[(K/2)*(K+1) + K/2] << nl;


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