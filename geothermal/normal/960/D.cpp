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
typedef complex<ll> cl;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<cl> vcl;
 
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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll MOD = 1ll << 60;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int Q; cin >> Q;
    ll shift[61]; F0R(i, 61) shift[i] = 0;
    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            ll X; cin >> X;
            ll K; cin >> K;
            int lev = 0;
            F0R(i, 61) {
                if ((1ll << (i+1)) > X) {
                    shift[i] += MOD + K;
                    shift[i] %= MOD;
                    break;
                }
            }
        } else if (T == 2) {
            ll X, K; cin >> X >> K;
            bool found = false;
            ll val = 0;
            F0R(i, 61) {
                val *= 2;
                if (!found && (1ll << (i+1)) > X) {
                    val += K + MOD; found = true;
                }
                val %= MOD;
                shift[i] += val; shift[i] %= MOD;

            }
        } else {
             ll X; cin >> X;
             F0R(i, 61) {
                 if ((1ll << (i+1)) > X) {
                         ll bef = (1ll << i);
                         ll aft = X - bef;
                         aft += shift[i];
                         aft %= (1ll << i);
                         aft += bef;
                         X = aft;
                         break;
                 }
             }
             while (X > 0) {
//                 cout << X << endl;

                 F0R(i, 61) {
                     if ((1ll << (i+1)) > X) {
                         ll bef = (1ll << i);
                         ll aft = X - bef;
                         aft += MOD - shift[i];
                         aft %= (1ll << i);
                         aft += bef;
                         cout << aft << " ";
                         break;
                     }
                 }

                 X /= 2;
             }
             cout << endl;
        }

    }

    F0R(i, 5) {
        //cout << i << " " << shift[i] << " " << MOD-shift[i] << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343