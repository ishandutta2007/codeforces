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
    int N, K; cin >> N >> K;
    
    bool bad[N]; F0R(i, N) bad[i] = false;
    F0R(i, N / K) {
        cout << "R" << endl;
        int cur = i, del = 0;
        F0R(j, N / K) {
            cur = (i + del + N/K) % (N/K);
            F0R(k, K) {
                if (bad[cur*K+k]) continue;
                cout << "? " << cur*K+k+1 << endl;
                char C; cin >> C;
                if (C == 'E') {
                    return 0;
                } 
                if (C == 'Y') bad[cur*K+k] = true;
            }
            if (del >= 0) del++;
            del = -del;
        }
    }

    int ans = 0;
    F0R(i, N) {
        if (!bad[i]) ans++;
    }
    cout << "! " << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343