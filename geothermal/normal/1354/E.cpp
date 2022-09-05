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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;

    int col[N]; F0R(i, N) col[i] = -1;
    int C[3]; F0R(i, 3) cin >> C[i];
    vector<vi> graph(N);
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    vector<pair<vi, vi> > comps;
    F0R(r, N) {
        if (col[r] != -1) continue;
        col[r] = 0;
        queue<int> q;
        q.push(r);
        pair<vi, vi> curp;
        curp.f.pb(r);
        while (!q.empty()) {
            int cur = q.front(); q.pop();

            trav(a, graph[cur]) {
                if (col[a] == col[cur]) {
                    cout << "NO" << nl; return 0;
                } else if (col[a] == -1) {
                    col[a] = 1 - col[cur];
                    if (col[a]) {
                        curp.s.pb(a);
                    } else {
                        curp.f.pb(a);
                    }
                    q.push(a);
                }
            }
        }
        comps.pb(curp);
    }
    int dp[sz(comps) + 1][N+1]; 
    F0R(i, sz(comps) + 1) F0R(j, N+1) dp[i][j] = 0;

    dp[0][0] = 1;
    F0R(i, sz(comps)) {
        F0R(j, N+1) {
            if (dp[i][j] == 0) continue;

            dp[i+1][j+sz(comps[i].f)] = 1;
            dp[i+1][j+sz(comps[i].s)] = 2;
        }
    }
    if (dp[sz(comps)][C[1]] == 0) {
        cout << "NO" << nl; return 0;
    }
    cout << "YES" << nl;
    int cur = C[1];
    F0Rd(i, sz(comps)) {
        vi X, Y;
        if (dp[i+1][cur] == 1) {
            X = comps[i].f; Y = comps[i].s; //X gets 1s
        } else {
            X = comps[i].s; Y = comps[i].f;
        }
        cur -= sz(X);
        trav(a, X) col[a] = 1;
        trav(a, Y) {
            if (C[2] > 0) {
                col[a] = 2;
                C[2]--;
            } else {
                col[a] = 0;
            }
        }
    }

    F0R(i, N) {
        cout << col[i]+1;
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343