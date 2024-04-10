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
 
int get(ll mask, int p, int t) {
    int v = p * 3 + t;
    ll mask2 = mask >> (2*v);
    return mask2 & 3;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int A[3]; F0R(i, 3) cin >> A[i];

        map<ll, int> pos;
        pos.insert({0, 0});
        ll cur = 0;
        vl vals; vals.pb(0);
        int per;
        while (true) {
            int res[3];
            F0R(i, 3) {
                res[i] = 3;
                bool found[4]; F0R(j, 4) found[j] = false;
                F0R(j, 3) {
                    if (i == j && i != 0) continue;
                    found[get(cur, A[j]-1, j)] = true;
/*                    if (get(cur, A[j] - 1, j) == 0) {
                        cout << "ZERO" << " " << i << " " << j << " " << sz(vals) << endl;
                    }*/
                }
                F0R(j, 4) {
                    if (!found[j]) {
                        res[i] = j; break;
                    }
                }
            }

            cur *= 64; cur &= (1ll << 30) - 1;
//            cout << "BEF " << cur << endl;
            cur += 16 * res[2];
            cur += 4 * res[1];
            cur += res[0];
//            cout << "AFT " << cur << endl;

            if (pos.count(cur)) {
                per = sz(vals) - pos[cur];
                break;
            }
            pos[cur] = sz(vals);
            vals.pb(cur);
        }

        int gsum = 0;
        ll state[N];
        int grun[N];
        F0R(i, N) {
            ll cur; cin >> cur; cur--;
            if (cur < sz(vals)) {
                state[i] = vals[cur];
            } else {
                int pStart = sz(vals) - per;
                cur -= pStart;
                cur %= per;
                cur += pStart;
                state[i] = vals[cur];
            }

            bool found[4]; F0R(j, 4) found[j] = false;
            F0R(j, 3) {
                found[get(state[i], A[j] - 1, j)] = true;
            }
            grun[i] = 4;
            F0R(j, 4) {
                if (!found[j]) {
                    grun[i] = j; break;
                }
            }
            gsum ^= grun[i];

/*            cur--;
            if (cur >= sz(vals)) {
                int pStart = sz(vals) - per;
                cur -= pStart;
                cur %= per;
                cur += pStart;
            }
            state[i] = vals[cur];*/
        }
        //cout << vals[3] << endl;
        //cout << vals[1] << " " << vals[2] << endl;
/*        F0R(i, N) {
            cout << grun[i] << " ";
        }
        cout << endl;
        F0R(i, 7) {

        
            cout << get(vals[i], 0, 0) << " " << get(vals[i], 0, 1) << " " << get(vals[i], 0, 2) << endl;
        }*/

        int ans = 0;
        F0R(i, N) {
            F0R(j, 3) {
                int cur = get(state[i], A[j] - 1, j);
                if ((cur ^ grun[i]) == gsum) ans++;
            }
        }
        cout << ans << '\n';
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343