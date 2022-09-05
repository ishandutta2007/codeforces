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
bool valid(int X, int Y) {
    return X >= 0 && X < N && Y >= 0 && Y < M;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int Q; cin >> N >> M >> Q;
    bool A[N][M];
    F0R(i, N) F0R(j, M) {
        char C; cin >> C; A[i][j] = C == '1';
    }
    ll T[N][M]; F0R(i, N) F0R(j, M) T[i][j] = -1;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    queue<pi> q;
    F0R(i, N) {
        F0R(j, M) {
            bool found = false;
            F0R(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                if (valid(ni, nj) && A[ni][nj] == A[i][j]) found = true;
            }
            if (found) {
                T[i][j] = 0; q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        int x = cur.f, y = cur.s;
        F0R(k, 4) {
            int nx = cur.f + dx[k], ny = cur.s + dy[k];
            if (valid(nx, ny) && T[nx][ny] == -1) {
                T[nx][ny] = T[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }


    F0R(i, Q) {
        ll X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
        bool res = A[X][Y];
        if (T[X][Y] != -1 && Z >= T[X][Y] && (Z - T[X][Y]) % 2) res = !res;
        cout << (res?1:0) << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343