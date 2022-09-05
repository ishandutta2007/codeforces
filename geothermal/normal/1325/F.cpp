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
const int MX = 100011; //check the limits, dummy
vector<vi> levels(MX);
vector<vi> graph(MX);
int D[MX];
int N;
int R;
set<int> sta;

int dfs(int v, int p, int d) {
    if (sta.count(v)) {
        int pos = D[v];
        int len = d - pos;
        if (len >= R) {
            printf("2\n%d\n", len);
            return v;
        }
        return -1;
    }

    if (D[v] != -1) return -1;

    D[v] = d;
    levels[d].pb(v);
    sta.insert(v);
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        int res = dfs(nxt, v, d+1);
        if (res == -2) return -2;
        if (res >= 0) {
            printf("%d ", v+1);
            if (v == res) return -2;
            return res;
        }
    }
    sta.erase(v);

    return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    scanf("%d", &N);
    int M; scanf("%d", &M);

    F0R(i, N) {
        if (i*i >= N) {
            R = i; break;
        }
    }
    F0R(i, M) {
        int A, B; scanf("%d %d", &A, &B); A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }
    F0R(i, MX) D[i] = -1;
    if (dfs(0, -1, 0) == -2) {
        printf("\n");
        return 0;
    }

    int dp[MX]; dp[0] = 0;
    int last[MX]; last[0] = -1;
    bool use[MX]; F0R(i, MX) use[i] = false;

    FOR(i, 1, MX) {
        int pr = max(0, i-R+1);
        if (dp[i-1] >= dp[pr]+ sz(levels[i-1])) {
            dp[i] = dp[i-1]; last[i] = i-1;
        } else {
            dp[i] = dp[pr] + sz(levels[i-1]); last[i] = pr;
            use[i] = true;
        }
    }

    int cur = MX-1;
    printf("1\n");
    
    while (cur > 0) {
        if (use[cur]) {
            F0R(i, sz(levels[cur-1])) {
                printf("%d ", levels[cur-1][i]+1); R--;
                if (R == 0) {
                    printf("\n"); return 0;
                }
            }
        }
        assert(cur != last[cur]);
        cur = last[cur];
    }

    printf("\n");
    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343