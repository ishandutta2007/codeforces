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
    
    ll A, B; cin >> A >> B;
    ll N = 0, sum = 0;
    while (sum+N+1 <= A+B) {
    	N++;
    	sum += N;
    }


    ll lo = min(A, B), hi = max(A, B);
    vl loData, hiData;
    FORd(i, 1, N+1) {
    	if (lo >= i) {
    		lo -= i;
    		loData.pb(i);
    	} else {
    		hiData.pb(i);
    	}
    }

    if (hi == A) {
    	cout << sz(hiData) << endl;
    	F0R(i, sz(hiData)) {
    		cout << hiData[i] << " ";
    	}
    	cout << endl;

    	cout << sz(loData) << endl;
    	F0R(i, sz(loData)) {
    		cout << loData[i] << " ";
    	}
    	cout << endl;
    } else {
    	cout << sz(loData) << endl;
    	F0R(i, sz(loData)) {
    		cout << loData[i] << " ";
    	}
    	cout << endl;

    	cout << sz(hiData) << endl;
    	F0R(i, sz(hiData)) {
    		cout << hiData[i] << " ";
    	}
    	cout << endl;
    }
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343