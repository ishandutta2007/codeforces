#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi pos[200]; 
        vi data(N);
        F0R(i, N) {
            int X; cin >> X; X--;
            pos[X].pb(i);
            data[i] = X;

        }

        int cnt[N+1][200];
        F0R(i, 200) cnt[0][i] = 0;
        F0R(i, N) {
            F0R(j, 200) {
                cnt[i+1][j] = cnt[i][j];
            }
            cnt[i+1][data[i]]++;
        }
        int ans = 0;
        F0R(i, 200) {
            F0R(j, sz(pos[i]) / 2) {
                int p1 = pos[i][j];
                int p2 = pos[i][sz(pos[i])-1-j];
                F0R(k, 200) {
                    ans = max(ans, (j+1)*2 + cnt[p2][k] - cnt[p1+1][k]);
                }
            }
        }
        F0R(k, 200) ans = max(ans, cnt[N][k]);

        cout << ans << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343