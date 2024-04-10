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
const int MX = 4001; //check the limits, dummy

ll dp[4010][150][100];
int N; 
ll A[MX];
ll sum[MX][100], mus[MX][100];
int cnt = 0;
ll get(int A, int B, int K) {
    if (A > B) return 0;
    int taken = A + N - 1 - B;
    int dif = A - (N-1-B) + 75;
/*    if (taken < 0 || taken >= MX || dif < 0 || dif >= 150 || K >= 100) {
        cout << taken << " " << dif << endl;
        cout << A << " " << B << " " << K << endl; exit(1);
    }*/
    if (dp[taken][dif][K] >= -1e18) {
        return dp[taken][dif][K];
    }
    cnt++;

    ll best = -1e18;
    //case 1: K, done
    if (A+K <= B+1 && A+2*K > B+1) {
        ckmax(best, sum[A][K-1]);
    }
    //case 2: K+1, done
    if (A+K+1 <= B+1 && A+2*K+2 > B+1) {
        ckmax(best, sum[A][K]);
    }
    //case 3: K, smth else
    if (A+2*K <= B+1) {
        ll wc = mus[B][K-1] - get(A+K, B-K, K);
        if (A+2*K+1 <= B+1) {
            ckmax(wc, mus[B][K] - get(A+K, B-K-1, K+1));
        }
        ckmax(best, sum[A][K-1] - wc);
    }

    //case 4: K+1, smth else
    if (A+2*K+2 <= B+1) {
        ll wc = mus[B][K] - get(A+K+1, B-K-1, K+1);
        if (A+2*K+3 <= B+1) {
            ckmax(wc, mus[B][K+1] - get(A+K+1, B-K-2, K+2));
        }
        ckmax(best, sum[A][K] - wc);
    }

    if (best < -1e17) {
//        cout << A << " " << B << " " << K << ": 0" << nl;
        return dp[taken][dif][K] = 0;
    }
//    cout << A << " " << B << " " << K << ": " << best << nl;
    return dp[taken][dif][K] = best;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    F0R(i, 4010) F0R(j, 150) F0R(k, 100) dp[i][j][k] = -2e18;
    cin >> N; F0R(i, N) cin >> A[i];
//    N = 4000; F0R(i, N) A[i] = i;
    F0R(i, N) {
        sum[i][0] = A[i];
        mus[i][0] = A[i];
        FOR(j, 1, 100) {
            sum[i][j] = sum[i][j-1];
            mus[i][j] = mus[i][j-1];
            if (i+j < N) sum[i][j] += A[i+j];
            if (i-j >= 0) mus[i][j] += A[i-j];
        }
    }

    cout << get(0, N-1, 1) << nl;
//    cout << get(4, 4, 1) << nl;
/*    F0R(d, N) {
        F0R(i, N) {
            int j = i+d; if (j >= N) continue;
            FOR(k, 1, 5) {
                cout << i << " " << j << " " << k << " " << get(i, j, k) << nl;
            }
        }
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343