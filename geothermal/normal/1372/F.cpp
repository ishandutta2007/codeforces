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
const int MX = 200001; //check the limits, dummy
int ans[MX];
set<pi> used;
pi query(int L, int R) {
    cout << "? " << L+1 << " " << R+1 << endl;
    int X, F;  cin >> X;
    if (X == -1) exit(0);
    cin >> F;
    return {X, F};
}

map<int, int> cnts;
int solve(int L, int R) {
    if (L > R) return L;
    while (R >= L) {
        pi res = query(L, R);
        if (cnts.count(res.f) && cnts[res.f] > 0) {
            int fir = R - res.s + 1;
            FOR(i, fir, fir+cnts[res.f]) {
                ans[i] = res.f;
            }
            int X = cnts[res.f];
            cnts[res.f] = 0;
            solve(L, fir-1);
            return fir+X;
        } else {
            cnts[res.f] = res.s;
            while (cnts[res.f] != 0) {
                solve(L, L+res.s-1);
                while (ans[L] != 0) L++;
            }
        }
    }

    return max(L, R+1);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;

    solve(0, N-1);
    cout << "! ";
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343