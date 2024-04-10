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
	
    int N, S1, S2; cin >> N >> S1 >> S2;
    int X[N], Y[N]; F0R(i, N) cin >> X[i] >> Y[i];
    F0R(i, N) {
        X[i] -= S1;
        Y[i] -= S2;
    }

    ll c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    F0R(i, N) {
        if (X[i] > 0) c1++;
        if (Y[i] > 0) c3++;
        if (X[i] < 0) c2++;
        if (Y[i] < 0) c4++;
    }

    ll mx = max({c1, c2, c3, c4});
    cout << mx << endl;

    int A = 0, B = 0;
    if (c1 == mx) {
        A = 1;
    } else if (c2 == mx) {
        A = -1;
    } else if (c3 == mx) {
        B = 1;
    } else B = -1;
	
    cout << S1+A << " " << S2+B << endl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343