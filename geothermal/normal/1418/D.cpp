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
	
    int N, Q; cin >> N >> Q;
    multiset<ll> difs;
    ll sum = 0;
    difs.ins(0);
    set<ll> cur;
    vl A(N);
    F0R(i, N) {
        cin >> A[i];
        cur.ins(A[i]);
    }
    sort(all(A)); F0R(i, N-1) difs.ins(A[i+1] - A[i]);
    sum = A[N-1] - A[0];
    cout << sum - *difs.rbegin() << nl;
    while(Q--) {
        int T, X; cin >> T >> X;
        if (T == 0) {
            auto it = cur.find(X);
            ll nxt = 0;
            int cnt = 0;
            if (it != cur.begin()) {
                cnt++;
                auto it2 = it; it2--;
                nxt -= *it2;
                difs.erase(difs.find(*it-*it2));
            } 
            if (it != --cur.end()) {
                auto it2 = it; it2++;
                cnt++;
                nxt += *it2;
                difs.erase(difs.find(*it2-*it));
            }
            if (cnt == 2) difs.ins(nxt);
            cur.erase(X);
        } else {
            cur.ins(X);
            auto it = cur.find(X);
            ll nxt = 0;
            int cnt = 0;
            if (it != cur.begin()) {
                cnt++;
                auto it2 = it; it2--;
                nxt -= *it2;
                difs.ins(*it-*it2);
            } 
            if (it != --cur.end()) {
                auto it2 = it; it2++;
                cnt++;
                nxt += *it2;
                difs.ins(*it2-*it);
            }
            if (cnt == 2) difs.erase(difs.find(nxt));

        }
        if (sz(cur) == 0) {
            cout << 0 << nl; 
        } else {
//            cout << *cur.rbegin() << " " << *cur.begin() << " " << *difs.rbegin() << nl;
            cout << *cur.rbegin() - *cur.begin() - *difs.rbegin() << nl;
        }
    }

    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343