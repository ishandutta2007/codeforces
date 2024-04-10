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
const int MX = 500001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, K; cin >> N >> M >> K;
    int C[N]; F0R(i, N) cin >> C[i];
    F0R(i, N) C[i]--;
    
    vector<vi> graph(MX);
    map<pi, vpi> bet;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        if (C[X] == C[Y]) {
            graph[X].pb(Y);
            graph[Y].pb(X);
        } else {
            pi cp = {min(C[X], C[Y]), max(C[X], C[Y])};
            bet[cp].pb({X, Y});
        }
    }

    bool ok[K]; F0R(i, K) ok[i] = true;
    int col[N], com[N]; F0R(i, N) {
        col[i] = -1; 
    }
    int nc = 0;

    F0R(r, N) {
        if (col[r] != -1) continue;
        col[r] = 0; com[r] = nc;
        queue<int> q; q.push(r);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int nextCol = 1 - col[cur];
            trav(a, graph[cur]) {
                if (col[a] == 1 - nextCol) {
                    ok[C[r]] = false;
                }
                if (col[a] == -1) {
                    col[a] = nextCol;
                    com[a] = com[cur];
                    q.push(a);
                }
            }
        }
        nc++;
    }

    ll ans = 0; F0R(i, K) if (ok[i]) ans++;
    ans = (ans * (ans-1)) / 2;

    int con[N];
    trav(dat, bet) {

        vpi ed = dat.s;
        if (!ok[dat.f.f] || !ok[dat.f.s]) continue;

        bool bad = false;

        map<int, vpi> ng;
        queue<int> bq;
        trav(a, ed) {
            int X = com[a.f], Y = com[a.s];
            con[X] = -1; con[Y] = -1;
            int dif = abs(col[a.f] - col[a.s]);

            ng[X].pb({Y, dif});
            ng[Y].pb({X, dif});
            bq.push(X); bq.push(Y);
        }

        while (!bq.empty()) {
            int r = bq.front(); bq.pop();
            if (con[r] != -1) continue;
            queue<int> q; q.push(r);
            con[r] = 0;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
//                cout << "Going " << cur << nl;
                vpi g = ng[cur];
                trav(a, g) {
                    int ncol = con[cur]; if (a.s) ncol = 1 - ncol;
                    if (con[a.f] == 1 - ncol) bad = true;
                    if (con[a.f] == -1) {
                        con[a.f] = ncol;
                        q.push(a.f);
                    }
                }
            }
        }
        if (bad) ans--;
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343