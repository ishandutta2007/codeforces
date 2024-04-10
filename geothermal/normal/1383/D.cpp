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
	
    int N, M; cin >> N >> M;
    int T[N][M]; F0R(i, N) F0R(j, M) cin >> T[i][j];

    set<int> R, C;
    F0R(i, N) {
        int X = 0; F0R(j, M) ckmax(X, T[i][j]);
        R.ins(X);
    }
    F0R(j, M) {
        int X = 0;
        F0R(i, N) ckmax(X, T[i][j]);
        C.ins(X);
    }
    int pr = -1, pc = -1;
    queue<pi> q;
    int A[N][M]; 
    FORd(i, 1, N*M+1) {
        if (R.count(i) || C.count(i)) {
            if (R.count(i)) {
                pr++;
                if (C.count(i) && pc >= 0) q.push({pr, pc});
                F0Rd(j, pc) q.push({pr, j});
            }
            if (C.count(i)) {
                pc++;
                F0Rd(j, pr) q.push({j, pc});
            }
            A[pr][pc] = i;
        } else {
            if (sz(q) == 0) {
                cout << -1 << nl; return 0;
            }
            pi cur = q.front();
            q.pop();
            A[cur.f][cur.s] = i;
        }
    }
    F0R(i, N) {
        F0R(j, M) {
            cout << A[i][j] << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343