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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; ll X; cin >> N >> X;
    vl D(2*N); F0R(i, N) cin >> D[i];
    F0R(i, N) {
        D[i+N] = D[i];
    }

    ll ans = 0;
    reverse(all(D));
    ll nxt = 0;
    ll cur = 0;
    ll cnt = 0;
    F0R(i, N) {
        if (i > 0) {
            cnt -= D[i-1];
            cur -= (D[i-1] * (D[i-1] + 1)) / 2;
        }
        while (cnt + D[nxt] <= X) {
            cnt += D[nxt];
            cur += (D[nxt] * (D[nxt] + 1)) / 2;
            nxt++;
        }
        ll rem = X - cnt;
        ll val = ((D[nxt] + D[nxt] - rem + 1) * (rem)) / 2;
        ans = max(ans, cur + val);
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343