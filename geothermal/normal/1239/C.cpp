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
	
    int N; cin >> N;
    ll P; cin >> P;
    vpl A(N); 
    F0R(i, N) {
        cin >> A[i].f;
        A[i].s = i;
    }
    sort(all(A));
    A.pb({1e18, -1});
    ll T = 0;
    priority_queue<int, vi, greater<int> > q;
    queue<int> q2;
    set<int> inq; inq.ins(N);
    ll ans[N]; 
    queue<pl> rem;
    F0R(i, N+1) {
        while (sz(rem) > 0 && rem.front().f < A[i].f) {
            inq.erase(rem.front().s);
            rem.pop();
        }
        if (!q.empty() && *inq.begin() > q.top()) {
            q2.push(q.top());
            inq.ins(q.top());
            q.pop();
        }
        while (T < A[i].f) {
            while (sz(rem) > 0 && rem.front().f < A[i].f) {
                inq.erase(rem.front().s);
                rem.pop();
            }
            if (!q.empty() && *inq.begin() > q.top()) {
                q2.push(q.top());
                inq.ins(q.top());
                q.pop();
            }
            if (sz(q2) == 0) break;
            T += P;
            ans[q2.front()] = T;
            rem.push({T, q2.front()});
            q2.pop();
        }
        ckmax(T, A[i].f);
        q.push(A[i].s);
    }

    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343