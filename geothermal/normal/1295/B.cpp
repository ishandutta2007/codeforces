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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;

    while(T--) {
        int N; ll X; cin >> N >> X;
        string S; cin >> S;
        int count[2]; F0R(i, 2) count[i] = 0;
        F0R(i, N) count[S[i]-'0']++;
        if (count[0] < count[1]) {
            F0R(i, N) S[i] = (char) ('1' - S[i] + '0');
            X = -1 * X;
            int curVal = count[0]; count[0] = count[1]; count[1] = curVal;
        }

        ll total = count[0] - count[1];
        if (total == 0) {
            ll pref = 0;
            F0R(i, N) {
                pref += 1 - 2*(S[i] - '0');
                if (pref == X) {
                    cout << -1 << endl; goto done;
                }
            }
            cout << 0 << endl;
        } else {
            int ans = 0;
            ll modTotal = X; while (modTotal < 0) modTotal += 10000 * total;
            modTotal %= total;
            if (X == 0) ans++;
            ll val, res; val = 0; res = 0;
            F0R(i, N) {
                val += 1 - 2*(S[i] - '0');
                res += 1 - 2*(S[i] - '0');
                if (res < 0) res += total;
                res %= total;
                if (res == modTotal && val <= X) ans++;

            }

            cout << ans << endl;
        }


        done:;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343