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
	
    int N; cin >> N;
    vpl data;
    F0R(i, N) {
        int A, B; cin >> A >> B;
        data.pb({A, B});
    }

    vl vals;
    F0R(i, N) {
        vals.pb(data[i].f*data[i].f+data[i].s*data[i].s);
    }

    set<ll> used;
    F0R(i, N) used.insert(vals[i]);
    if (sz(used) == 1) {
/*        vector<pair<ld, int> > sines;
        F0R(i, N) {
            sines.pb({asin((ld) (data[i].s) / (ld) (vals[0])), i});
            if (data[i].f < 0) sines[i].f += acos(-1);
        }
        sort(all(sines));
        cout << N/2 << endl;
        for (int i = 1; i < sz(sines); i+=2) {
            cout << sines[i].s + 1 << " ";
        }
        cout << endl; return 0;*/
        F0R(i, N) data[i].f++;
    }

    while (true) {
        int counts[4]; F0R(i, 4) counts[i] = 0;
        int modulo[N]; 
        F0R(i, N) {
            int cur = 0;
            if (data[i].f % 2 ) {
                cur += 2;
            }
            if (data[i].s % 2) {
                cur++;
            }
            counts[cur]++;
            modulo[i] = cur;
        }
        if (counts[0] == N || counts[1] == N || counts[2] == N || counts[3] == N) {
            if (counts[1] == N || counts[3] == N) {
                F0R(i, N) data[i].s--;
            } 
            if (counts[2] == N || counts[3] == N) {
                F0R(i, N) data[i].f--;
            }
            F0R(i, N) {
                data[i].f /= 2; data[i].s /= 2;
            }
        } else {
            vi ans;
            if (counts[0] + counts[3] > 0 && counts[1] + counts[2] > 0) { 
                F0R(i, N) if (modulo[i] == 0 || modulo[i] == 3) ans.pb(i);
            } else {
                int least = 5; F0R(i, 4) if (counts[i] > 0) least = i;
                F0R(i, N) if (modulo[i] == least) ans.pb(i);
            }
            cout << sz(ans) << endl;
            F0R(i, sz(ans)) {
                cout << ans[i] + 1 << " ";
            }
            cout << endl; return 0;
        }
    }

/*    F0R(it, 25) {
        int count[2];
        F0R(i, N) {
            count[data[i].f%2 + data[i].s%2]++;
        }
        if (count[0] > 0 && count[1] > 0) {
            vl ans;
            F0R(i, N) {
                if (data[i].f % 2 == data[i].s % 2) {
                    ans.pb(i);
                }
            }
            cout << sz(ans) << endl;
            F0R(i, sz(ans)) {
                cout << ans[i] << " ";
            }
            cout << endl;
            return 0;
        }
        if (count[0] == 0) {
            F0R(i, N) data[i].f--;
        }
        
    }*/
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343