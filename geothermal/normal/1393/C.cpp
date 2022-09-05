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
int N;
int cnt[MX];

bool ok(int d) {
    int rem[N+1]; F0R(i, N+1) rem[i] = cnt[i];
    priority_queue<int> q;
    vector<vi> in(N);
    F0R(i, N+1) {
        if (cnt[i] > 0) {
            q.push({cnt[i]});
        }
    }

    F0R(i, N) {
        trav(a, in[i]) q.push(a);
        if (sz(q) == 0) return false;
        int cur = q.top(); q.pop();
        cur--;
        if (cur == 0) continue;
        if (i + d >= N) return false;
        in[i+d].pb(cur);
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        cin >> N;
        F0R(i, N+1) cnt[i] = 0;
        F0R(i, N) {
            int X; cin >> X; cnt[X]++;
        }

        int lo = 1, hi = N;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (ok(mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << lo-1 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343