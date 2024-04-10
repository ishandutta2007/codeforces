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

int N, M;

bool valid (int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        cin >> N >> M;
        bool wall[N][M]; F0R(i, N) F0R(j, M) wall[i][j] = false;
        bool need[N][M]; F0R(i, N) F0R(j, M) need[i][j] = false;
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        F0R(i, N) {
            F0R(j, M) {
                char C; cin >> C;
                if (C == 'G') {
                    need[i][j] = true;
                }  else if (C == '#') {
                    wall[i][j] = true;
                } else if (C == 'B') {
                    wall[i][j] = true;
                    F0R(k, 4) {
                        if (valid(i+dx[k], j+dy[k])) {
                            wall[i+dx[k]][j+dy[k]] = true;
                        }
                    }
                }
            }
        }

        bool vis[N][M]; F0R(i, N) F0R(j, M) vis[i][j] = false;
        queue<pi> q;
        if (!wall[N-1][M-1]) {
            q.push({N-1, M-1});
            vis[N-1][M-1] = true;
        }
        while (!q.empty()) {
            pi cur = q.front(); q.pop();
            int x = cur.f, y = cur.s;
            F0R(i, 4) {
                int nx = cur.f + dx[i], ny = cur.s + dy[i];
                if (valid(nx, ny) && !vis[nx][ny] && !wall[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        F0R(i, N) {
            F0R(j, M) {
                if (need[i][j] && !vis[i][j]) {
                    cout << "No" << nl; goto done;
                }
            }
        }


        cout << "Yes" << nl;
        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343