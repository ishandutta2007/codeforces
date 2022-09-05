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
    int BL = 300;
    queue<int> q[N];

    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;
    bool found[N+1]; F0R(i, N+1) found[i] = false;
    F0R(i, N) {
        q[A[i]].push(i);
    }
    if (sz(q[0]) == N) {
        cout << 1 << nl; return 0;
    }
    found[N] = true;
    F0R(i, N) if (sz(q[i]) == 0) found[N] = false;
/*    vi pos[N];
    F0R(i, N) pos[A[i]].pb(i);

    vpi range[N];
    F0R(i, N) {
        if (sz(pos[i]) == 0) {
            range[i].pb({0, N-1});
        } else {
            range[i].pb({0, pos[i][0]});
            F0R(j, sz(pos[i]) - 1) {
                range[i].pb({pos[i][j], pos[i][j+1]});
            }
            range[i].pb({pos[i][sz(pos[i])-1], N-1});
        }
    }*/
    for (int bl = 0; bl < N; bl += BL) {
        int cnt[bl]; F0R(i, bl) cnt[i] = 0;
        int mis = bl;
        int l = 0, r = 0;
        int na[N]; 
        while (l < N) {
            while (r < N && mis > 0) {
                if (A[r] < bl) {
                    if (cnt[A[r]] == 0) {
                        mis--;
                    }
                    cnt[A[r]]++;
                }
                r++;
            }
            if (mis == 0) {
                na[l] = r-1;
            } else {
                na[l] = N;
            }
            if (A[l] < bl) {
                cnt[A[l]]--;
                if (cnt[A[l]] == 0) mis++;
            }
            l++;
        }
        int nb = min(bl+BL, N);
        FOR(i, bl, nb) {
            int nxt = N-1;
            if (sz(q[i])) nxt = q[i].front();
            bool ok = na[0] <= nxt;
            FOR(j, bl, i) {
                int np = N;
                if (sz(q[j])) np = q[j].front();
                ok = ok && np <= nxt;
            }
            if (ok) found[i] = true;
        }
        F0R(i, N) {
            if (A[i] < bl || A[i] >= nb) continue;
            int X = A[i];
            q[X].pop();
            int nxt = N-1;
            if (sz(q[X])) nxt = q[X].front();
            bool ok = na[i] <= nxt;
            FOR(j, bl, X) {
                int np = N;
                if (sz(q[j])) np = q[j].front();
                ok = ok && np <= nxt;
            }
            if (ok) found[X] = true;
        }

    }

    int ans = N+1;
    F0Rd(i, N+1) {
        if (!found[i]) ans = i;
    }
    cout << ans+1 << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343