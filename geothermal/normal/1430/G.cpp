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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    vector<vpl> graph(N);
    F0R(i, M) {
        ll X, Y, W; cin >> X >> Y >> W; X--; Y--; 
        graph[Y].pb({X, W});
    }

    int ord[N]; 
    int ced[N]; F0R(i, N) ced[i] = 0;
    F0R(i, N) trav(a, graph[i]) ced[a.f]++;
    queue<int> q;
    int nxt = 0;
    F0R(i, N) {
        if (ced[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ord[nxt] = x; nxt++;
        trav(a, graph[x]) {
            ced[a.f]--;
            if (ced[a.f] == 0) {
                q.push(a.f);
            }
        }
    }

    int trans[1 << N];
    ll cost[1 << N];
    bool ed[1 << N][N]; F0R(i, 1 << N) F0R(j, N) ed[i][j] = false;
    F0R(m, 1 << N) {
        ll ct = 0, cc = 0;
        int ce[N]; F0R(i, N) ce[i] = 0;
        F0R(i, N) trav(a, graph[i]) ce[a.f]++;
        F0R(i, N) {
            if (m & (1 << i)) {
                ct |= 1 << i;
                trav(a, graph[i]) {
                    if (!(m & (1 << a.f))) {
                        ce[a.f]--;
                        cc += a.s;
                    }
                }
            }
        }
        F0R(i, N) {
            if (ce[i] == 0) {
                ed[m][i] = true;
            }
        }
        cost[m] = cc;
        trans[m] = ct;
    }
    
    ll dp[N+1][1 << N];
    ll lst[N+1][1 << N];
    int val[1 << N];
    F0R(i, N+1) {
        F0R(j, 1 << N) {
            val[j] = N+1;
            dp[i][j] = 1e18;
            lst[i][j] = 0;
        }
    }
    dp[0][0] = 0;
    val[0] = 0;
    FOR(i, 1, N+1) {
        F0R(m, 1 << N) {
            dp[i][m] = dp[i-1][m] + cost[m];
            lst[i][m] = m;
        }
//        cout << "Starting " << i << nl;
        F0Rd(j, N) {
            int x = ord[j];
            F0R(m, 1 << N) {
                if ((m & (1 << x)) != 0 || !ed[m][x]) continue;
//                cout << "Transitioning " << m << " " << m+(1 << x) << nl;
                if (ckmin(dp[i][m+(1<<x)], dp[i][m])) {
                    lst[i][m+(1<<x)] = lst[i][m];
                }
            }
        }
/*        F0R(m, 1 << N) {
            if (val[m] != i) continue;
            ckmin(dp[i+1][trans[m]], dp[i][m] + cost[m]);
            if (dp[i+1][trans[m]] == dp[i][m] + cost[m]) {
                val[trans[m]] = i+1;
                lst[i+1][trans[m]] = m;
            }
        }

        F0Rd(m, 1 << N) {
            if (val[m] <= i) continue;
            F0R(a, N) {
                if ((m & (1 << a)) == 0) {
                    if (val[m+(1 << a)] != i+1) continue;
                    if (ckmin(dp[i+1][m], dp[i+1][m+(1<<a)])) {
                        val[m] = i+1;
                        lst[i+1][m] = lst[i+1][m + (1<<a)];
                    }
                }
            }
        }*/
    }

/*    F0R(i, N+1) {
        F0R(j, 1 << N) {
            cout << "step " << i << " mask " << j << ": " << dp[i][j] << " " << lst[i][j] << nl;
        }
    }*/

    ll cur = 1 << N; cur--;
    int ans[N];
    FORd(i, 1, N+1) {
        ll lm = lst[i][cur];
        ll rem = (cur|lm) - lm;
        cur = lm;
        F0R(j, N) {
            if (rem & (1 << j)) {
                ans[j] = i;
            }
        }
    }
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343