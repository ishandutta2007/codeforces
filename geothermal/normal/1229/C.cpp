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
        graph[A].pb(B); graph[B].pb(A);

    }

    vector<int> higherNodes[N];
    int label[N]; F0R(i, N) label[i] = i;
    ll ans = 0;
    F0R(i, N) {
        F0R(j, sz(graph[i])) {
            if (graph[i][j] > i) {
                higherNodes[i].pb(graph[i][j]);
            }
        }
        ll curSize = sz(higherNodes[i]), totalSize = sz(graph[i]);
        ans += curSize * (totalSize - curSize); 
    }

    cout << ans << endl;

    int Q; cin >> Q;
    F0R(query, Q) {
        int P; cin >> P; P--;
       ll curSize = sz(higherNodes[P]), totalSize = sz(graph[P]);
        ans -= curSize * (totalSize - curSize); 
        for (auto it = higherNodes[P].begin(); it != higherNodes[P].end(); it++) {
            int v = *it;
             curSize = sz(higherNodes[v]), totalSize = sz(graph[v]);
             ans -= curSize * (totalSize - curSize); 
 
            higherNodes[v].pb(P);
            curSize = sz(higherNodes[v]), totalSize = sz(graph[v]);
            ans += curSize * (totalSize - curSize);

        }

        higherNodes[P].clear();
        cout << ans << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343