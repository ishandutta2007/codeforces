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
    int count[N]; F0R(i, N) count[i] = 0;
    F0R(i, N) {
        int cur; cin >> cur; cur--; count[cur]++;
    }

    int lo[N+1][4], hi[N+1][4]; //1: X occupied, 0: X+1 occupied
    F0R(i, N+1) {
        F0R(j, 4) {
            lo[i][j] = 10*MX, hi[i][j] = -10*MX;

        }
    }
    lo[0][0] = 0; hi[0][0] = 0;

    F0R(i, N) {
        F0R(j, 4) {
            F0R(k, 8) {
                int countBits = 0; F0R(x, 3) if (k & (1 << x)) countBits++;
                int count2 = 0; F0R(x, 2) if (j & (1 << x)) count2++;
                if (countBits-count2 > count[i]) continue;
                if (count[i] > 0 && (k == 0 )) continue;
                F0R(x, 2) {
                    if ((j & (1 << x)) && !(k & (1 << x))) goto bad;
                }
                
                lo[i+1][k/2] = min(lo[i+1][k/2], lo[i][j] + countBits-count2);
                hi[i+1][k/2] = max(hi[i+1][k/2], hi[i][j] + countBits-count2);
                bad:;
            }
        }
    }
    F0R(i, N+1) {
        F0R(j, 4) {
//            cout << i << " " << j << " lo " << lo[i][j] << " hi " << hi[i][j] << endl;
        }
    }

    int aHi = -1, aLo = MX*10;
    F0R(i, 4) {
        aLo = min(aLo, lo[N][i]);
        aHi = max(aHi, hi[N][i]);
    }

    cout << aLo << " " << aHi << endl;


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343