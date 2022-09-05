
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000001; //check the limits, dummy
 
vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

vector<vi> graph(MX);
bool vis[MX]; 
int value[MX];

int dfs(int v, int p, int d) {
    if (value[v] != -1) {
        return d - value[v];
    }
    if (vis[v]) return MX;
    vis[v] = true;
    value[v] = d;
    d++;
    int ans = MX;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        ans = min(ans, dfs(nxt, v, d));
    }
    value[v] = -1;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    compPrimes(1000);

    set<int> found;
    set<int> primez;

    bool two = false;
    F0R(i, N) {
        int X; cin >> X;
        vi set;
        F0R(j, sz(primes)) {
            int cnt = 0;
            while (X % primes[j] == 0) {
                cnt++; X /= primes[j];
            }
            if (cnt % 2 == 1) {
                set.pb(primes[j]);
            }
        }
        if (X > 1) {
            set.pb(X);
        }
        if (sz(set) == 0) {
            cout << 1 << endl; return 0;
        } else if (sz(set) == 2) {
            graph[set[0]].pb(set[1]);
            graph[set[1]].pb(set[0]);
            int val = set[0] * set[1];
            if (found.count(val)) two = true;
            found.insert(val);
        } else {
            if (found.count(set[0])) {
                two = true;
            }
            found.insert(set[0]);
            primez.insert(set[0]);
            graph[0].pb(set[0]);
            graph[set[0]].pb(0);
        }

    }


    if (two) {
        cout << 2 << endl; return 0;
    }

    int ans = MX;
    vi in; F0R(i, MX) if (sz(graph[i]) != 0) in.pb(i);
    F0R(i, MX) value[i] = -1;
    int par[MX]; F0R(i, MX) par[i] = -1;
    F0R(root, 1000) {
        if (sz(graph[root]) == 0) continue;
        F0R(i, MX) value[i] = -1, par[i] = -1;
        value[root] = 0;
        queue<int> q({root});
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            F0R(i, sz(graph[cur])) {
                int nxt = graph[cur][i];
                int nD = value[cur] + 1;
                if (value[nxt] == -1) {
                    value[nxt] = nD; q.push(nxt);
                    par[nxt] = cur;
                } else if (par[cur] != nxt) {
                    ans = min(ans, value[cur] + value[nxt] + 1); 
                }
            }
        }
        done:
        ;


    }


    if (ans == MX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343