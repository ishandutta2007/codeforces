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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int A[N][M];
    char cs[4] = {'D', 'I', 'M', 'A'};
    F0R(i, N) {
        F0R(j, M) {
            char C; cin >> C;
            F0R(k, 4) {
                if (C == cs[k]) A[i][j] = k;
            }
        }
    }
    vector<vi> graph(N*M);
    F0R(i, N) {
        F0R(j, M) {
            F0R(k, 4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (valid(ni, nj, N, M) && (A[i][j] + 1)%4 == A[ni][nj]) {
                graph[i*M+j].pb(ni*M+nj);
            
            }
            }
        }
    }


    queue<int> q;
    int deg[N*M]; F0R(i, N*M) deg[i] = 0;
    F0R(i, N*M) {
        F0R(j, sz(graph[i])) {
            deg[graph[i][j]]++;
        }
    }
    F0R(i, N*M) {
        if (deg[i] == 0) q.push(i);
    }
    vi ord;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ord.pb(cur);
        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    if (sz(ord) != N*M) {
        cout << "Poor Inna!" << nl;
        return 0;
    }
    int dist[N*M]; F0R(i, N*M) dist[i] = -1000000;
    F0R(i, N*M) {
        int cur = ord[i];
        if (A[cur/M][cur%M] == 0) ckmax(dist[cur], 1);
        F0R(j, sz(graph[cur])) {
            int nxt = graph[cur][j];
            ckmax(dist[nxt], dist[cur] + 1);
        }
    }

    int ans = 0; F0R(i, N*M) ckmax(ans, dist[i] / 4);

    if (ans == 0) {
        cout << "Poor Dima!" << nl;
    } else {
        cout << ans << nl;
    }





	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343