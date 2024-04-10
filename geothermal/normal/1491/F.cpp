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

vi P;
int N;
int val;

int query(vi &A, vi &B) {
    cout << "? " << sz(A) << " " << sz(B) << endl;
    trav(a, A) {
        cout << P[a] << " ";
    }
    cout << endl;
    trav(b, B) {
        cout << P[b] << " ";
    }
    cout << endl;
    int X; cin >> X;
    if (abs(X) > N) exit(0);
    return val = X;
}

void ans(vi &A) {
    cout << "! " << sz(A) << " ";
    vi res; trav(a, A) res.pb(P[a]);
    trav(a, res) cout << a << " ";
    cout << endl;
}

void solve() {

    cin >> N;
    P.clear();
    F0R(i, N) P.pb(i+1);
    int p = -1;
    FOR(i, 1, N) {
        vi cur; F0R(j, i) cur.pb(j);
        vi x = {i};
        if (query(cur, x) != 0) {
            p = i; break;
        }
    }
    bool mag[N]; F0R(i, N) mag[i] = false;
    mag[p] = true;
    FOR(j, p+1, N) {
        vi A = {p}, B = {j};
        mag[j] = query(A, B) != 0;
    }

    int lo = 0, hi = p-1;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        vi cur;
        F0R(i, mid+1) {
            cur.pb(i);
        }
        vi x = {p};
        if (query(cur, x) != 0) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    mag[lo] = true;
    vi res; F0R(i, N) if (!mag[i]) res.pb(i);

    ans(res);

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343