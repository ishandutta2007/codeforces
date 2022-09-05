#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vector<vi> graph(N);
    int M; cin >> M;
    int K; cin >> K;
    vi spec(K);
    F0R(i, K) {
        int A; cin >> A; A--;
        spec[i] = A;
    }

    F0R(i, M) {
        int A, B; cin >> A >> B;
        A--;
        B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }

    int dist1[N]; F0R(i, N) dist1[i] = -1;
    queue<int> q;
    dist1[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            if (dist1[nxt] == -1) {
                dist1[nxt] = dist1[cur] + 1;
                q.push(nxt);
            }
        }
    }

    int dist2[N]; F0R(i, N) dist2[i] = -1;
    dist2[N-1] = 0;
    q.push(N-1);
	while (!q.empty()) {
        int cur = q.front(); q.pop();
        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            if (dist2[nxt] == -1) {
                dist2[nxt] = dist2[cur] + 1;
                q.push(nxt);
            }
        }
    }


    vpi ops;
    F0R(i, K) {
        ops.pb({dist1[spec[i]], dist2[spec[i]]});
    }

    sort(all(ops)); reverse(all(ops));
    int best = -1000000;
    int ans = 0;
    F0R(i, K) {

        ans = max(ans, ops[i].f + best);

        best = max(best, ops[i].s);
//        cout << ops[i].f << " " << ops[i].s << endl;
    }

    cout << min(ans+1, dist1[N-1]) << endl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343