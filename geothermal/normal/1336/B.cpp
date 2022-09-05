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
int N[3];
vpl A;
ll ans;
void solve(int x, int y, int z) {
    ll prev[sz(A)]; 
    int ldif = 0;
    ll last = A[0].f;
    ll cv = -1000000000;
    if (A[0].s == x) cv = A[0].f;
    FOR(i, 1, sz(A)) {
        if (A[i].f != last) {
            FOR(j, ldif, i) {
                prev[j] = cv;
            }
            ldif = i;
        }
        if (A[i].s == x) {
            cv = A[i].f;
        }
        last = A[i].f;
    }
    FOR(j, ldif, sz(A)) prev[j] = cv;
/*    F0R(i, sz(A)) {
        cout << x << " " << y << " " << z << " " << i << " " << A[i].f << " " << prev[i] << nl;
    }*/

    ll nxt[sz(A)];
    ldif = sz(A)-1;
    last = A[sz(A)-1].f;
    cv = 2000000000;
    if (A[sz(A) - 1].s == z) cv = A[sz(A)-1].f;
    F0Rd(i, sz(A)-1) {
        if (A[i].f != last) {
            FOR(j, i+1, ldif+1) {
                nxt[j] = cv;
            }
            ldif = i;
        }
        if (A[i].s == z) {
            cv = A[i].f;
        }
        last = A[i].f;
    }
    FOR(j, 0, ldif+1) nxt[j] = cv;

    F0R(i, sz(A)) {
        if (A[i].s == y && prev[i] > 0 && nxt[i] <= 1000000000) {
            ans = min(ans, (A[i].f-prev[i]) * (A[i].f-prev[i]) + (nxt[i]-A[i].f) * (nxt[i]-A[i].f) + (nxt[i] - prev[i]) * (nxt[i]-prev[i]));
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        A.clear();
        cin >> N[0] >> N[1] >> N[2];
        F0R(i, 3) {
            F0R(j, N[i]) {
                ll X; cin >> X;
                A.pb({X, i});
            }
        }
        sort(all(A));
        vi p = {0, 1, 2};
        ans = 4e18;
        do {
            solve(p[0], p[1], p[2]);
        } while (next_permutation(all(p)));
        cout << ans << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343