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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int N, M;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    cin >> N >> M;
    bool B[N][M];

    F0R(i, N) {
        F0R(j, M) {
            char C; cin >> C;
            B[i][j] = C == 'B';
        }
    }

    F0R(ri, N) {
        F0R(rj, M) {
            if (!B[ri][rj]) continue;
            bool vis[N][M][4][2];
            F0R(i, N) {
                F0R(j, M) {
                    F0R(k, 4) {
                        F0R(l, 2) {
                            vis[i][j][k][l] = false;
                        }
                    }
                }
            }
            queue<pair<pi, pi> > q;
            F0R(k, 4) {
                vis[ri][rj][k][0] = true;
                q.push({{ri, rj}, {k, 0}});
            }
            while (!q.empty()) {
                pair<pi, pi> curp = q.front(); q.pop();
                int x = curp.f.f;
                int y = curp.f.s, dir = curp.s.f, cnt = curp.s.s;

                if (valid(x+dx[dir], y+dy[dir]) && B[x+dx[dir]][y+dy[dir]] && !vis[x+dx[dir]][y+dy[dir]][dir][cnt]) {
                    vis[x+dx[dir]][y+dy[dir]][dir][cnt] = true;
                    q.push({{x+dx[dir], y+dy[dir]}, {dir, cnt}});
                }

                if (cnt == 1) continue;
                F0R(i, 4) {
                    if (valid(x+dx[i], y+dy[i]) && B[x+dx[i]][y+dy[i]] && !vis[x+dx[i]][y+dy[i]][i][1]) {
                        vis[x+dx[i]][y+dy[i]][i][1] = true;
                        q.push({{x+dx[i], y+dy[i]}, {i, 1}});
                    }
                }
            }

            F0R(i, N) {
                F0R(j, M) {
                    if (!B[i][j]) continue;
                    bool f = false;
                    F0R(k, 4) {
                        F0R(l, 2) {
                            f = f || vis[i][j][k][l];
                        }
                    }
                    if (!f) {
                        cout << "NO" << nl; return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343