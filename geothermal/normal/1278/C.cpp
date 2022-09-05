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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int data[N][2];
        F0R(i, 2) F0R(j, N) cin >> data[j][i];
        
        int total = 0;
        F0R(i, N) F0R(j, 2) {
            if (data[i][j] == 1) {
                total--;
            } else {
                total++;
            }
        }
        int firstOccur[N*8+1];
        F0R(i, N*8+1) {
            firstOccur[i] = MX;
            
        }
        firstOccur[N*4] = 0;

        int curSum = N*4;
        F0R(i, N) {
            if (data[i][1] == 1) {
                curSum--;
            } else {
                curSum++;
            }
            firstOccur[curSum] = min(firstOccur[curSum], i+1);
        }
        int ans = firstOccur[total+4*N];
        curSum = 0;
        F0R(i, N) {
            if (data[N-i-1][0] == 1) {
                curSum--;
            } else {
                curSum++;
            }
            ans = min(ans, i+1+firstOccur[N*4+total-curSum]);
        }
        cout << ans << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343