#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ctime>

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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
	return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

pl addFrac(pl A, pl B) {
	ll top = add(mul(A.f, B.s), mul(A.s, B.f));
	ll bot = mul(A.s, B.s);
	return mp(top, bot);
}

pl mulFrac(pl A, pl B) {
	return mp(mul(A.f, B.f), mul(A.s, B.s));
}

ll getAns(pl frac) {
	return mul(frac.f, inv(frac.s));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    //N = 5000;


    vi unprocessed(N);
    F0R(i, N) cin >> unprocessed[i];
    //F0R(i, N) unprocessed[i] = i+1;
    sort(all(unprocessed));

    int last = unprocessed[0], count = 1;
    vpi data;
    FOR(i, 1, N) {
        int cur = unprocessed[i];
        if (cur != last) {
        	data.pb(mp(last, count));
        	count = 1;
        	last = cur;
        } else count++;
    }
    data.pb(mp(last, count));

    pl ans = mp(0, 1);
    pl pLow[N+1]; //first: probability of drawing a lower card with N cards left.  second: probability of having the same card with N cards left.
    F0R(i, N+1) {
    	pLow[i] = mp(0, 1);
    }
    pLow[N] = mp(1, 1);
    
    pl curVals[N+1];
    pl zero = mp(0, 1);

    int seen = 0;
    F0R(i, sz(data)) {

    	F0R(i, N+1) curVals[i] = zero;
    	int count = data[i].s;
    	FOR(i, max(count, N-seen), N+1) {
    		curVals[i-1] = addFrac(curVals[i-1], mulFrac(pLow[i], mp(count, i)));
    	}
    	FOR(i, max(count-1, max(1, N-seen-1)), N+1) {
    		ans = addFrac(ans, mulFrac(curVals[i], mp(count-1, i)));
    	}
    	FOR(i, max(count, N-seen)-1, N) {
    		pLow[i] = addFrac(pLow[i], curVals[i]);
    	}
    	seen++;
    }

    cout << getAns(ans) << endl;

    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343