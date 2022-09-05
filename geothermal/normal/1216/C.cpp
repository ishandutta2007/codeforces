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
	
    vl W(4), B1(4), B2(4);
    F0R(i, 4) cin >> W[i];
    F0R(i, 4) cin >> B1[i];
    F0R(i, 4) cin >> B2[i];

    B1[0] = max(B1[0], W[0]);
    B2[0] = max(B2[0], W[0]);
    B1[1] = max(B1[1], W[1]);
    B2[1] = max(B2[1], W[1]);
    B1[2] = min(B1[2], W[2]);
    B2[2] = min(B2[2], W[2]);
    B1[3] = min(B1[3], W[3]);
    B2[3] = min(B2[3], W[3]);

    ll ans = 0;
    if (B1[3] >= B1[1] && B1[2] >= B1[0]) {
    ans += max(0ll, (B1[3] - B1[1]) * (B1[2] - B1[0]));
    }
    if (B2[3] >= B2[1] && B2[2] >= B2[0]) {
    ans += max(0ll, (B2[3] - B2[1]) * (B2[2] - B2[0]));
    }
    B1[0] = max(B1[0], B2[0]);
    B1[1] = max(B1[1], B2[1]);
    B1[2] = min(B1[2], B2[2]);
    B1[3] = min(B1[3], B2[3]);
    if (B1[3] >= B1[1] && B1[2] >= B1[0]) {
    ans -= max(0ll, (B1[3] - B1[1]) * (B1[2] - B1[0]));
    }
    cout << (ans == (W[3] - W[1]) * (W[2] - W[0]) ? "NO" : "YES") << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343