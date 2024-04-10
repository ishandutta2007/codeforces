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
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        int A[3][N][N]; F0R(i, N) F0R(j, N) cin >> A[0][i][j];
        F0R(i, N) {
            F0R(j, N) {
                A[0][i][j]--;
                A[1][i][j] = i;
                A[2][i][j] = j;
            }
        }
        int shift[3]; F0R(i, 3) shift[i] = 0;
        int cur = 0, rp = 2, cp = 1;
        string S; cin >> S;
        trav(a, S) {
            if (a == 'R') {
                shift[rp]++;
            } else if (a == 'L') {
                shift[rp]--;
            } else if (a == 'D') {
                shift[cp]++;
            } else if (a == 'U') {
                shift[cp]--;
            } else if (a == 'I') {
                swap(cur, rp);
            } else {
                swap(cur, cp);
            }
        }

        int ans[N][N]; F0R(i, N) F0R(j, N) ans[i][j] = -1;
        //rS[cp] *= -1; rS[rp] *= -1; cS[cp] *= -1; cS[rp] *= -1;
        F0R(i, 3) {
            while (shift[i] < 0) shift[i] += N;
            shift[i] %= N;
        }
/*        F0R(i, 3) {
            cout << shift[i] << nl;
        }
        cout << cur << " " << rp << " " << cp << nl;*/
        F0R(i, N) {
            F0R(j, N) {
                int C = (A[rp][i][j] + shift[rp]) % N;
                int R = (A[cp][i][j] + shift[cp]) % N;
                
//                cout << R << " " << C <<  nl;
                ans[R][C] = 1 + (A[cur][i][j] + shift[cur]) % N;
            }
        }

/*        if (ri) {
            F0R(i, N) {
                int old[N]; F0R(j, N) old[j] = ans[i][j]-1;
                F0R(j, N) {
                    ans[i][old[j]] = j+1;
                }
            }
        }
        if (ci) {
            F0R(i, N) {
                int old[N]; F0R(j, N) old[j] = ans[j][i]-1;
                F0R(j, N) {
                    ans[old[j]][i] = j+1;
                }
            }
        }*/

        F0R(i, N) {
            F0R(j, N) {
                cout << ans[i][j] << " ";
            }
            cout << nl;
        }
        cout << nl;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343