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
        int N, K; cin >> N >> K;
        vector<vi> S(K);
        F0R(i, K) {
            int C; cin >> C;
            F0R(j, C) {
                int cur; cin >> cur; S[i].pb(cur);
            }
        }
        cout << "? " << N << " ";
        FOR(i, 1, N+1) {
            cout << i << " ";
        }
        cout << endl;
        int M; cin >> M;
        int res = 0;
        F0R(bit, 10) {
            vi Q; 
            F0R(i, K) {
                if (i & (1 << bit)) {
                    F0R(j, sz(S[i])) {
                        Q.pb(S[i][j]);
                    }
                }
            }
            if (sz(Q) == 0) continue;
            cout << "? " << sz(Q) << " ";
            F0R(i, sz(Q)) cout << Q[i] << " ";
            cout << endl;
            int X; cin >> X;
            if (X == M) res += (1 << bit);
        }
        bool in[N]; F0R(i, N) in[i] = true;
        int cnt = N;
        F0R(i, K) {
            bool good = i == res;
            if (good) {
                F0R(j, sz(S[i])) {
                    in[S[i][j]-1] = false;
                    cnt--;
                }

                break;
            }
        }
        cout << "? " << cnt << " ";
        F0R(i, N) {
            if (in[i]) cout << i+1 << " ";
        }
        cout << endl;
        int M2; cin >> M2;
        cout << "! ";
        F0R(i, K) {
            int val = M;
            if (i == res) val = M2;
            cout << val << " ";
        }
        cout << endl;
        string ans; cin >> ans;
        if (ans != "Correct") return 0;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343