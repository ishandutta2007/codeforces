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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> M >> N;
    vector<vi> graph(N);

    F0R(it, M) {
        map<int, vi> S;
        F0R(i, N) {
            int cur; cin >> cur;
            if (cur == -1) continue;
            S[cur].pb(i);
        }
        int lstDif = -1;
        for (auto it = S.begin(); it != S.end(); it++) {
            auto it2 = it; it2++;
            if (it2 == S.end()) break;
            vi cur; int P = sz(graph);
            trav(a, it->s) {
                graph[a].pb(P);
            }
            trav(b, it2->s) {
                cur.pb(b);
            }
            graph.pb(cur);
        }
    }

    int oN = N;
    N = sz(graph);
    int in[N]; 
    F0R(i, N) in[i] = 0;
    F0R(i, N) trav(a, graph[i]) in[a]++;

    queue<int> q;
    F0R(i, N) {
        if (in[i] == 0) q.push(i);
    }
    vi ans;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur < oN) ans.pb(cur);
        trav(a, graph[cur]) {
            in[a]--;
            if (in[a] == 0) {
                q.push(a);
            }
        }
    }

    if (sz(ans) == oN) {
        F0R(i, oN) cout << ans[i]+1 << " ";
    } else {
        cout << -1;
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343