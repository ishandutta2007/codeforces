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
typedef complex<ll> cl;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<cl> vcl;
 
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
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    map<int, int> dp[MX];
    int N, M; cin >> N >> M;
    F0R(i, N) dp[i].ins({-1, 0});
    F0R(i, M) {
        int A, B, C; cin >> A >> B >> C; A--; B--;
        int op = 1 + (--(dp[A].lb(C)))->s;
        if (op > (--(dp[B].lb(C)))->s) {
            dp[B].ins({C, op});
            for (auto it = dp[B].ub(C); it != dp[B].end() && it->s <= op; it = dp[B].ub(C)) {
                dp[B].erase(it);
            }
        }

    }
    int ans = 0;
    F0R(i, N) {
        for (auto it = dp[i].begin(); it != dp[i].end(); it++) ans = max(ans, it->s);
    }

    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343