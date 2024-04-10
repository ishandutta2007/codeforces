#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int N, M; cin >> N >> M;
    bool found[N][M][4][3];
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    F0R(i, N) {
        F0R(j, M) {
            F0R(k, 4) {
                F0R(l, 3) {
                    found[i][j][k][l] = false;
                }
            }
        }
    }
    int X, Y, A, B;
    bool access[N][M];
    F0R(i, N) {
        F0R(j, M) {
            char C; cin >> C;
            access[i][j] = C != '*';
            if (C == 'S') {
                X = i; Y = j;
            }
            if (C == 'T') {
                A = i; B = j;
            }
        }
    }
    queue<pair<pi, pi> > q;
    F0R(i, 4) {
        found[X][Y][i][0] = true;
        q.push({{X, Y}, {i, 0}});
    }

    while (!q.empty()) {
        pair<pi, pi> cur = q.front(); q.pop();
        int x = cur.f.f, y = cur.f.s;
        int dir = cur.s.f;
        int used = cur.s.s;
        F0R(i, 4) {
            int nU = cur.s.s; if (i != dir) nU++;
            if (nU == 3) continue;
            int nX = x + dx[i];
            int nY = y + dy[i];
            if (nX < 0 || nY < 0 || nX >= N || nY >= M) continue;
            if (!access[nX][nY]) continue;
            if (found[nX][nY][i][nU]) continue;
            found[nX][nY][i][nU] = true;
            q.push({{nX, nY}, {i, nU}});
        }
//        cout << x << " " << y << " " << dir << " " << used << " " << q.size() << endl;
    }

    F0R(i, 4) {
        F0R(j, 3) {
            if (found[A][B][i][j]) {
                cout << "YES" << endl; return 0;
            }
        }
    }
    cout << "NO" << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343