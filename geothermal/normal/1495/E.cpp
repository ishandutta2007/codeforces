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

ll seed = 0, base = 0;
ll rnd() {
    ll ret = seed;
    seed = (seed * base + 233) % MOD;
    return ret;
}

void solve() {

    int N, M; cin >> N >> M;
    ll lst = 0;
    ll A[N]; int T[N];
    F0R(i, M) {
        ll P, K, B, W; cin >> P >> K >> B >> W;
        seed = B;
        base = W;
        FOR(j, lst, P) {
            T[j] = rnd()%2;
            A[j] = rnd()%K + 1;
        }
        lst = P;
    }

    ll sum = 0;
    F0R(i, N) {
        if (T[i]) {
            sum += A[i];
        } else {
            sum -= A[i];
        }
    }
    int p = 0;
    int win = 0;
    ll ans[N]; F0R(i, N) ans[i] = 0;
    if (sum > 0 || (sum == 0 && !T[0])) win = 1;
    if (!T[0] && sum < 0) {
        A[0]--;
        ans[0] = 1;
        F0R(i, N) {
            if (T[i] != T[0]) {
                p = i; break;
            }
        }
    }
    if (T[0] && sum > 0) {
        A[0]--;
        ans[0] = 1;
        F0R(i, N) {
            if (T[i] != T[0]) {
                p = i; break;
            }
        }
    }

    bool found = false;
    F0R(i, N) if (T[i] != win) found = true;
    if (found) {
        F0R(i, N) {
            if (T[i] != win) ans[i] += A[i];
        }
        sum = 0;
        while (p < 3*N) {
            int x = p%N;
            if (T[x] != win) {
                sum += A[x];
                A[x] = 0;
            } else {
                ans[x] += min(sum, A[x]);
                ll val = min(sum, A[x]);
                A[x] -= val; sum -= val;
            }
            p++;
        }
    }
    ll res = 1;
    F0R(i, N) {
        ll val = i+1;
        val *= val;
        val ^= ans[i];
        val++;
        val %= MOD;
        res *= val;
        res %= MOD;
    }
    cout << res << nl;

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