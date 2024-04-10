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

void solve() {

    int N, K; cin >> N >> K;
    string S; cin >> S;
    if (N%K) {
        cout << -1 << nl; return;
    }
    int p = 0;
    int add = 0;
    vi need(26);

    vi req(26); 
    int sr = 0;
    F0R(i, N) {
        int x = S[i] - 'a';
        FORd(j, x+1, 26) {
            if (req[j] == 0) continue;
            int nr = sr - 1;
            if (nr <= N-i-1) {
                p = i; 
                need = req;
                need[j]--;
                add = j;
            }
        }
        if (x < 25) {
            int nr = sr;
            if (req[x+1] == 0) {
                nr += K-1;
            } else {
                nr -= 1;
            }
            if (nr <= N-i-1) {
                p = i;
                need = req;
                if (need[x+1] == 0) {
                    need[x+1] += K-1;
                } else {
                    need[x+1]--;
                }
                add = x+1;
            }
        }
        if (req[x] == 0) {
            req[x] = K-1;
            sr += K-1;
        } else {
            req[x]--; sr--;
        }

    }

    if (sr == 0) {
        cout << S << nl;
    } else {
        string pre;
        F0R(i, p) pre += S[i];
        pre += 'a' + add;
        string lst;
        F0R(i, 26) {
            F0R(j, need[i]) {
                lst += 'a' + i;
            }
        }
        while (sz(pre) + sz(lst) < sz(S)) pre += 'a';
        cout << pre << lst << nl;
    }

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