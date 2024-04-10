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
	
    int T; cin >> T;
    while(T--) {
        int N, Q; cin >> N >> Q;
        vl A(N); F0R(i, N) cin >> A[i];
        sort(all(A));
        ll pre[N+1]; 
        pre[0] = 0;
        F0R(i, N) {
            pre[i+1] = pre[i] + A[i];
        }
        queue<pi> q; q.push({0, N-1});
        set<ll> ok;
        while (!q.empty()) {
            pi cur = q.front(); q.pop();
            ok.ins(pre[cur.s+1] - pre[cur.f]);
            if (A[cur.f] == A[cur.s]) continue;
            ll bp = (A[cur.f] + A[cur.s]) / 2;
            int lo = (upper_bound(all(A), bp) - A.begin());
            q.push({cur.f, lo-1});
            q.push({lo, cur.s});
        }
        F0R(i, Q) {
            ll S; cin >> S;
            cout << (ok.count(S)?"Yes":"No") << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343