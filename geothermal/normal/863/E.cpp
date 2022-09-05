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
    vpi E;
    int in[N];
    F0R(i, N) {
        int X, Y; cin >> X >> Y;
        E.pb({X, -1*i-1});
        E.pb({Y+1, i});
    }
    sort(all(E));
    int lst = -1;
    int cnt = 0;
    F0R(i, 2*N) {
        if (E[i].s < 0) {
            E[i].s = E[i].s * -1 - 1;
            in[E[i].s] = E[i].f;
            cnt++;
        } else {
            int cur = E[i].s;
            if (lst < in[cur]) {
                cout << cur+1 << nl; return 0;
            }
            cnt--;
        }

        if (i < 2*N-1 && E[i].f != E[i+1].f && cnt == 1) {
            lst = E[i].f;
        }
    }

    cout << -1 << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343