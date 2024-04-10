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
const int MX = 41; //check the limits, dummy
int in = 18, out;
int N;
vector<vi> graph(MX);

int cc = 0;
bool bi = true;

void ff() {
    int col[N]; F0R(i, N) col[i] = -1;
    F0R(r, N) {
        if (col[r] != -1) continue;

        col[r] = 0;
        queue<int> q; q.push(r);
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            trav(a, graph[cur]) {
                if (col[a] != -1) {
                    if (col[a] == col[cur]) bi = false;
                } else {
                    col[a] = 1 - col[cur]; q.push(a);
                }
            }
        }
        cc++;
    }
}

ll cis() {
    ll mask[N];
    F0R(i, N) {
        mask[i] = 1ll << N; mask[i]--;
        trav(a, graph[i]) {
            mask[i] -= 1ll << a;
        }
    }
    ll dp[(1ll << out)];
    F0R(m, (1ll << out)) {
        ll cm = 1ll << N; cm--;
        F0R(i, out) {
            if (m & (1ll << i)) cm &= mask[i+in];
        }
        bool good = true;
        F0R(i, out) {
            if ((m & (1ll << i)) && !(cm & (1ll << (i+in)))) good = false;
        }
        dp[m] = 0;
        if (good) dp[m] = 1ll;
    }

    F0R(i, out) F0R(m, (1ll << out)) if (m & (1ll << i)) dp[m] += dp[m^(1ll<<i)];
    
    ll ans = 0;
    F0R(m, (1ll << in)) {
        ll cm = 1ll << N; cm--;
        F0R(i, in) {
            if (m & (1ll << i)) cm &= mask[i];
        }
//        cout << cm << endl;
        bool good = true;
        F0R(i, in) {
            if ((m & (1ll << i)) && !(cm & (1ll << (i)))) good = false;
        }
        if (good) {
            ans += dp[cm >> in];
        }
//        cout << m << " " << cm << " " << (cm >> in) << " " << ans << endl;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    int M; cin >> M;
    vpi edges; 
    bool found[N]; F0R(i, N) found[i] = false;
    F0R(i, M) {
        int A, B; cin >> A >> B;
        A--; B--;
        edges.pb({A, B});
        found[A] = true;
        found[B] = true;
    }
    int ind[N]; int nxt = 0;
    ll mul = 1;
    F0R(i, N) {
        if (found[i]) {
            ind[i] = nxt; nxt++;
        } else {
            mul *= 2;
        }
    }
    N = nxt;
    ckmin(in, N);
    out = N - in;

    if (M == 0) {
        cout << 0 << nl; return 0;
    }

    F0R(i, M) {
        int A = edges[i].f;
        int B = edges[i].s;
        A = ind[A];
        B = ind[B];
        graph[A].pb(B);
        graph[B].pb(A);
    }


    ff();
    ll is = cis();
    ll ans = (1ll << N);
    ans -= 2 * is;
    if (!bi) ans -= (1ll << cc);
    ans += 2;
    cout << ans*mul << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343