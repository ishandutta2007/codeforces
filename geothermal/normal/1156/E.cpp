#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 500001; //check the limits, dummy

ll SZ = 262144;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return max(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    F0R(i, 2*SZ) seg[i] = 0LL;

    ll data[N];
    set<pl > locs; 
    F0R(i, N) {
    	cin >> data[i];
    	update(i, data[i]*MX+i);
    	locs.insert(mp(data[i], i));
    }

    queue<pi> q;
    ll ans = 0;
    q.push(mp(0, N-1));

    while (!q.empty()) {
    	pi cur = q.front(); q.pop();
    	int A = cur.f, B = cur.s;
    	if (B-A+1 < 2) continue;
    	ll res = query(A, B);
    	ll value = res / MX; ll pos = res % MX;

    	ll loB, hiB, oLo, oHi;
    	if (B - (pos+1) > (pos-1) - A) {
    		loB = A; hiB = pos-1;
    		oLo = pos+1; oHi = B;
    	} else {
    		oLo = A; oHi = pos-1;
    		loB = pos+1; hiB = B;
    	}
    	FOR(i, loB, hiB+1) {
    		ll val = data[i];
    		ll goal = value - val;
    		auto best = locs.lower_bound(mp(goal, oLo));

    		if (best != locs.end() && *best <= mp(goal, oHi)) {
    			ans++;
    		}
    	}

    	q.push(mp(pos+1, B));
    	q.push(mp(A, pos-1));
    }
    cout << ans << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343