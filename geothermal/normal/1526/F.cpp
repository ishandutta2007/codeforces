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

int query(int X, int Y, int Z) {
    cout << "? " << X+1 << " " << Y+1 << " " << Z+1 << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int N; cin >> N;

    int A, B;
    while (true) {
        A = uid(0, N-1);
        B = A;
        while (B == A) B = uid(0, N-1);
        int C = uid(0, N-1);
        while (A == C || B == C) C = uid(0, N-1);
        int X = query(A, B, C);
        if (X <= N/8) {
            break;
        }
    }

    int val[N];
    F0R(i, N) {
        if (i == A || i == B) {
            val[i] = 0;
        } else {
            val[i] = query(A, B, i);
        }
    }
    int cap = 0;
    F0R(i, N) ckmax(cap, val[i]);
    int one, two;
    vi cand;
    F0R(i, N) {
        if (val[i] == cap) {
            one = i;
        } else if (val[i]+1 == cap) {
            cand.pb(i);
        }
    }
    assert(sz(cand) <= 2);
    two = cand[0];
    if (sz(cand) == 2) {
        if (query(one, cand[0], A) == query(one, cand[1], A)) swap(A, B);
        if (query(one, cand[0], A) < query(one, cand[1], A)) {
            two = cand[0];
        } else two = cand[1];
    }
    int ans[N];
    ans[one] = 1; ans[two] = 2;
    F0R(i, N) {
        if (i == one || i == two) continue;
        ans[i] = query(one, two, i) + 2;
    }

    if (ans[0] > ans[1]) {
        F0R(i, N) {
            ans[i] = N+1-ans[i];
        }
    }
    cout << "! ";
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
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