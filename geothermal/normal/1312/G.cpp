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
const int MX = 1000011; //check the limits, dummy

int nxt[MX][26];
int ans[MX];
int sub[MX];
bool used[MX];

int dfs(int v, int d, int c) {
    //cout << v << " " << d << " " << c << endl;
    int res = 0; if (used[v]) res++;
    if (used[v]) c++;
    ans[v] = min(d, c);
    if (used[v]) d = min(d, c);
    int nC = d; if (used[v]) nC++;
    c = min(nC, c);
    d++;
    F0R(i, 26) {
        if (nxt[v][i] == -1) continue;
        int V = dfs(nxt[v][i], d, c);
        res += V; c += V;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int N; cin >> N;

    F0R(i, 26) nxt[0][i] = -1;
    FOR(i, 1, N+1) {
        int A; char C; cin >> A >> C;
        int B = C - 'a';
        nxt[A][B] = i;
        F0R(j, 26) nxt[i][j] = -1;
    }

    F0R(i, N+1) used[i] = false;
    int K; cin >> K;
    vi q(K);
    F0R(i, K) {
        int X; cin >> X; used[X] = true;
        q[i] = X;
    }

    dfs(0, 0, 0);

    F0R(i, K) cout << ans[q[i]] << " ";
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343