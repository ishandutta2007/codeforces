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
const int MX = 300001; //check the limits, dummy
ll* data = new ll[MX]; ll* mask = new ll[MX];
int N;

int countBits(ll X) {
	int count = 0;
	while (X > 0) {
		X &= X-1;
		count++;
	}
	return count;
}

ll calc(ll cur) {
	ll sum = 0;
	F0R(i, N) {
		if (countBits(mask[i] & cur) % 2 == 1) {
			sum -= data[i];
		} else sum += data[i];
	}
	return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N; 

    ll oSum = 0;
    F0R(i, N) {
    	cin >> data[i] >> mask[i];
    	oSum += data[i];
    }
    
    vpl dataByBit[63];
    ll powTwos[63];
    F0R(i, 63) powTwos[i] = (1LL << i);

    FOR(i, 1, 63) {
    	F0R(j, N) { 
    		if (mask[j] < powTwos[i] && mask[j] >= powTwos[i-1]) { 
    			dataByBit[i].pb(mp(data[j], mask[j]));

    		}
    	}
    }

    ll resMask = 0;
    FOR(i, 1, 63) {
    	ll sumToggle = 0;
    	F0R(j, sz(dataByBit[i])) {
    		if (countBits(dataByBit[i][j].s & resMask) % 2 == 0) { 
    			sumToggle -= dataByBit[i][j].f;
    		} else {
    			sumToggle += dataByBit[i][j].f;
    		}
    	}


    	if ((sumToggle > 0 && oSum < 0) || (sumToggle < 0 && oSum > 0)) {
    		resMask += powTwos[i-1];
    	}
    }

    cout << resMask << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343