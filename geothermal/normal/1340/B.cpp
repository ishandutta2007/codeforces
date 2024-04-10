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
	
    int vals[] = {0b1110111, 0b0100100, 0b1011101, 0b1101101, 0b0101110, 0b1101011, 0b1111011, 0b0100101, 0b1111111, 0b1101111};
    int N; cin >> N;
    int K; cin >> K;
    int cost[N][10];
    F0R(i, N) {
        int X = 0;
        F0R(j, 7) {
            char C; cin >> C;
            X += (C - '0') * (1 << j);
        }
        F0R(j, 10) {
            if ((vals[j] & X) == X) {
                cost[i][j] = __builtin_popcount(vals[j] - X);
            } else {
                cost[i][j] = K+1;
            }
        }
    }
    bool poss[N+1][K+1]; //i..N-1, K
    F0R(i, N+1) {
        F0R(j, K+1) {
            poss[i][j] = false;
        }
    }

    poss[N][0] = true;
    F0Rd(i, N) {
        F0R(j, K+1) {
            if (!poss[i+1][j]) continue;
            F0R(k, 10) {
                if (j + cost[i][k] <= K) {
                    poss[i][j+cost[i][k]] = true;
                }
            }
        }
    }
    if (!poss[0][K]) {
        cout << -1 << endl; return 0;
    }
    int cur = K;
    F0R(i, N) {
        F0Rd(j, 10) {
            if (cur >= cost[i][j] && poss[i+1][cur-cost[i][j]]) {
                cout << j;
                cur -= cost[i][j];
                goto done;
            }
        }
        done:
        ;
    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343