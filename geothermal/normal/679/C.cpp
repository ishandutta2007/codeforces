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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}
void solve() {

    int N, K; cin >> N >> K;
    bool wall[N][N]; F0R(i, N) F0R(j, N) {
        char C; cin >> C; wall[i][j] = C == 'X';
    }

    int cc = 0;
    int ccNum[N][N]; F0R(i, N) F0R(j, N) ccNum[i][j] = -1;
    vi total;
    F0R(ri, N) {
        F0R(rj, N) {
            if (ccNum[ri][rj] != -1 || wall[ri][rj]) continue;
            ccNum[ri][rj] = cc;

            queue<pi> q; q.push({ri, rj});
            int cnt = 1;
            while (!q.empty()) {
                int x = q.front().f, y = q.front().s; q.pop();
                F0R(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (valid(nx, ny, N, N) && !wall[nx][ny] && ccNum[nx][ny] == -1) {
                        ccNum[nx][ny] = cc; q.push({nx, ny});
                        cnt++;
                    }
                }
            }
            total.pb(cnt);
            cc++;
        }
    }
    /*F0R(i, N) {
        F0R(j, N) {
            cout << ccNum[i][j] << " ";
        }
        cout << nl;
    }*/
    int ans = 0;
    int cnt[cc];
    bool found[cc]; F0R(i, cc) found[i] = false;
    F0R(x, N-K+1) {
        F0R(i, cc) cnt[i] = 0;
        F0R(i, K) {
            F0R(j, K) {
                if (!wall[x+i][j]) cnt[ccNum[x+i][j]]++;
            }
        }
        F0R(y, N-K+1) {
            vpi pts;
            F0R(i, K) {
                if (valid(x-1, y+i, N, N)) pts.pb({x-1, y+i});
                if (valid(x+K, y+i, N, N)) pts.pb({x+K, y+i});
                if (valid(x+i, y-1, N, N)) pts.pb({x+i, y-1});
                if (valid(x+i, y+K, N, N)) pts.pb({x+i, y+K});
            }
            vi used;
            ll cur = K*K;
            trav(a, pts) {
                if (wall[a.f][a.s]) continue;
                used.pb(ccNum[a.f][a.s]);
                if (!found[ccNum[a.f][a.s]]) {
                    found[ccNum[a.f][a.s]] = true;
/*                    if (x == 3 && y == 1) {
                        cout << ccNum[a.f][a.s] << nl;
                        cout << total[ccNum[a.f][a.s]] << " " << cnt[ccNum[a.f][a.s]] << nl;
                    }*/
                    cur += total[ccNum[a.f][a.s]] - cnt[ccNum[a.f][a.s]];
                }
            }

            if (cur > ans) ans = cur;
            if (y != N-K) {
                F0R(i, K) {
                    if (!wall[x+i][y]) cnt[ccNum[x+i][y]]--;
                    if (!wall[x+i][y+K]) cnt[ccNum[x+i][y+K]]++;
                }
            }
            trav(a, used) found[a] = false;
        }
    }

    cout << ans << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343