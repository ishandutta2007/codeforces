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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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
const int MX = 100001; 

ll get(ll D1, ll D2, bool B1, bool B2, int M) {
    if (B1 && B2) { // both right
        return M - (D1+D2)/2;
    } else if (B1 && !B2) {
        return (D2-D1)/2;
    } else if (!B1 && B2) {
        return M+(D1-D2)/2;
    } else {
        return (D1+D2)/2;
    }
}

map<int, int> go(vi &A, vector<bool> &B, vi &C, int M) {
    int N = sz(A);
    set<int> in;
    F0R(i, N) in.ins(i);
    pqg<pair<int, pi>> q;
    F0R(i, N-1) {
        q.push({get(A[i], A[i+1], B[i], B[i+1], M), {i, i+1}});
    }

    map<int, int> ans;
    while (!q.empty()) {
        int X = q.top().s.f, Y = q.top().s.s;
        int D = q.top().f;
        q.pop();
        if (!in.count(X) || !in.count(Y)) continue;
        ans[C[X]] = D; ans[C[Y]] = D;
        in.erase(X); in.erase(Y);
        auto it = in.ub(X);
        if (it != in.begin()) {
            it--;
            int L = *it;
            it++;
            if (it != in.end()) {
                int R = *it;
                q.push({get(A[L], A[R], B[L], B[R], M), {L, R}});
            }
        }
    }
    return ans;
    
}

void solve() {
    int N, M; cin >> N >> M;
    int X[N]; F0R(i, N) cin >> X[i];
    bool R[N]; F0R(i, N) {
        char C; cin >> C; R[i] = C == 'R';
    }

    vpi coords; F0R(i, N) coords.pb({X[i], i});
    sort(all(coords));
    vi A[2], C[2]; vector<bool> B[2];
    F0R(i, sz(coords)) {
        int v = coords[i].f%2;
        int p = coords[i].s;
        C[v].pb(p);
        A[v].pb(X[p]);
        B[v].pb(R[p]);
    }

    map<int, int> ans[2];
    ans[0] = go(A[0], B[0], C[0], M);
    ans[1] = go(A[1], B[1], C[1], M);
    F0R(i, N) {
        if (ans[0].count(i)) {
            cout << ans[0][i] << " ";
        } else if (ans[1].count(i)) {
            cout << ans[1][i] << " ";
        } else cout << -1 << " ";
    }
    cout << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}