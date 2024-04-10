#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dist[40][1010000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, K; cin >> N >> M >> K;
    int A[N][M]; F0R(i, N) F0R(j, M) cin >> A[i][j];
    F0R(i, N) F0R(j, M) A[i][j]--;
    vector<vi> graph(N*M+K);
    F0R(i, N) {
        F0R(j, M) {
            graph[A[i][j]].pb(K+i*M+j);
            graph[K+i*M+j].pb(A[i][j]);
            F0R(k, 4) {
                if (valid(i+dx[k], j+dy[k], N, M)) {
                    graph[K+i*M+j].pb((i+dx[k])*M+K+j+dy[k]);
                }
            }
        }
    }

    F0R(k, K) {
        F0R(i, N*M+K) dist[k][i] = 1000000000;
        dist[k][k] = 0;
        vi cur, nxt, nxt2;
        cur.pb(k);
        while (!cur.empty() || !nxt.empty() || !nxt2.empty()) {

            trav(x, cur) {
                trav(y, graph[x]) {
                    int D = 2;
                    if (x < K || y < K) D = 1;
                    if (dist[k][y] > dist[k][x] + D) {
                        dist[k][y] = dist[k][x] + D;
                        if (D == 1) {
                            nxt.pb(y);
                        } else {
                            nxt2.pb(y);
                        }
                    }
                }
            }

            cur = nxt;
            nxt = nxt2;
            nxt2.clear();
        }
    }
    int Q; cin >> Q;

    F0R(q, Q) {
        int W, X, Y, Z; cin >> W >> X >> Y >> Z; W--; X--; Y--; Z--;
        int ans = abs(W-Y) + abs(X-Z);
        F0R(i, K) {
            ckmin(ans, (dist[i][K+W*M+X] + dist[i][K+Y*M+Z]) / 2);
        }
        cout << ans << nl;
    }


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343