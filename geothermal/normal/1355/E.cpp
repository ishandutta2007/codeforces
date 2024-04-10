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
    ll A, R, M; cin >> A >> R >> M;
    vl H(N); F0R(i, N) cin >> H[i];
    sort(all(H));
    ll bsum = 0, asum = 0;
    ll bc = 0, ac = 0;
    F0R(i, N) {
        asum += H[i]; ac++;
    }
    ll ans = 4e18;
    F0R(i, N) {
        asum -= H[i]; ac--;
        bsum += H[i]; bc++;
        ll tb = H[i]*bc-bsum;
        ll ta = asum - H[i] * ac;

        ans = min(ans, tb*A+ta*R);
        if (tb < ta) {
            ans = min(ans, tb*M + (ta-tb)*R);
        } else {
            ans = min(ans, ta*M + (tb-ta)*A);
        }
    }
    ll ave = 0;
    F0R(i, N) ave += H[i];
    bc = 0, ac = 0;
    ll cur = 0;
    F0R(i, N) {
        if (H[i] <= ave / N) {
            cur += ((ave / N) - H[i]) * M;
        }
    }
    cur += (ave % N) * R;
    ans = min(ans, cur);
    cur = 0;
    F0R(i, N) {
        if (H[i] >= (ave / N) + 1) {
            cur += (H[i] - (ave / N) - 1  ) * M;
        }
    }
    cur += (N - (ave % N)) * A;
    ans = min(ans, cur);

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343