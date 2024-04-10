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
const ll MX = 200001; //check the limits, dummy

void solve() {

    int N, M; cin >> N >> M;
    ll dist[M+1]; F0R(i, M+1) dist[i] = MX*MX;
    dist[0] = 0;
    ll T[N], X[N], Y[N]; F0R(i, N) cin >> T[i] >> X[i] >> Y[i];
    priority_queue<pl, vpl, greater<pl>> q;
    q.push({0, 0});
    const ll mul = 100000;
    while (!q.empty()) {
        ll x = q.top().s; ll d = q.top().f; q.pop();
        if (dist[x] != d) continue;
        ll v = dist[x]/MX;

        FOR(p, v, N) {
            ll nxt;
            if (T[p] == 1) {
                nxt = (x * mul + X[p] + mul-1) / mul;
            } else {
                nxt = (x * X[p] + mul-1) / mul;
            }

            if (nxt <= M) {
                ll vd = dist[x] + 1;
                if (v != p) vd = MX*p+1;
                if (vd % MX == Y[vd/MX]) {
                    vd = MX*(p+1);
                }
                if (ckmin(dist[nxt], vd)) {
                    q.push({dist[nxt], nxt});
                }
            }
        }
    }

    FOR(i, 1, M+1) {
        if (dist[i] == MX*MX) {
            cout << -1 << " ";
        } else {
            cout << (dist[i]-1)/MX + 1 << " ";
        }
    }
    cout << nl;

    /*F0R(i, M+1) {
        cout << i << ": " << dist[i]/MX << " " << dist[i]%MX << nl;
    }*/


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