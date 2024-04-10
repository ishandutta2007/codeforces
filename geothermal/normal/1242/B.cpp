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
	
    int N, M; cin >> N >> M;

    vector<set<int> > graph(N);
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].ins(B);
        graph[B].ins(A);
    }

    bool in[N]; F0R(i, N) in[i] = false;
    in[0] = true;
    set<int> good, bad;

    FOR(i, 1, N) {
        if (graph[0].count(i)) {
            bad.ins(i);
        } else {
            good.ins(i);
        }
    }
    int ans = 0;
    F0R(i, N-1) {
        int cur;
        if (sz(good) > 0) {
            cur = *good.begin();
            good.erase(cur);
        } else {
            cur = *bad.begin();
            bad.erase(cur);
            ans++;
        }
        in[cur] = true;
        set<int> obad = bad;
        bad = graph[cur];
        vi erase;
        trav(a, bad) {
            if (!obad.count(a)) {
                erase.pb(a);
            }
        }
        trav(a, erase) {
            bad.erase(a);
        }
        trav(a, obad) {
            if (!bad.count(a)) {
                good.ins(a);
            }
        }
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343