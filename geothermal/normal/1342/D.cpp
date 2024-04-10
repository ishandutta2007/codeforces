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
	
    int N, K; cin >> K >> N;
    int cnt[N]; F0R(i, N) cnt[i] = 0;
    vpi data(K);
    F0R(i, K) {
        int X; cin >> X; X--;
        cnt[X]++;
        data[i] = {X, i};
    }
    int cap[N]; F0R(i, N) cin >> cap[i];

    int ans = 0;
    int pre = 0;
    F0Rd(i, N) {
        pre += cnt[i];
        ans = max(ans, (pre+cap[i] - 1) / cap[i]);
    }

    vector<vi> res(ans);
    sort(all(data)); reverse(all(data));
    F0R(i, K) {
        res[i%ans].pb(data[i].f);
    }
    cout << ans << nl;
    F0R(i, ans) {
        cout << sz(res[i]) << " ";
        F0R(j, sz(res[i])) cout << res[i][j]+1 << " ";
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343