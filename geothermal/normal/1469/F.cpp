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


struct Node {
    Node* l = NULL; Node* r = NULL;
    ll L, R;
    ll sum, lazy;
    
    Node(ll X, ll Y) {
        L = X; R = Y;
        sum = 0; lazy = 0;
    }

    void initChildren() {
        l = new Node(L, (L+R)/2);
        r = new Node((L+R)/2 + 1, R);
    }

    void push() {
        sum = sum + lazy * (R-L+1);
        if (L != R && lazy != 0) {
            if (l == NULL) initChildren();
            l->lazy += lazy; r->lazy += lazy;
        }
        lazy = 0;
    }

    void pull() {
        if (L != R && l != NULL) sum = l->sum + r->sum;
    }

    ll query(ll K) {
        push();
//        cout << L << " " << R << " " << sum << " " << K << nl;
        if (L == R) {
            return (sum >= K ? L : 1e15);
        }
        if (l == NULL) initChildren();
        l->push(); r->push();
        if (l->sum < K) {
            return r->query(K-l->sum);
        }
        return l->query(K);
    }

    void update(int lo, int hi, ll increase) {
        push();
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy = increase;
            push();
            return;
        }
        if (l == NULL) initChildren();
        l->update(lo, hi, increase);
        r->update(lo, hi, increase);
        pull();
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; ll K; cin >> N >> K;
    vi L(N); F0R(i, N) cin >> L[i];
    Node seg(0, 2147483647);

    ll ans = 1e15;
    seg.update(0, 0, 1);
    sort(all(L)); reverse(all(L));
    trav(a, L) {
        int V = seg.query(1);
        seg.update(V, V, -1);
        a--;
        seg.update(V+2, V+1+a/2, 2);
        if (a%2) {
            seg.update(V+2+a/2, V+2+a/2, 1);
        }
//        cout << "STA" << nl;
        ckmin(ans, seg.query(K));
    }
    if (ans > 1e14) {
        cout << -1 << nl; return 0;
    }
    cout << ans << nl;
    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343