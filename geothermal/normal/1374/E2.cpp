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
	
    int N, M, K; cin >> N >> M >>  K;
    vpi A[4];
    F0R(i, N) {
        int T, X, Y; cin >> T >> X >> Y;
        if (X && Y) {
            A[0].pb({T, i});
        } else if (X) {
            A[1].pb({T, i});
        } else if (Y) {
            A[2].pb({T, i});
        } else {
            A[3].pb({T, i});
        }
    }

    F0R(i, 4) sort(all(A[i]));
    if (sz(A[0]) + sz(A[1]) < K || sz(A[0]) + sz(A[2]) < K || 2*K - M > sz(A[0])) {
        cout << -1 << nl; return 0;
    }
    int nb = min(K, sz(A[0]));
    ll best = 2e9, sum = 0;
    vi P(4);
    vi bp(4);
    F0R(i, nb) {
        sum += A[0][i].f;
    }
    P[0] = nb;
    F0R(i, K - nb) {
        sum += A[1][i].f;
    }
    P[1] = K - nb;
    F0R(i, K-nb) {
        sum += A[2][i].f;
    }
    P[2] = K - nb;
    P[3] = 0;

    while (P[0] + P[1] + P[2] + P[3] < M) {
        int bv = 1e9, ba = -1;
        F0R(i, 4) {
            if (P[i] == sz(A[i])) continue;
            if (ckmin(bv, A[i][P[i]].f)) {
                ba = i;
            }
        }
        P[ba]++; sum += bv;
    }
    best = sum; bp = P;

    F0Rd(i, nb) {
        
        P[0]--;
        sum -= A[0][P[0]].f;
        int pos = K - i;
        if (sz(A[1]) < pos || sz(A[2]) < pos || 2*K-i > M) continue;
        while (P[1] < pos) {
            sum += A[1][P[1]].f;
            P[1]++;
        } 
        while (P[2] < pos) {
            sum += A[2][P[2]].f;
            P[2]++;
        }
        vi cap = {i, pos, pos, 0};
        while (P[0] + P[1] + P[2] + P[3] > M) {
            int bv = 0, ba = -1;
            F0R(i, 4) {
                if (P[i] == cap[i]) continue;
                if (ckmax(bv, A[i][P[i]-1].f)) {
                    ba = i;
                }
            }
            sum -= bv; P[ba]--;
        }

        while (P[0] + P[1] + P[2] + P[3] < M) {
            int bv = 1e9, ba = -1;
            F0R(i, 4) {
                if (P[i] == sz(A[i])) continue;
                if (ckmin(bv, A[i][P[i]].f)) {
                    ba = i;
                }
            }
            P[ba]++; sum += bv;
        }
        while (true) {
            int lo = 1e9, hi = 0, pl = -1, ph = -1;
            F0R(i, 4) {
                if (P[i] != cap[i] && ckmax(hi, A[i][P[i]-1].f)) {
                    ph = i;
                }
                if (P[i] != sz(A[i]) && ckmin(lo, A[i][P[i]].f)) {
                    pl = i;
                }
            }
            if (lo < hi) {
                sum += hi - lo;
                P[ph]--;
                P[pl]++;
            } else break;
        }

        if (ckmin(best, sum)) {
            bp = P;
        }
    }

    cout << best << nl;

    F0R(i, 4) {
        F0R(j, bp[i]) {
            cout << A[i][j].s + 1 << " ";
        }
    }
    cout << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343