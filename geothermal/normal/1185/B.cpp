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
    
    int T; cin >> T;
    F0R(testCase, T) {
    	string S[2]; cin >> S[0] >> S[1];
    	vector<pair<char, int> > data[2];

    	F0R(arr, 2) {
    		char last = S[arr][0];
    		int count = 1;
    		FOR(i, 1, sz(S[arr])) {
    			if (S[arr][i] != last) {
    				data[arr].pb(mp(last, count));
    				last = S[arr][i];
    				count = 0;
    			}
    			count++;
    		}
    		data[arr].pb(mp(last, count));
    	}

    	if (sz(data[0]) != sz(data[1])) {
    		cout << "NO" << endl; continue;
    	}

    	F0R(i, sz(data[0])) {
    		if (data[0][i].f != data[1][i].f || data[0][i].s > data[1][i].s) {
    			cout << "NO" << endl; goto done;
    		}
    	}
    	cout << "YES" << endl;
    	done:;
    }
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343