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
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

void solve() {

    int N; ll M; cin >> N >> M;
    ll X[N]; int B[N];
    F0R(i, N) cin >> X[i];
    F0R(i, N) cin >> B[i];
    vl one, two;
    F0R(i, N) {
        if (B[i] == 2) {
            two.pb(X[i]);
        } else {
            one.pb(X[i]);
        }
    }
    sort(all(one)); sort(all(two)); reverse(all(one)); reverse(all(two));
    ll sum = 0;
    int p = 0;
    while (sum < M && p < sz(one)) {
        sum += one[p]; p++;
    }
    int ans = 3*N;
    if (sum >= M) ans = p;
    F0R(i, sz(two)) {
        sum += two[i];
        while (p > 0 && sum - one[p-1] >= M) {
            p--;
            sum -= one[p];
        }
        if (sum >= M) ckmin(ans, i*2+p+2);
    }
    if (ans > 2*N) {
        cout << -1 << nl;
    } else cout << ans << nl;


}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343