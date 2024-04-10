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

string go(string A, string B) {
    string res;
    int x = 0, y = 0;
    while (x < sz(A) || y < sz(B)) {
        if (x == sz(A)) {
            res += B[y]; y++;
        } else if (y == sz(B)) {
            res += A[x]; x++;
        } else if (A[x] == '0') {
            res += '0'; x++;
        } else if (B[y] == '0') {
            res += '0'; y++;
        } else {
            res += '1'; x++; y++;
        }
    }
    return res;
}

void solve() {

    int N; cin >> N;
    string S[3]; F0R(i, 3) cin >> S[i];
    int cnt[3];
    F0R(i, 3) {
        cnt[i] = 0;
        trav(a, S[i]) cnt[i] += a - '0';
    }

    int num = 0; F0R(i, 3) if (cnt[i] >= N) num++;
    bool flp = false;
    if (num < 2) flp = true;
    if (flp) {
        F0R(i, 3) {
            cnt[i] = 2*N-cnt[i];
            trav(a, S[i]) a = '0' + '1' - a;
        }
    }
    vector<string> use;
    F0R(i, 3) {
        if (cnt[i] >= N) {
            use.pb(S[i]);
        }
    }
    string res = go(use[0], use[1]);
    trav(a, res) {
        if (flp) {
            cout << (char) ('0' + '1' - a);
        } else {
            cout << a;
        }
    }
    cout << nl;

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