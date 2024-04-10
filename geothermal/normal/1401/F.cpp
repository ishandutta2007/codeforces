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
const int MX = 20; //check the limits, dummy

struct Node {
    Node* L;
    Node* R;
    int A, B;
    int dep;
    bool rev[MX];
    bool swp[MX];
    int di = 0;
    ll sum = 0;
    Node(int _A, int _B, int _D) {
        A = _A, B = _B;
        dep = _D;
        F0R(i, MX) rev[i] = false;
        F0R(i, MX) swp[i] = false;
        if (A != B) {
            L = new Node(A, (A+B)/2, dep-1);
            R = new Node((A+B)/2 + 1, B, dep-1);
        } else {
            L = NULL; R = NULL;
        }
    }

    void pull() {
        A += di; B += di; 
        if (A != B) {
            L->di += di;
            R->di += di;
        }
        di = 0;
        if (A != B) sum = L->sum + R->sum;
    }

    void push() {
        A += di; B += di;
        if (A != B) {
            L->di += di;
            R->di += di;
        }
        di = 0;
        if (A == B) return;
        if (rev[dep]) {
            L->di += (1 << (dep-1));
            R->di -= (1 << (dep-1));
            swap(L, R);
            L->rev[dep-1] = !L->rev[dep-1];
            R->rev[dep-1] = !R->rev[dep-1];
            rev[dep] = false;
            
        }
        if (swp[dep]) {
            L->di += (1 << (dep-1));
            R->di -= (1 << (dep-1));
            swap(L, R);
            swp[dep] = false;
        }
        F0R(i, dep) {
            if (swp[i]) {
                L->swp[i] = !L->swp[i];
                R->swp[i] = !R->swp[i];
                swp[i] = false;
            }
            if (rev[i]) {
                L->rev[i] = !L->rev[i];
                R->rev[i] = !R->rev[i];
                rev[i] = false;
            }
        }
    }

    void updVal(int p, ll k) {
        push();
        pull();
        if (A == B) {
            sum = k; return;
        } 
        if (p <= (A+B)/2) {
            L->updVal(p, k);
        } else {
            R->updVal(p, k);
        }
        pull();
    }

    void updRev(int k) {
        rev[k] = !rev[k];
    }

    void updSwp(int k) {
        swp[k+1] = !swp[k+1];
    }

    ll getSum(int X, int Y) {
        push();
        pull();
//        cout << X << " " << Y << " " << A << " " << B << endl;
        if (X == A && Y == B) return sum;
        ll ans = 0;
        if (X <= (A+B)/2) {
            ans += L->getSum(X, min(Y, (A+B)/2));
        }
        if (Y > (A+B)/2) {
            ans += R->getSum(max(X, (A+B)/2 + 1), Y);
        }
        return ans;
    }

    void dfs() {
        push();
        pull();
        cout << A << " " << B << " " << sum << nl;
        if (A == B) return;
        cout << A << " " << B << " left:" << nl;
        L->dfs();
        cout << A << " " << B << " right:" << nl;
        R->dfs();
    }
    
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, Q; cin >> N >> Q;
    Node seg(0, (1 << N) - 1, N);

    F0R(i, (1 << N)) {
        ll X; cin >> X;
        seg.updVal(i, X);
    }
    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            int X, K; cin >> X >> K; X--;
            seg.updVal(X, K);
        } else if (T == 2) {
            int K; cin >> K; seg.updRev(K);
        } else if (T == 3) {
            int K; cin >> K; seg.updSwp(K);
        } else {
            int L, R; cin >> L >> R; L--; R--;
            cout << seg.getSum(L, R) << nl;
        }
    }

/*    F0R(i, 4) {
        cout << seg.getSum(i, i) << nl;
    }*/
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343