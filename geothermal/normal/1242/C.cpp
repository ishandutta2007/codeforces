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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    vector<vl> A(N);
    map<ll, int> loc;
    ll sum = 0;
    F0R(i, N) {
        int K; cin >> K;
        F0R(j, K) {
            ll X; cin >> X; A[i].pb(X);
            loc[X] = i;
            sum += X;
        }
    }

    if (sum % N) {
        cout << "No" << nl; return 0;
    }
    sum /= N;
    ll tot[N]; F0R(i, N) {
        tot[i] = 0;
        F0R(j, sz(A[i])) tot[i] += A[i][j];
    }

    bool way[(1 << N)];
    F0R(i, (1 << N)) way[i] = false;
    vector<pair<int, pl> > how[(1 << N)];
    F0R(sta, N) {
        F0R(ep, sz(A[sta])) {
            ll sel = A[sta][ep];
            ll nxt = sum - tot[sta] + sel;
            int mask = 1 << sta;
            int lpos = sta;
            vector<pair<int, pl> > cway;
            while (nxt != sel) {
                if (!loc.count(nxt)) {
                    goto bad;
                }
                int pos = loc[nxt];
                cway.pb({pos, {nxt, lpos}});
                if (mask & (1 << pos)) goto bad;
                mask += 1 << pos;
                nxt = sum - tot[pos] + nxt;
                lpos = pos;
            }
            cway.pb({sta, {sel, lpos}});
            way[mask] = true;
            how[mask] = cway;
            bad:
            ;

        }
    }

    bool found[1 << N];
    int last[1 << N];

    F0R(i, 1 << N) found[i] = false;
    found[0] = true;
    last[0] = 0;

    FOR(i, 1, 1 << N) {
        for (int j = (i-1) & i; ; j = (j-1) & i) {
            if (found[j] && way[i-j]) {
                found[i] = true; last[i] = i-j;
                break;
            }
            if (j == 0) break;
        }
    }
    if (!found[(1 << N)-1]) {
        cout << "No" << nl; return 0;
    }

    cout << "Yes" << nl;

    int cur = (1 << N) - 1;
    vpl res(N);

    while (cur > 0) {
        int val = last[cur];
        cur -= val;
        trav(a, how[val]) {
            res[a.f] = a.s;
        }
    }

    F0R(i, N) {
        cout << res[i].f << " " << res[i].s + 1 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343