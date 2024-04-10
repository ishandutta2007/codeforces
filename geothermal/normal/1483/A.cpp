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

    int N, M; cin >> N >> M;
    int cnt[N]; F0R(i, N) cnt[i] = 0;
    vector<vi> A(M);
    vi ans;
    F0R(i, M) {
        int X; cin >> X;
        A[i] = vi(X);
        F0R(j, X) cin >> A[i][j];
        F0R(j, X) A[i][j]--;
        cnt[A[i][0]]++;
        ans.pb(A[i][0]+1);
    }
    int rep = -1;
    F0R(i, N) {
        if (cnt[i] > (M+1)/2) rep = i;
    }

    F0R(i, M) {
        if (sz(A[i]) > 1 && A[i][0] == rep && cnt[rep] > (M+1)/2) {
            cnt[rep]--; cnt[A[i][1]]++;
            ans[i] = A[i][1]+1;
        }
    }
    if (rep != -1 && cnt[rep] > (M+1)/2) {
        cout << "NO" << nl; return;
    }
    cout << "YES" << nl;
    F0R(i, M) {
        cout << ans[i] << " ";
    }
    cout << nl;

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