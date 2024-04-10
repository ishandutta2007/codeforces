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
	
    int N, K; cin >> N >> K;
    int in[(1 << N)]; F0R(i, (1 << N)) in[i] = false;
    F0R(i, K) {
        int X; cin >> X; in[X-1] = true;
    }

    vector<vi> cur; //neither, winner, loser, both
    F0R(i, (1 << (N-1))) {
        if (in[i*2] && in[i*2+1]) {
            cur.pb({-100, -100, -100, 1}); 
        } else if (!in[i*2] && !in[i*2+1]) {
            cur.pb({0, -100, -100, -100});
        } else {
            cur.pb({-100, 1, 1, -100});
        }
    }

    while (sz(cur) > 1) {
        vector<vi> nxt;
        F0R(i, sz(cur)/2) {
            nxt.pb({-100, -100, -100, -100});
        }
        F0R(i, sz(cur)/2) {
            F0R(a, 4) {
                F0R(b, 4) {
                    F0R(x, 2) {
                        F0R(y, 2) {
                            F0R(z, 2) { //cursed septubly nested loops yeet
                                int val = cur[2*i][a] + cur[2*i+1][b];
                                if ((a | b) & 1) val++;
                                if ((a | b) & 2) val++;
                                int ww;
                                if (x) {
                                    ww = a & 1;
                                } else {
                                    ww = b & 1;
                                }
                                int lw;
                                if (x) {
                                    lw = b & 1;
                                } else {
                                    lw = a & 1;
                                }
                                lw *= 2;
                                int wl;
                                if (y) {
                                    wl = a & 2;
                                } else {
                                    wl = b & 2;
                                }

                                if ((wl | lw) & 2) val++;

                                int s;
                                if (z) {
                                    s = wl;
                                } else {
                                    s = lw;
                                }

                                ckmax(nxt[i][ww+s], val);
                            }
                        }
                    }
                }
            }
        }

        cur = nxt;
        
    }

    int ans = cur[0][0];
    FOR(i, 1, 4) ckmax(ans, cur[0][i]+1);

    cout << ans << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343