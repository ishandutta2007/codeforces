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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 500011; //check the limits, dummy
int N; int M;

int one[MX], zero[MX];
int bit[MX];
ll dp[MX];



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    cin >> N;
    int K; cin >> K;
    cin >> M;

    ll ans = 1;

    vector<vi> conds; F0R(i, M) {
        int A, B, C; cin >> A >> B >> C;
        A--; B--; C = (1 << K) - 1 - C;
        conds.pb({A, B, C});
    }


    F0R(x, K) {
        F0R(i, N) {
            one[i] = -1, zero[i] = -1;
        }
        F0R(i, M) {
            if (conds[i][2] & (1 << x)) {
                one[conds[i][1]] = max(one[conds[i][1]], conds[i][0]);

            } else {
                zero[conds[i][0]] = max(zero[conds[i][0]], conds[i][1]);
            }
        }

        ll sum = 1;
        int p = 0;
        dp[0] = 1;
        int zed = 0;
        FOR(i, 1, N+1) {
            dp[i] = sum;
            zed = max(zed, zero[i-1] + 1);
            if (zed >= i) {
                dp[i] = 0;
            }
            sum += dp[i]; sum %= MOD;
            while (p <= one[i-1]) {
                sum += MOD - dp[p];
                sum %= MOD;
                p++;
            }
        }

        ans *= sum; ans %= MOD;
        F0R(i, N) {
            //cout << x << " " << i << " " << one[i] << " " << zero[i] << endl;
        }
        //cout << sum << endl;


    }

    cout << ans << endl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343