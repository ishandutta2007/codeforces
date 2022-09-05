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
ll mod(ll A, ll B) {
    if (A < 0) {
        return (B-((-A)%B))%B;
    } else {
        return A%B;
    }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll N; cin >> N;
    ll A[N]; F0R(i, N) cin >> A[i];
    if (N == 1) {
        cout << "1 1" << nl;
        cout << -A[0] << nl;
        F0R(i, 2) {
            cout << "1 1\n0\n";
        }
        return 0;
    }
    cout << 1 << " " << N-1 << nl;
    F0R(i, N-1) {
        cout << (N-1) * mod(A[i], N) << " ";
        A[i] += (N-1) * mod(A[i], N);
    }
    cout << nl;
    cout << 2 << " " << N << nl;
    FOR(i, 1, N-1) cout << 0 << " ";
    cout << (N-1) * mod(A[N-1], N) << nl;
    A[N-1] += (N-1) * mod(A[N-1], N);
    cout << 1 << " " << N << nl;
    F0R(i, N) cout << -A[i] << " ";
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343