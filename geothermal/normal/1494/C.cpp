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

int get(vl &A, vl &B) {
    
    int N = sz(A), M = sz(B);
    if (N == 0 || M == 0) return 0;
    if (B[M-1] < A[0]) return 0;
    int match[N]; match[N-1] = 0;
    FORd(i, 1, N) {
        auto it = lb(all(B), A[i]);
        match[i-1] = match[i];
        if (it != B.end() && *it == A[i]) {
            match[i-1]++;
        }
    }
    int ans = 0;
    int p = 0;
    while (p < M && B[p] < A[0]) p++;
    F0R(i, N) {
        while (p < M && (i == N-1 || B[p] < A[i+1])) {
            auto it2 = lb(all(B), B[p] - i);
            int cur = p - (it2-B.begin()); cur++;
            cur += match[i];
            ckmax(ans, cur);
            p++;
        }
    }
    return ans;
}

void solve() {

    int N, M; cin >> N >> M;
    vl na, pa, nb, pb;
    F0R(i, N) {
        ll X; cin >> X;
        if (X > 0) {
            pa.pb(X);
        } else {
            na.pb(-X);
        }
    }
    F0R(i, M) {
        ll X; cin >> X;
        if (X > 0) {
            pb.pb(X);
        } else {
            nb.pb(-X);
        }
    } 
    
    sort(all(na)); sort(all(nb));
    cout << get(pa, pb) + get(na, nb) << nl;

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