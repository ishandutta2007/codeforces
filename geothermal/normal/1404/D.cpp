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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    if (N % 2 == 0) {
        cout << "First" << endl;
        F0R(i, N) {
            cout << i+1 << " ";
        }
        F0R(i, N) cout << i+1 << " ";
        cout << endl;
        return 0;
    } 
    cout << "Second" << endl;
    vector<vi> A(N);
    int pos[2*N];
    F0R(i, 2*N) {
        int X; cin >> X; X--;
        A[X].pb(i);
        pos[i] = X;
    }
    bool in[2*N]; F0R(i, 2*N) in[i] = false;
    F0R(i, N) {
        int curVal = i;
        int cur = i;
        while (!in[cur%N] && !in[cur%N+N]) {
           // cout << "Proc " << cur << nl;
            in[cur] = true;
            int oth = A[pos[cur]][0];
            if (oth == cur || oth == cur+N) {
                oth = A[pos[cur]][1];
            } 
            cur = oth;
            if (cur >= N) {
                cur -= N;
            } else cur += N;
        }
    }

    ll sum = 0; F0R(i, 2*N) if (in[i]) sum += i;
    if (sum % 2 == 0) {
        F0R(i, 2*N) in[i] = !in[i];
    }
    F0R(i, 2*N) if (in[i]) cout << i + 1 << " ";
    cout << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343