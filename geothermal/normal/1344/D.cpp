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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

ll A[MX], B[MX];
int N;

ll ex(ll X, ll Y) {
    if (Y == 0) return 5e18;
    Y--;
    return X - 1 - 3*Y - 3*Y*Y;
}

ll getCnt(ll X, ll cap) {
    ll lo = 0, hi = X;
    while (lo < hi) {
        ll mid = (lo+hi+1)/2;
        if (ex(X, mid) >= cap) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

ll total(ll cap) {
    ll ans = 0;
    F0R(i, N) {
        B[i] = getCnt(A[i], cap);
        ans += B[i];
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    ll K; cin >> K;
    F0R(i, N) cin >> A[i];
    ll lo = -4e18, hi = 4e18;
    while (lo < hi) {
        ll mid = lo+(hi-lo)/2;
        
        if (total(mid) <= K) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    ll cnt = total(lo);
    F0R(i, N) {
        ll poss = getCnt(A[i], lo-1);
        ll old = B[i];
        B[i] = min(poss, old + K - cnt);
        cnt += B[i] - old;
    }

    F0R(i, N) {
        cout << B[i] << " ";
    }
    cout << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343