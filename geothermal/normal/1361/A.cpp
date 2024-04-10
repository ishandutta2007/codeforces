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
	
    int N, M; cin >> N >> M;
    vector<vi> graph(N);
    priority_queue<int, vi, greater<int> > q[N];
    int V[N]; F0R(i, N) V[i] = 1;
    int ans[N]; F0R(i, N) ans[i] = -1;
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    int G[N]; F0R(i, N) cin >> G[i];

    priority_queue<pi, vpi, greater<pi> > ready;
    F0R(i, N) if (V[i] == G[i]) ready.push({i, 1});
    int nxt = 1;
    while (!ready.empty()) {
        int cur = ready.top().f; ready.pop();
        if (V[cur] != G[cur]) {
            cout << -1 << nl; return 0;
        }
        ans[nxt-1] = cur+1; nxt++;

        trav(a, graph[cur]) {
            q[a].push(G[cur]);
            while (!q[a].empty() && q[a].top() <= V[a]) {
                if (q[a].top() == V[a]) {
                    V[a]++;
                    if (V[a] == G[a]) ready.push({a, G[a]});
                }
                q[a].pop();
            }
        }
    }
    if (nxt <= N) {
        cout << -1 << nl; return 0;
    }

    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343