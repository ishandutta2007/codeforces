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
    
    int N, M; cin >> N >> M;
    char data[N][M];
    F0R(i, N) {
    	F0R(j, M) {
    		cin >> data[i][j];
    	}
    }

    int stripe[N][M];
    F0R(i, N) {
    	F0R(j, M) {
    		stripe[i][j] = -1;
    	}
    }

    F0R(i, M) {
    	vector<pair<int, char> > shorts;
    	char last = data[0][i];
    	int count = 1;
    	FOR(j, 1, N) {
    		if (data[j][i] != last) {
    			shorts.pb(mp(count, last));
    			count = 0;
    			last = data[j][i];
    		}
    		count++;
    	}

    	shorts.pb(mp(count, last));
    	int pref = 0;
    	F0R(j, sz(shorts)) {
    		int length = shorts[j].f;
    		if (j > 0 && shorts[j-1].f >= length && j < sz(shorts)-1 && shorts[j+1].f >= length) {
    			stripe[pref-length][i] = 26*26*(shorts[j-1].s - 'a') + 26*(shorts[j].s - 'a') + shorts[j+1].s - 'a';
    		}
    		pref += shorts[j].f;
    	}

    }

    bool visited[N][M];
    F0R(i, N) {
    	F0R(j, M) {
    		visited[i][j] = false;
    	}
    }

    ll ans = 0;

    F0R(i, N) {
    	F0R(j, M) {
    		if (visited[i][j]) continue;
    		visited[i][j] = true;
    		if (stripe[i][j] < 0) continue;
    		int length = 1;
    		FOR(k, j+1, M) {
    			if (stripe[i][k] != stripe[i][j]) {
    				break;
    			}
    			length++;
    			visited[i][k] = true;
    		}

    		ans += (length * length + length) / 2;
    	}
    }

    cout << ans << endl;
    
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343