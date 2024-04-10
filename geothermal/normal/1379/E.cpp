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

int ans[MX];
bool isPower(int N) {
    bool isPow = false;
    int cur = 1;
    while (cur < MX) {
        cur *= 2;
        if (cur-1 == N) isPow = true;
    }
    return isPow;
}
void solve(int N, int p) {
    if (N == 1) return;
    int cur = 1;
    int A, B;
    A = -1; B = -1;
    int best = 2;
    while (cur*2 < N) {
        cur *= 2;
        int val = 0;
        int X = cur - 1;
        int Y = N - 1 - X;
        if (max(X, Y) >= 2 * min(X, Y)) val++;
        if (!isPower(Y)) val++;
        if (ckmin(best, val)) {
            A = X; B = Y;
        }
    }
    assert(A != -1);
    ans[p+1] = p+1;
    solve(A, p+1);
    ans[p+A+1] = p+1;
    solve(B, p+A+1);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
/*    map<pi, vi> ans;
    ans[{3, 0}] = {0, 1, 1};
    ans[{5, 1}] = {0, 1, 1, 2, 2};
    ans[{7, 0}] = {0, 1, 1, 2, 2, 3, 3};
    ans[{7, 2}] = {0, 1, 1, 2, 2, 4, 4};
    ans[{9, 1}] = {0, 1, 1, 2, 2, 3, 3, 4, 4};
    ans[{9, 3}] = {0, 1, 1, 2, 2, 4, 4, 6, 6};
    ans[{11, 1}] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    ans[{11, 2}] = {*/
    if (N % 2 == 0) {
        cout << "NO" << nl; return 0;
    }
    if (N == 0 && K == 0) {
        cout << "YES\n0\n" << nl; return 0;
    } else if (N == 0 && K == 1) {
        cout << "NO" << nl; return 0;
    }
    if (K > max((N-3)/2, 0)) {
        cout << "NO" << nl; return 0;
    }
    bool isPow = isPower(N);
    if (K == 0 && !isPow) {
        cout << "NO" << nl; return 0;
    }
    if (K == 1 && isPow) {
        cout << "NO" << nl; return 0;
    }
    if (N == 9 && K == 2) {
        cout << "NO" << nl; return 0;
    }
    int M = N;
    ans[0] = 0;
    int R = 0;
    int oK = K;
    while (K > 1) {
        ans[R] = M;
        ans[M-2] = M;
        ans[M-1] = 0;
        R = M-1;
        K--;
        M -= 2;
    }

    if (isPower(M) && K == 1) {
        ans[0] = 0;
        R = 0;
        M = N;
        K = oK;
        while (K > 2) {
            ans[R] = M;
            ans[M-2] = M;
            ans[M-1] = 0;
            R = M-1;
            K--;
            M -= 2;
        }
        ans[R] = M;
        ans[M-1] = 0;
        ans[M-2] = M;
        ans[M-3] = M-1;
        ans[M-4] = M - 1;
        K--;
        M -= 4;
    }


    solve(M, 0);

    cout << "YES" << nl;
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343