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
	
    int N, M; cin >> N >> M;
    vector<vi> graph(N);
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[B].pb(A);
    }

    int K; cin >> K;
    vi data(K); F0R(i, K) cin >> data[i];
    F0R(i, K) data[i]--;

    int dist[N];
    int cnt[N]; 
    F0R(i, N) dist[i] = 1000000;
    F0R(i, N) cnt[i] = 0;
    int root = data[K-1];
    dist[root] = 0;
    cnt[root] = 1;
    priority_queue<pi, vpi, greater<pi> > q;
    q.push({0, root});
    while (!q.empty()) {
        pi curDat = q.top(); q.pop();
        int curDist = curDat.f;
        int v = curDat.s;
        if (dist[v] != curDist) continue;
        F0R(i, sz(graph[v])) {
            int nxt = graph[v][i];
            if (curDist + 1 < dist[nxt]) {
                dist[nxt] = curDist + 1;
                q.push({dist[nxt], nxt});
                cnt[nxt] = 0;
            }
            if (curDist + 1 == dist[nxt]) {
                cnt[nxt] ++;
            }
        }
    }

    int hi = K-1;
    int lo = 0;
    F0R(i, K-1) {
        if (1 + dist[data[i+1]] != dist[data[i]]) {
            lo++;
        }
        if (1 + dist[data[i+1]] == dist[data[i]] && cnt[data[i]] == 1) {
            hi--;
        }
    }


    cout << lo << " " << hi << endl; 
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343