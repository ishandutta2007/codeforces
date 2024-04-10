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
int N, M;
vector<vector<bool> > datas;
vector<vector<int> > maxVal;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
vector<vi> dist;

bool poss(int bound) {
    F0R(i, N) F0R(j, M) dist[i][j] = -1;

    queue<pi> q;
    if (bound == 0) return true;
    F0R(i, N) {
        F0R(j, M) {
            if (maxVal[i][j] > bound) {
                dist[i][j] = 0; q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().f, y = q.front().s; q.pop();
        F0R(i, 8) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) return false;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            if (dist[nx][ny] < bound) q.push({nx, ny});
        }
    }
    F0R(i, N) {
        F0R(j, M) {
            if (dist[i][j] == -1 && datas[i][j]) return false;
        }
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    cin >> N >> M;
    F0R(i, N) datas.pb(vector<bool>(M));
    F0R(i, N) dist.pb(vector<int>(M));
    F0R(i, N) maxVal.pb(vi(M));
    F0R(i, N) F0R(j, M) {
        char C; cin >> C;
        datas[i][j] = C == 'X';
    }

    queue<pi> q;

    F0R(i, N) F0R(j, M) maxVal[i][j] = -1;
    F0R(i, N) {
        F0R(j, M) {
            if (datas[i][j] == false) {

                maxVal[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    vpi edges;
    F0R(i, N) {
        edges.pb({i, 0});
        edges.pb({i, M-1});
    }
    F0R(i, M) {
        edges.pb({0, i});
        edges.pb({N-1, i});
    }

    F0R(i, sz(edges)) {
        int x = edges[i].f, y = edges[i].s;
        if (maxVal[x][y] == -1) {
            maxVal[x][y] = 1; q.push({x, y});
        }
    }

    while (!q.empty()) {
        pi cur = q.front(); q.pop();
        int x = cur.f, y = cur.s;
        F0R(i, 8) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || maxVal[nx][ny] != -1) continue;
            maxVal[nx][ny] = maxVal[x][y] + 1;
            q.push({nx, ny});
        }
    }
    int lo = 0, hi = 1000000;
    F0R(i, 22) {
        int mid = (lo+hi)/2;
        if (poss(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    int ans = min(hi, lo);
    if (poss(max(hi, lo))) {
        ans = max(hi, lo);
    }

    vector<vector<char> > res; F0R(i, N) res.pb(vector<char>(M));

    F0R(i, N) F0R(j, M) res[i][j] = (maxVal[i][j] > ans ? 'X' : '.');
    printf("%d\n", ans);
    F0R(i, N) {
        F0R(j, M) printf("%c", res[i][j]);
        printf("\n");
    }
    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343