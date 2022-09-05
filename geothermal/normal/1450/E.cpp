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

pi inter(pi A, pi B) {
    if (A.s < B.f || A.f > B.s) return {0, -1};
    return {max(A.f, B.f), min(A.s, B.s)};
}

vector<vi> graph(MX);
int col[MX];

bool dfs(int v, int c) {
    if (col[v] != -1) {
        return col[v] == c;
    }
    col[v] = c;
    trav(a, graph[v]) {
        if (!dfs(a, 1-c)) return false;
    }
    return true;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M; F0R(i, N) col[i] = -1;
    int lo[N][N], hi[N][N];
    F0R(i, N) {
        F0R(j, N) {
            lo[i][j] = -1000000; hi[i][j] = 1000000;
        }
        lo[i][i] = 0; hi[i][i] = 0;
    }
    vector<pair<pi, bool> > ed;
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
        ed.pb({{X, Y}, Z});
    }

    if (!dfs(0, 0)) {
        cout << "NO" << nl; return 0;
    }

    F0R(it, N+10) {
        F0R(e, M) {
            int X = ed[e].f.f, Y = ed[e].f.s;
            bool Z = ed[e].s;
            F0R(i, N) {
                if (Z == 0) {
                    pi resX = inter({lo[i][Y], hi[i][Y]}, {lo[i][X] - 1, hi[i][X] + 1});
                    if (resX.f > resX.s) {
                        cout << "NO" << nl; return 0;
                    }
                    lo[i][Y] = resX.f; hi[i][Y] = resX.s;
                    pi resY = inter({lo[i][X], hi[i][X]}, {lo[i][Y] - 1, hi[i][Y] + 1});
                    if (resY.f > resY.s) {
                        cout << "NO" << nl; return 0 ;
                    }
                    lo[i][X] = resY.f; hi[i][X] = resY.s;
                }  else {
                    pi resX = inter({lo[i][Y], hi[i][Y]}, {lo[i][X] + 1, hi[i][X] + 1});
                    if (resX.f > resX.s) {
                        cout << "NO" << nl; return 0 ;
                    }
                    lo[i][Y] = resX.f; hi[i][Y] = resX.s;
                    pi resY = inter({lo[i][X], hi[i][X]}, {lo[i][Y] - 1, hi[i][Y] - 1});
                    if (resY.f > resY.s) {
                        cout << "NO" << nl; return 0;
                    }
                    lo[i][X] = resY.f; hi[i][X] = resY.s;

                }

            }
        }
        F0R(i, N) {
            F0R(j, N) {
                pi isec = inter({lo[i][j], hi[i][j]}, {-hi[j][i], -lo[j][i]});
                if (isec.f > isec.s) {
                    cout << "NO" << nl; return 0;
                }
                lo[i][j] = isec.f; hi[i][j] = isec.s;
                lo[j][i] = -isec.s; hi[j][i] = -isec.f;
            }
        }
    }
    int ans = 0;
    int sta = 0;
    F0R(i, N) {
        F0R(j, N) {
            if (ckmax(ans, hi[i][j])) {
                sta = i;
            }
        }
    }
    cout << "YES" << nl;
    cout << ans << nl;
    F0R(i, N) {
        cout << hi[sta][i] + 500000 << " ";
    }
    cout << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343