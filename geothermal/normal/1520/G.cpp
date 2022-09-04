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

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
void solve() {
    int N, M; cin >> N >> M;
    ll W; cin >> W;
    int A[N][M]; F0R(i, N) F0R(j, M) cin >> A[i][j];

    int dist1[N][M], dist2[N][M];
    F0R(i, N) {
        F0R(j, M) {
            dist1[i][j] = 1e9;
            dist2[i][j] = 1e9;
        }
    }
    queue<pi> q;
    q.push({0, 0});
    dist1[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s; q.pop();
        F0R(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny, N, M) && A[nx][ny] != -1 && ckmin(dist1[nx][ny], dist1[x][y]+1)) {
                q.push({nx, ny});
            }
        }
    }
    q.push({N-1, M-1});
    dist2[N-1][M-1] = 0;
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s; q.pop();
        F0R(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny, N, M) && A[nx][ny] != -1 && ckmin(dist2[nx][ny], dist2[x][y]+1)) {
                q.push({nx, ny});
            }
        }
    }

    ll ans = 1e18;
    if (dist1[N-1][M-1] < 1e8) {
        ans = dist1[N-1][M-1] * W;
    }
    ll tp = 1e18, fp = 1e18;
    F0R(i, N) {
        F0R(j, M) {
            if (dist1[i][j] < 1e8 && A[i][j] > 0) {
                ckmin(tp, dist1[i][j] * W + A[i][j]);
            }
            if (dist2[i][j] < 1e8 && A[i][j] > 0) {
                ckmin(fp, dist2[i][j] * W + A[i][j]);
            }
        }
    }
    ckmin(ans, tp+fp);
    if (ans < 1e17) {
        cout << ans << nl;
    } else cout << -1 << nl;

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