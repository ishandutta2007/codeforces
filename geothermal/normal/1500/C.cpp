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

int base;

struct hsh  {
    ll base, p1, p2;

    ll val1, val2;
    ll inv1, inv2;

	ll modExp(ll power, ll prime) {
        if (power == 0) {
            return 1;
        } else {
            ll cur = modExp(power / 2, prime); cur = cur * cur; cur = cur % prime;
            if (power % 2 == 1) cur = cur * base;
            cur = cur % prime;
            return cur;
        }
    }

    hsh() {
    }

    hsh(ll b, string S) {
        p1 = 1000000007;
        p2 = 1000000009;
        base = b;
        val1 = 0;
        val2 = 0;

        inv2 = modExp(p2-2, p2);
        inv1 = modExp(p1-2, p1);
        F0R(i, sz(S)) {
            push_back(S[i] - 'a');
        }
    }

    void push_back(ll v) {
        val1 *= base;
        val1 %= p1;
        val1 += v;
        val1 %= p1;
        val2 *= base;
        val2 %= p2;
        val2 += v;
        val2 %= p2;
    }

    ll get() {
        return val1 * p2 + val2;
    }
};

void prepHash() {
   base = uniform_int_distribution<int>(2000, MOD-2)(rng);
}

void solve() {

    int N, M; cin >> N >> M;
    int A[N][M], B[N][M];
    F0R(i, N) F0R(j, M) cin >> A[i][j];
    F0R(i, N) F0R(j, M) cin >> B[i][j];
    F0R(i, N) F0R(j, M) {
        A[i][j]--; B[i][j]--;
    }
    prepHash();
    map<ll, queue<int>> q;
    F0R(i, N) {
        hsh cur(base, "");
        F0R(j, M) {
            cur.pb(A[i][j]);
        }
        q[cur.get()].push(i);
    }

    vi ord;
    F0R(i, N) {
        hsh cur(base, "");
        F0R(j, M) {
            cur.pb(B[i][j]);
        }
        if (sz(q[cur.get()]) == 0) {
            cout << -1 << nl; return;
        }
        ord.pb(q[cur.get()].front());
        q[cur.get()].pop();
    }

    vi g1[M], g2[N];
    int ind[M]; F0R(i, M) ind[i] = 0;
    F0R(i, N-1) {
        F0R(j, M) {
            if (A[ord[i]][j] < A[ord[i+1]][j]) {
                g1[j].pb(i);
            } else if (A[ord[i]][j] > A[ord[i+1]][j]) {
                g2[i].pb(j);
                ind[j]++;
            }
        }
    }
    queue<int> qu;
    F0R(i, M) {
        if (ind[i] == 0) qu.push(i);
    }
    bool found[N-1]; F0R(i, N-1) found[i] = false;
    vi res;
    while (!qu.empty()) {
        int cur = qu.front(); qu.pop();
        res.pb(cur);
        trav(a, g1[cur]) {
            if (found[a]) continue;
            found[a] = true;
            trav(b, g2[a]) {
                ind[b]--;
                if (ind[b] == 0) qu.push(b);
            }
        }
    }
    F0R(i, N-1) {
        if (!found[i] && ord[i+1] < ord[i]) {
            cout << -1 << nl; return;
        }
    }
    cout << sz(res) << nl;
    F0Rd(i, sz(res)) {
        cout << res[i]+1 << " ";
    }
    cout << nl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343