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
bool solve(int A, int B, int C, int D, bool use, bool rev) {
    vi ans;
    int state = 0;
    int data[4]; data[0] = A; data[1] = B; data[2] = C; data[3] = D;
    if (rev) {
        data[0] = D;
        data[1] = C;
        data[2] = B;
        data[3] = A;
    }
    int exp = 0; if (use) exp = 1;
    F0R(i, 10000000) { 
        if (data[exp] > 0) {
            ans.pb(exp); data[exp]--;
            exp -= state;
            exp = 1-exp;
            exp += state;
        } else {
            state++;
            if (state == 3) break;
            exp = state;
            if ((!ans.empty() && ans[sz(ans)-1] == exp) || data[exp] == 0) exp++;
        }
    }

    if (data[0] > 0 || data[1] > 0 || data[2] > 0 || data[3] > 0) return false;
    F0R(i, sz(ans) - 1) {
        if (abs(ans[i] - ans[i+1]) != 1) return false;
    }

    cout << "YES" << endl;
    if (rev) {
        F0R(i, sz(ans)) ans[i] = 3-ans[i];
    }
    F0R(i, sz(ans)) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return true;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int A, B, C, D; cin >> A >> B >> C >> D;
    F0R(i, 2) {
        F0R(j, 2) {
            if (solve(A, B, C, D, (bool) i, (bool) j)) return 0;
        }
    }
    cout << "NO" << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343