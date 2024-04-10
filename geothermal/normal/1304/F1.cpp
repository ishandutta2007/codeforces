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
 
const ll identity = 0;
const ll SZ = 131072/4;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return max(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, K; cin >> N >> M >> K;
    int P = M-K+1;
    int pref[N][M+1];
    int data[N][M]; F0R(i, N) F0R(j, M) cin >> data[i][j];
    F0R(i, N) {
        pref[i][0] = 0;
        F0R(j, M) {
            pref[i][j+1] = pref[i][j] + data[i][j];
        }
    }

    F0R(i, 2*SZ) {
        sum[i] = 0; lazy[i] = 0;
    }

    int dp[N][P];
    F0R(i, N) {
        F0R(j, P) {
            dp[i][j] = 0;
        }
    }
    F0R(i, P) {
        dp[0][i] = pref[0][i+K] - pref[0][i];
    }

    FOR(r, 1, N) {
        F0R(i, P) {
            update(i, i, dp[r-1][i] + pref[r][i+K] - pref[r][i] - query(i, i));
        }

        F0R(i, K) {
            update(0, i, -1 * data[r][i]);
        }
        dp[r][0] = query(0, P) + pref[r][K] - pref[r][0];

        FOR(i, 1, P) {
            update(max(0, i-K), i-1, data[r][i-1]);
            update(i, min(P-1, i+K-1), -1*data[r][i+K-1]);
            dp[r][i] = query(0, P) + pref[r][i+K] - pref[r][i];
        }
    }
    int ans = 0;
    F0R(i, P) {
        ans = max(ans, dp[N-1][i]);
    }
    cout << ans << endl;

/*    F0R(i, N) {
        F0R(j, P) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343