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
	
    int N, K; cin >> N >> K;
    bool wall[2][N];
    F0R(i, 2) {
        F0R(j, N) {
            char C; cin >> C;
            wall[i][j] = C == 'X';
        }
    }
    int vis[2][N];
    F0R(i, 2) F0R(j, N) vis[i][j] = 1000000;
    vis[0][0] = 0;
    queue<pi> q; q.push({0, 0});
    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        int x = cur.f, y = cur.s;
        if (vis[x][y] > y) continue;
        if (y + K >= N) {
            cout << "YES" << nl; return 0;
        }
        if (!wall[x][y+1] && vis[x][y+1] > vis[x][y] + 1) {
            vis[x][y+1] = vis[x][y]+1; q.push({x, y+1});
        }
        if (y > 0 && !wall[x][y-1] && vis[x][y-1] > vis[x][y] + 1) {
            vis[x][y-1] = vis[x][y] + 1; q.push({x, y-1});
        }
        if (!wall[1-x][y+K] && vis[1-x][y+K] > vis[x][y] + 1) {
            vis[1-x][y+K] = vis[x][y] + 1; q.push({1-x, y+K});
        }

    }
    cout << "NO" << nl; 
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343