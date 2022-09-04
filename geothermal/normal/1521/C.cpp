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

int ask(int T, int X, int Y, int V) {
    cout << "? " << T << " " << X+1 << " " << Y+1 << " " << V << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int N; cin >> N;
    vi can;
    if (N%2) {
        can.pb(N-1);
    }
    F0R(i, N/2) {
        int V = ask(1, i*2, i*2+1, N-1);
        if (V >= N-1) {
            can.pb(i*2); can.pb(i*2+1);
        }
    }
    int p = -1;
    trav(a, can) {
        int V;
        if (a == 0) {
            V = ask(2, a, 1, N-1);
        } else {
            V = ask(2, a, 0, N-1);
        }
        if (V == N) {
            p = a;
        }
    }
    assert(p != -1);
    int ans[N]; 
    ans[p] = N;
    F0R(i, N) {
        if (i == p) continue;
        int V = ask(2, i, p, 1);
        ans[i] = V;
    }
    cout << "! ";
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

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