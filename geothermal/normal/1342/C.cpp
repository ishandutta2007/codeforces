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
	
    int T; cin >> T;
    while(T--) {
        ll A, B; int Q; cin >> A >> B >> Q;
        ll total = 0;
        ll X[A*B];
        ll pre[A*B];
        ll post[A*B];
        F0R(i, A*B) {
            X[i] = 0;
            if ((i % A) % B != (i % B) % A) {
                X[i] = 1; total++;
            }
        }
        pre[0] = X[0];
        F0R(i, A*B-1) {
            pre[i+1] = pre[i] + X[i+1];
        }

        post[A*B-1] = X[A*B-1];
        F0Rd(i, A*B-1) {
            post[i] = post[i+1] + X[i];
        }

        F0R(it, Q) {
            ll L, R; cin >> L >> R;
            ll aR = pre[R%(A*B)] + (R / A / B) * total;
            L--;
            ll aL = pre[L%(A*B)] + (L / A / B) * total;
            cout << aR - aL << " ";
/*            ll lC = (L+A*B-1)/(A*B);
            lC *= A*B;
            ll rF = R / (A*B);
            rF *= A*B;
            if (lC > rF) {
                ll ans = pre[R % (A*B)];
                if (L % (A*B) > R % (A*B)) ans += total;
                if (L % (A*B) != 0) ans -= pre[(L-1)%(A*B)];
                cout << ans << " ";
                continue;
            }
            ll ans = (rF - lC) / A*B; ans *= total;
            ans += pre[R % (A*B)];
            ans += post[L % (A*B)];
            cout << ans << " ";*/
        }
        cout << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343