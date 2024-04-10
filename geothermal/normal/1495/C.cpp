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
const int MX = 502; //check the limits, dummy

template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};
void solve() {

    int N, M; cin >> N >> M;
    string A[N]; F0R(i, N) cin >> A[i];
    string ans[N];
    F0R(i, N) {
        if (i % 3 == 0) {
            F0R(j, M) ans[i] += 'X';
        } else {
            ans[i] = A[i];
        }
    }
    for (int i = 0; i < N; i+=3) {
        if (i+2 >= N) continue;
        bool found = false;
        F0R(j, M) {
            if (ans[i+1][j] == 'X' || ans[i+2][j] == 'X') {
                if (!found || i+3 == N) {
                    ans[i+1][j] = 'X'; ans[i+2][j] = 'X'; found = true;
                }
            }
        }
        if (!found) {
            ans[i+1][0] = 'X'; ans[i+2][0] = 'X';
        }
    }

    /*FOR(i, 1, N) {
        DSU<MX> dsu;
        ans[i] = A[i];
        F0R(j, M) {
            if (A[i][j] == 'X' && ans[i-1][j] == 'X') {
                dsu.unify(j, MX-1);
            }
        }
        F0R(j, M) {
            if (ans[i][j] == 'X' && dsu.get(j) != dsu.get(MX-1)) {
                bool found = false;
                F0Rd(k, j) {
                    ans[i][k] = 'X';
                    dsu.unify(k, k+1);
                    if (ans[i-1][k] == 'X') {
                        found = true; break;
                    }
                }
                if (!found) {
                    FOR(k, j+1, M) {
                        ans[i][k] = 'X';
                        dsu.unify(k, k-1);
                        if (ans[i-1][k] == 'X') {
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        int cnt = 0;
        F0R(j, M) if (ans[i][j] == 'X') cnt++;
        if (cnt == 0) {
            F0R(j, M) {
                if (ans[i-1][j] == 'X') {
                    ans[i][j] = 'X'; break;
                }
            }
        }
    }*/
    /*for (int i = 1; i < N; i += 2) {
        vi pos;
        F0R(j, M) {
            if (A[i][j] == 'X') pos.pb(j);
        }
        ans[i][j] = 'X'; break;
   ans[i][j] = 'X'; break;
   ans[i][j] = 'X'; break;
   ans[i][j] = 'X'; break;
     ans[i][j] = 'X'; break;
        bool found = false;
        trav(a, pos) {
            ans[i][a] = 'X';
            if (ans[i-1][a] == 'X') found = true;
        }

        if (i +1 < N) {
            F0R(j, sz(pos) - 1) {
                ans[i+1][pos[j]+1] = '.';
            }
            DSU<MX> dsu;
            F0R(j, M) {
                if (ans[i+1][j] == 'X' && ans[i][j] == 'X' && ans[i-1][j] == 'X') {
                    dsu.unify(j, MX-1);
                }
            }
            F0R(j, M-1) {
                if (ans[i+1][j] == 'X' && ans[i+1][j+1] == 'X') {
                    dsu.unify(j, j+1);
                }
            }
            F0R(j, M) {
                if (ans[i+1][j] == 'X' && dsu.get(j) != dsu.get(MX-1) && ans[i-1][j] == 'X') {
                    dsu.unify(j, MX-1);
                    ans[i][j] = 'X';
                }
            }
            F0R(j, M-1) {
                if (ans[i][j] == 'X' && ans[i][j+1] == 'X' && ans[i+1][j] == 'X' && ans[i+1][j+1] == 'X') {
                    ans[i+1][j+1] = '.';
                }
            }
        }
    }*/
    F0R(i, N) cout << ans[i] << nl;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343