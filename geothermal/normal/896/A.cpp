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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string A = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string B = "What are you doing while sending \"", C = "\"? Are you busy? Will you send \"", D = "\"?";
    ll len[MX];
    len[0] = sz(A);
    FOR(i, 1, MX) {
        len[i] = 2 * len[i-1] + sz(B) + sz(C) + sz(D);
        ckmin(len[i], (ll) 2e18);
    }
    int Q; cin >> Q;
    while(Q--) {
        int N; cin >> N;
        ll K; cin >> K;
        K--;
        if (K >= len[N]) {
            cout << '.'; continue;
        }
        while (N > 0) {
            if (K < sz(B)) {
                cout << B[K]; goto done;
            } else if (sz(B) <= K && K < sz(B) + len[N-1]) {
                K -= sz(B); N--;
            } else if (sz(B) + len[N-1] <= K && K < sz(B) + sz(C) + len[N-1]) {
                K -= sz(B) + len[N-1]; 
                cout << C[K]; goto done;
            } else if (sz(B) + sz(C) + len[N-1] <= K && K < sz(B) + sz(C) + 2*len[N-1]) {
                K -= sz(B) + sz(C) + len[N-1]; N--;
            } else {
                K -= sz(B) + sz(C) + 2*len[N-1]; cout << D[K]; goto done;
            }
        }
        cout << A[K];
        done:
        ;
    }
    cout << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343