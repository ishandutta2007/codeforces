#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 998244353; //check the limits, dummy
 
ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}
 
ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}
 
ll mul(ll A, ll B) {
	return (A*B)%MOD;
}
 
ll add(ll A, ll B) {
	return (A+B)%MOD;
}
 
ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}
 
ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll N, M; cin >> N >> M;
    
    ll X = N*M;
    ll L, R; cin >> L >> R; L--;
    ll A = R/2 - L/2; // Even
    ll B = (R+1)/2 - (L+1)/2; // Odd
    A %= MOD; B %= MOD;
    if (X % 2 == 1) {
        cout << modExp((R-L)%MOD, X) << endl; return 0;
    }
    pl cnt[60];
    cnt[0] = {A, B};
    F0R(i, 59) {
        cnt[i+1] = {cnt[i].f * cnt[i].f + cnt[i].s * cnt[i].s, 2 * cnt[i].f * cnt[i].s};
        cnt[i+1].f %= MOD;
        cnt[i+1].s %= MOD;
    }
 
    pl ans = {1, 0};
    F0R(i, 60) {
        if (X & (1ll << i)) {
            ans = {ans.f * cnt[i].f + ans.s * cnt[i].s, ans.f * cnt[i].s + ans.s * cnt[i].f};
            ans.f %= MOD;
            ans.s %= MOD;
        }
    }
 
    cout << ans.f << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343