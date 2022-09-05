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
const int MX = 30001; //check the limits, dummy

ll ch[MX][5];

void solve() {

    int N, C, Q; cin >> N >> C >> Q;
    set<pl> cur[C+1];
    ll del[C+1]; F0R(i, C+1) del[i] = 0;
    int rem[Q]; F0R(i, Q) rem[i] = C;
    vector<vi> atPos(N); 
    vpl toAdd[N][C+1]; 
    int pos[Q];
    ll nc[Q]; 
    int ans[Q]; F0R(i, Q) ans[i] = -1;
    int P[N]; F0R(i, N) cin >> P[i];
    F0R(i, Q) {
        int X; ll K; cin >> X >> K; 
        X--; K--;
        cur[C].ins({K, i});
        pos[i] = X;
        nc[i] = K;
        atPos[X].pb(i);
    }

    F0R(i, N) {
        F0R(j, C+1) {
            trav(a, toAdd[i][j]) { cur[j].ins({a.f+del[j], a.s});
                //cout << i << " " << j << " " << a.f << " " << a.s << " " << del[j] << " " << nc[a.s] << nl;
                nc[a.s] += del[j];
            }
        }
        F0R(j, C+1) {
            vpi ops;
            F0R(k, j+1) {
                if (i+k < N) {
                    ops.pb({P[i+k], k});
                }
            }
            sort(all(ops));
            ll curSum = 0;
            F0R(x, sz(ops)) {
                pi a = ops[x];
                if (a.s == 0) {
                    ll num = 1; if (i < N-1) num = ch[N-i-2][j];
                    del[j] += curSum;
                    curSum = num;
                } else {
                    ll numWith = 1;
                    if (N-i-a.s-1 > 0) numWith = ch[N-i-a.s-2][j-a.s];
/*                    if (i == 1 && j == 1) {
                        cout << del[j] << " " << curSum << " " << numWith << nl;
                    }*/
                    auto it = cur[j].ub({del[j] + curSum, -1});
                    while (it != cur[j].end() && it->f < del[j] + curSum + numWith) {
                        //process this
                        //cout << "PROC " << i << " " << j << " " << a.s << " " << del[j] << " " << curSum << nl;
                        rem[it->s] -= a.s;
                        if (pos[it->s] <= i+a.s) {
                            if (pos[it->s] >= i) ans[it->s] = P[2*i+a.s-pos[it->s]];
                        } else {
                            toAdd[i+a.s+1][rem[it->s]].pb({it->f-curSum-del[j], it->s});
                            nc[it->s] -= curSum + del[j];
                        }
                        cur[j].erase(it);
                        it = cur[j].ub({del[j] + curSum, -1});
                    }

                    curSum += numWith;
                }
/*                if (i == 2 && j == 3) {
                    cout << a.s << " " << del[j] << " " << curSum << nl;
                }*/
            }
            trav(a, atPos[i]) {
                ll num = 1; if (i < N-1) num = ch[N-2-i][j];
/*                if (i == 2 && j == 3 && a == 0) {
                    cout << nc[a] << " " << cur[j].count({nc[a], a}) << " " << num << " " << del[j] << endl;
                }*/
                if (cur[j].count({nc[a], a}) && num > nc[a]-del[j]) {
                    ans[a] = P[i];
                }
            }


        }
        //deal w/ things to be removed here [uhh what does this mean lol]
    }

    F0R(i, Q) {
        cout << ans[i] << nl;
    }
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    ch[0][0] = 1;
    FOR(i, 1, 5) ch[0][i] = 0;
    FOR(i, 1, MX) {
        ch[i][0] = 1;
        FOR(j, 1, 5) {
            ch[i][j] = ch[i-1][j-1] + ch[i-1][j];
        }
    }
    F0R(i, MX) {
        FOR(j, 1, 5) {
            ch[i][j] += ch[i][j-1];
        }
    }
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343