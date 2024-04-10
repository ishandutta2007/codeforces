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
const int MX = 500001; //check the limits, dummy

ll N, M;
ll K;
int A[MX];
int B[MX];
ll G;
ll mov;
ll pos[MX];
ll cnt;

bool angry(ll it) {
    ll num = it / mov;
    ll tot = num * cnt;
    F0R(i, N) {
        if (pos[i] < it % mov) tot++;
    }
    return it - tot >= K;
}

void solve() {

    cin >> N >> M >> K;
    G = __gcd(N, M);
    mov = N*M/G;
    F0R(i, N) cin >> A[i];
    F0R(i, M) cin >> B[i];
    ll p[MX*4]; F0R(i, MX*4) p[i] = -1;
    cnt = 0;
    int ord[M/G];
    F0R(i, M) {
        p[B[i]] = i;
    }
    int x = 0;
    F0R(j, M/G) {
        ord[x] = j;
        x += N/G;
        x %= M/G;
    }
    F0R(i, N) {
        if (p[A[i]] == -1 || p[A[i]] % G != i % G) {
            pos[i] = mov+1;
        } else {
            ll X = ord[(i%M)/G];
            ll Y = ord[p[A[i]]/G];
            ll Z = Y - X; if (Z < 0) Z += M/G;
            //cout << X << " " << Y << " " << Z << nl;
            pos[i] = N * Z + i;
            cnt++;
        }
    }

    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (!angry(mid)) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    /*F0R(i, N) {
        cout << pos[i] << nl;
    }*/

    cout << lo << nl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343