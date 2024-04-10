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
vector<vi> graph;
int P[MX];
int cnt[MX];

int dfs(int v, int p) {
    P[v] = p;
    cnt[v] = 0;
    if (sz(graph[v]) == 1 && p != -1) {
        cnt[v] = 1;
    }
    trav(a, graph[v]) {
        if (a == p) continue;
        cnt[v] += dfs(a, v);
    }
    return cnt[v];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        graph.clear();
        int N; cin >> N;
        F0R(i, N) {
            graph.pb(vi());
        }
        ll S; cin >> S;
        pi ep[N-1];
        ll W[N-1], C[N-1];
        F0R(i, N-1) {
            cin >> ep[i].f >> ep[i].s >> W[i];
            ep[i].f--; ep[i].s--;
            graph[ep[i].f].pb(ep[i].s);
            graph[ep[i].s].pb(ep[i].f);

            cin >> C[i]; //CHANGE THIS FOR E1
//            C[i] = 1;
            C[i]--;
        }

        dfs(0, -1);

        ll sum = 0;
        vl ec[2];
        F0R(i, N-1) {
            int v = ep[i].s;
            if (P[ep[i].f] == ep[i].s) {
                v = ep[i].f;
            }

            sum += W[i] * cnt[v];
            ll cost = W[i];
            while (cost > 0) {
                ll nc = cost / 2;
                ec[C[i]].pb((cost - nc) * cnt[v]);
                cost = nc;
            }
        }

        F0R(i, 2) {
            sort(all(ec[i])); reverse(all(ec[i]));
        }

        int p[2]; p[0] = 0; p[1] = 0;
        F0R(i, 2) {
            while (sum > S && p[i] < sz(ec[i])) {
                sum -= ec[i][p[i]];
                p[i]++;
            }
        }

        int ans = p[0] + p[1] * 2;
        while (p[0] > 0) {
            p[0]--;
            sum += ec[0][p[0]];
            while (sum > S && p[1] < sz(ec[1])) {
                sum -= ec[1][p[1]];
                p[1]++;
            }
            if (sum > S) break;
            ckmin(ans, p[0] + p[1] * 2);
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343