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
	
    int N, S; cin >> N >> S; S--;
    vi A(N); F0R(i, N) cin >> A[i];
    int ans = 0;
    if (A[S] != 0) {
        A[S] = 0; ans = 1;
    }
    sort(all(A));
    int p1 = 1, p2 = N-1;
    int lst = 0;
    int bck = 0;
    while (p1 <= p2) {
        if (A[p1] == 0) {
            ans++; p1++; bck++;
        } else {
            while (A[p1] > lst+1 && bck > 0) {
                bck--; lst++;
            }
            if (A[p1] > lst+1) {
                ans++;
                bck++; p2--;
            } else {
                ckmax(lst, A[p1]);
                p1++;
            }
        }
    }
    cout << ans << nl;
/*    int cnt[N]; F0R(i, N) cnt[i] = 0;
    F0R(i, N) {
        cnt[A[i]]++;
    }
    int miss = 0;
    int in = 1;
    int val = ans;
    int best = ans + A[0] - 1;
    ans = N;
    FOR(i, 1, N) {
        if (A[i] == 0) {
            miss++;
        } else {
            in += A[i];
        }
        ckmin(ans, val+max(miss, N - in));
    }

    cout << max(ans, best) << nl;*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343