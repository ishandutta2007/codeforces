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
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

bool check(vi& C, int X) {
    F0R(p, X) {
        for (int i = p; i < sz(C); i += X) {
            if (C[i] != C[(i+X)%sz(C)]) goto bad;
        }
        return true;
        bad:
        ;
    }
    return false;
}

int solve(vi& C) {
    int N = sz(C);
    int ans = sz(C);
    for (int i = 1; i * i <= N; i++) {
        if (N % i != 0) continue;
        if (check(C, i)) ans = min(ans, i);
        if (check(C, N / i)) ans = min(ans, N / i);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int ans = N;
        int P[N]; F0R(i, N) cin >> P[i];
        F0R(i, N) P[i]--;
        int C[N]; F0R(i, N) cin >> C[i];
        int col[N]; F0R(i, N) col[i] = 0;
        int pos[N]; F0R(i, N) pos[i] = 0;
        F0R(i, N) {
            if (col[i] != 0) continue;
            col[i] = 1; pos[i] = 0;
            vi lst; lst.pb(i);
            int cur = P[i];
            while (col[cur] == 0) {
                col[cur] = 1; pos[cur] = sz(lst);
                lst.pb(cur);
                cur = P[cur];
            }
            if (col[cur] == 1) {
                vi perm; FOR(i, pos[cur], sz(lst)) perm.pb(C[lst[i]]);
                ans = min(ans, solve(perm));
            }
            F0R(i, sz(lst)) col[lst[i]] = 2;

        }
        cout << ans << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343