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
const int MX = 100001; //check the limits, dummy
int N, M, K; 
vector<vi> graph(MX);
vector<vi> L(MX);
stack<int> st;
int dep[MX];
 
bool dfs(int v, int p, int d) {
    dep[v] = d;
    L[d].pb(v);
    st.push(v);
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        if (dep[nxt] == -1) {
            if (dfs(nxt, v, d+1)) return true;
        } else if (dep[nxt] + K > d && dep[nxt] < d) {
            cout << 2 << nl;
            cout << d - dep[nxt] + 1 << nl;
            F0R(i, d - dep[nxt] + 1) {
                cout << st.top()+1 << " ";
                st.pop();
            }
            return true;
        }
    }
    st.pop();
    return false;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> M >> K;
 
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    F0R(i, N) dep[i] = -1;
    if (dfs(0, 0, 0)) {
        return 0;
    }
    int dp[K]; int lst[K];
    F0R(i, K) {
        dp[i] = 0; lst[i] = -1;
    }
    dp[0] = sz(L[0]);
    dp[1] = sz(L[1]); 
    dp[2] = sz(L[2]) + sz(L[0]); lst[2] = 0;
    FOR(i, 3, K) {
        if (dp[i-2] > dp[i-3]) {
            lst[i] = i-2;
            dp[i] = dp[i-2] + sz(L[i]);
        } else {
            lst[i] = i-3;
            dp[i] = dp[i-3] + sz(L[i]);
        }
    }
    int cur = K-1;
    if (dp[K-2] > dp[K-1]) cur = K-2;
    int cnt = 0;
    cout << 1 << nl;
    while (cur >= 0) {
        F0R(i, sz(L[cur])) {
            if (cnt < (K+1)/2) {
                cout << L[cur][i]+1 << " ";
                cnt++;
            }
        }
        cur = lst[cur];
    }
 
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343