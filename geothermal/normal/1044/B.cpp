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
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<vi> graph(N);
        F0R(i, N-1) {
            int A, B; cin >> A >> B; A--; B--;
            graph[A].pb(B);
            graph[B].pb(A);
        }

        set<int> sub1;
        int K1; cin >> K1;
        F0R(i, K1) {
            int X; cin >> X; X--; sub1.ins(X);
        }

        set<int> sub2; int K2; cin >> K2;
        int R = 0;
        F0R(i, K2) {
            int X; cin >> X; X--; R = X; sub2.ins(X);
        }
        cout << "B " << R+1 << endl;
        cin >> R; R--;
        queue<int> q;
        bool vis[N]; F0R(i, N) vis[i] = false;
        vis[R] = true;
        q.push(R);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (sub1.count(cur)) {
                cout << "A " << cur+1 << endl;
                int res; cin >> res; res--;
                cout << "C " << (sub2.count(res)?cur+1:-1) << endl;
                break;
            }
            trav(a, graph[cur]) {
                if (!vis[a]) {
                    vis[a] = true;
                    q.push(a);
                }
            }
        }


    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343