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
        
        int N; cin >> N;
        int A[2][N];
        int cnt[N]; F0R(i, N) cnt[i] = 0;
        vpi pos(N); F0R(i, N) pos[i] = {-1, -1};
        F0R(i, 2) {
            F0R(j, N) {
                int X; cin >> X; X--;
                A[i][j] = X;
                cnt[X]++;
                if (pos[X].f == -1) {
                    pos[X].f = j;
                } else {
                    pos[X].s = j;
                }
            }
        }
        bool bad = false;
        F0R(i, N) {
            if (cnt[i] != 2) {
                cout << "-1" << nl;
                bad = true; break;
            }
        }
        if (bad) continue;

        bool vis[N]; F0R(i, N) vis[i] = false;
        int ans = 0;
        vi res;
        F0R(r, N) {
            if (vis[r]) continue;
            vis[r] = true;
            int best = 1000000;
            vi use[2];
            F0R(i, 2) {
                int cur = r;
                int sta = i;
                int nxt = pos[A[0][r]].f;
                if (nxt == cur) nxt = pos[A[0][r]].s;
                int val = A[0][r];
                int curVal = sta;
                if (sta) use[i].pb(cur);
                while (nxt != r) {
                    vis[nxt] = true;
                    if ((A[0][cur] == val) == (A[0][nxt] == val)) {
                        sta = 1-sta;
                    }
                    curVal += sta;
                    if (sta) {
                        use[i].pb(nxt);
                    }

                    if (val == A[0][nxt]) {
                        val = A[1][nxt];
                    } else {
                        val = A[0][nxt];
                    }

                    cur = nxt;
                    nxt = pos[val].f;
                    if (nxt == cur) nxt = pos[val].s;
                    
                }
                if ((A[0][cur] == val) == (A[0][nxt] == val) && cur != nxt) {
                    sta = 1-sta;
                }
                if (sta != i) continue;
                ckmin(best, curVal);

            }
            if (best == 1000000) {
                cout << -1 << nl; bad = true; break;
            }
            ans += best;
            if (best == sz(use[0])) {
                trav(a, use[0]) res.pb(a);
            } else trav(a, use[1]) res.pb(a);
        }
        if (bad) continue;
        cout << ans << nl;
        F0R(i, sz(res)) {
            cout << res[i]+1 << " ";
        }
        cout << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343