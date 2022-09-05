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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
bool solve(vi& data, int N, int K) {
    int cnt = 0;
    int sta = -1;
    F0R(i, N) {
        if (data[i] == K) {
            sta = i; break;
        }
    }
    if (sta == -1) {
        return false;
    }
/*    sta++;
    FOR(i, sta, N) {
        if (data[i] >= K) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt >= 0) {
            return true;
        }
        if (data[i] == K) {
            cnt = 0;
        }
    }
    return false;*/

    int cur = 0;
    int lo = 200000;
    int last = 0;
    F0R(i, N) {
        last = cur;
        if (data[i] >= K) {
            cur++;
        } else {
            cur--;
        }
        if (cur > lo) return true;
        lo = min(lo, last);
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        vi data(N); F0R(i, N) cin >> data[i];
        bool found = false;
        if (solve(data, N, K)) found = true;
/*        reverse(all(data));
        if (solve(data, N, K)) found = true;*/
        if (N == 1 && data[0] == K) found = true;
        cout << (found?"yes":"no") << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343