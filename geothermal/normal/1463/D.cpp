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
vi in, out;

int get(int X) {
    F0R(i, X) {
        if (in[i] > out[N-X+i]) return 1; //need lower X
    }
    FOR(i, X, N) {

        if (in[i] < out[i-X]) return 2; //need higher X
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        cin >> N;
        bool ok[2*N]; F0R(i, 2*N) ok[i] = false;
        F0R(i, N) {
            int X; cin >> X; X--;
            ok[X] = true;
        }
        in.clear(); out.clear();
        F0R(i, 2*N) {
            if (ok[i]) {
                in.pb(i);
            } else out.pb(i);
        }
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            int X = get(mid);
            if (X != 2) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int l = lo;
        lo = 0, hi = N;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            int X = get(mid);
            if (X != 1) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        int h = lo;
        if (l <= h) {
            cout << h-l+1 << nl;
        } else cout << "0\n";
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343