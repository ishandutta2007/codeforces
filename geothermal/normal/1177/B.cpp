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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll K; cin >> K;
    int digitCount;
    ll powTen = 9;
    F0R(i, 13) {
    	if (K > powTen * (i+1)) {
    		K -= powTen* (i+1); powTen *= 10;
    	} else {
    		digitCount = i+1;
    		break;
    	}
    }

    ll start = 1; F0R(i, digitCount-1) start *= 10;
    K--;

    //cout << start << endl;
    //cout << K << endl;


    start += K / digitCount;
    K = K % digitCount;
    vl digits;
    while (start > 0) {
    	digits.pb(start % 10);
    	start /= 10;
    }
    reverse(all(digits));

    cout << digits[K] << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343