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
const int MX = 100001; 

char ans[100][100];
set<char> chars;
int N, M;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
set<char> ops;

void clear(int x, int y) {
    F0R(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && ans[nx][ny] != '?') {
            ops.erase(ans[nx][ny]);
        }
    }
}

void add(int x1, int y1, int x2, int y2) {
    ops = chars;
    clear(x1, y1); clear(x2, y2);
    char C = *ops.begin();
    ans[x1][y1] = C; ans[x2][y2] = C;
}

void solve() {
    cin >> N >> M;
    int H; cin >> H;
    int V = N*M/2 - H;
    F0R(i, N) F0R(j, M) ans[i][j] = '?';
    if (N%2) {
        F0R(i, M/2) {
            add(N-1, i*2, N-1, i*2+1);
            H--;
        }
    }
    if (M%2) {
        F0R(i, N/2) {
            add(i*2, M-1, i*2+1, M-1);
            V--;
        }
    }
    if (H < 0 || V < 0 || H % 2) {
        cout << "NO" << nl; return;
    }
    F0R(i, (N-N%2)/2) {
        F0R(j, (M-M%2)/2) {
            if (V) {
                V -= 2;
                add(i*2, j*2, i*2+1, j*2);
                add(i*2, j*2+1, i*2+1, j*2+1);
            } else {
                H -= 2;
                add(i*2, j*2, i*2, j*2+1);
                add(i*2+1, j*2, i*2+1, j*2+1);
            }
        }
    }

    cout << "YES" << nl;

    F0R(i, N) {
        F0R(j, M) {
            cout << ans[i][j];
        }
        cout << nl;
    }

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    F0R(i, 26) chars.ins('a'+i);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}