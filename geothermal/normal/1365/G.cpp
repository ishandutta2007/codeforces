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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vector<vi> queries(13);
    vi perm;
    bool in[N][13]; 
    F0R(i, 6) perm.pb(1);
    F0R(i, 7) perm.pb(0);
    F0R(i, N) {
        F0R(j, 13) {
            if (perm[j]) queries[j].pb(i);
            in[i][j] = perm[j];
        }
        next_permutation(all(perm));
    }
    ll ans[N]; F0R(i, N) ans[i] = 0;
    F0R(i, 13) {
        if (sz(queries[i]) == 0) continue;
        cout << "? " << sz(queries[i]) << " ";
        F0R(j, sz(queries[i])) {
            cout << queries[i][j] + 1 << " ";
        }
        cout << endl;
        ll res; cin >> res;
        F0R(j, N) {
            if (!in[j][i]) ans[j] |= res;
        }
    }
    cout << "! ";
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343