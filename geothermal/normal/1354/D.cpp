#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 1000001; //check the limits, dummy
int N, Q;
int A[MX], K[MX];

bool atleast(int P) {
    int l = 0, h = 0;
    F0R(i, N) {
        if (A[i] >= P) {
            h++;
        } else {
            l++;
        }
    }
    F0R(i, Q) {
        if (K[i] >= P) {
            h++;
        } else if (K[i] > 0) {
            l++;
        } else if (K[i] * -1 > l) {
            h--;
        } else {
            l--;
        }
    }
    return l == 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> Q;
    F0R(i, N) {
        cin >> A[i];
    }
    F0R(i, Q) {
        cin >> K[i];
    }

    int lo = 1;
    int hi = N+1;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (atleast(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo%(N+1) << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343