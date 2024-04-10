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
	
    vector<vi> L(27), R(27);
    int N; cin >> N;
    string S, T; cin >> S >> T;
    F0R(i, N) {
        int P = S[i] - 'a';
        if (P < 0 || P >= 26) {
            P = 26;
        }
        L[P].pb(i);
        P = T[i] - 'a';
        if (P < 0 || P >= 26) {
            P = 26;
        }
        R[P].pb(i);
    }

    vpi ans;
    int posL = 0, posR = 0;
    F0R(i, 26) {
        int lo = min(sz(L[i]), sz(R[i]));
        F0R(j, lo) {
            ans.pb({L[i][j], R[i][j]});
        }
        FOR(j, lo, sz(L[i])) {
            if (posR < sz(R[26])) {
                ans.pb({L[i][j], R[26][posR]});
                posR++;
            }
        }
        FOR(j, lo, sz(R[i])) {
            if (posL < sz(L[26])) {
                ans.pb({L[26][posL], R[i][j]});
                posL++;
            }
        }
    }

    while (posL < sz(L[26]) && posR < sz(R[26])) {
        ans.pb({L[26][posL], R[26][posR]});
        posL++; posR++;
    }
    cout << sz(ans) << endl;
    F0R(i, sz(ans)) {
        cout << ans[i].f +1 << " " << ans[i].s+1 << "\n";
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343