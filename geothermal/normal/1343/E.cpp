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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; //check the limits, dummy

vector<vi> graph;
int dist[MX][3];

void dfs(int root, int p) {
    F0R(i, sz(graph)) {
        dist[i][p] = -1;
    }
    dist[root][p] = 0;
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            if (dist[nxt][p] != -1) continue;
            dist[nxt][p] = dist[cur][p] + 1;
            q.push(nxt);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, M, A, B, C; cin >> N >> M >> A >> B >> C;
        A--; B--; C--;
        graph = vector<vi>(N);
        vl P(M); F0R(i, M) cin >> P[i];
        sort(all(P));
        ll psum[M+1]; psum[0] = 0;
        F0R(i, M) {
            psum[i+1] = psum[i] + P[i];
        }
        F0R(i, M) {
            int A, B; cin >> A >> B; A--; B--;
            graph[A].pb(B);
            graph[B].pb(A);
        }
        dfs(B, 0);
        dfs(A, 1);
        dfs(C, 2);
        ll ans = psum[M] * 2;
        F0R(i, N) {
            if (dist[i][0] + dist[i][1] + dist[i][2] > M) continue;
            ll cur = psum[dist[i][0]] + psum[dist[i][0] + dist[i][1] + dist[i][2]];
            ans = min(ans, cur);
        }
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343