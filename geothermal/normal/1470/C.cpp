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

int N, K;
int ans;
vl val;

ll ask(int X) {
    cout << "? " << X+1 << endl;
    ll ans; cin >> ans;
    return ans;
}

void done(int X) {
    cout << "! " << X+1 << endl;
    exit(0);
}

/*ll ask(int X) {
    ll res = val[X];
//    cout << "QUER " << X << " " << ans << nl;
    vl nxt(N);
    F0R(i, N) {
        if (i != ans) {
            nxt[(i+1)%N] += (val[i]+1)/2;
            nxt[(i+N-1)%N] += (val[i])/2;
        } else {
            nxt[(i+1)%N] += val[i];
        }
    }
    F0R(i, N) val[i] = nxt[i];
    return res;
}

void done(int X) {
//    cout << "ANS " << X << nl;
    if (X != ans) {
        cout << "ERROR" << endl; 
        cout << N << " " << K << " " << ans << nl;
        exit(0);
    }
}*/

void solve() {

    cin >> N >> K;
/*    N = uid(4, 10); ans = uid(0, N-1); K = uid(2, 10);
    K += K % 2;*/
    val.clear();
    F0R(i, N) val.pb(K);
    ask(0);
    int pos = 0;
    int lo, hi;
    FOR(i, 1, 900) {
        ll X = ask(pos);
        if (X < K) {
            lo = pos;
            hi = pos + i;
        } else if (X > K) {
            hi = pos;
            lo = pos - i;
        }
        if (X != K) break;
        pos += i; pos %= N;
    }
    lo += N; hi += N;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        ll X = ask(mid % N);
        if (X == K) {
            done(mid%N);
        } else if (X < K) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    done(lo%N);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 100;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343