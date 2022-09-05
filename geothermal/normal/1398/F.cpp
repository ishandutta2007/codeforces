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
const int MX = 1000001; //check the limits, dummy
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], rep[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, rep[i] = i;
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
        rep[x] = max(rep[x], rep[y]);

    }
};

bool ok(char C, int X) {
    return C == X + '0' || C  == '?';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    string S; cin >> S;

    int val[2][N];

    val[0][N-1] = ok(S[N-1], 0);
    val[1][N-1] = ok(S[N-1], 1);
    F0Rd(i, N-1) {
        F0R(j, 2) {
            if (ok(S[i], j)) {
                val[j][i] = val[j][i+1] + 1;
            } else {
                val[j][i] = 0;
            }
        }
    }
    vector<vi> pos(N+1);
    F0R(i, N) {
        pos[max(val[0][i], val[1][i])].pb(i);
    }

    DSU<MX> dsu;

    FOR(i, 1, N+1) {
/*        if (i == 6) {
            F0R(j, 7) {
                cout << dsu.rep[dsu.get(j)] << " ";
            }
            cout << nl;
            return 0;
        }*/
        int p = dsu.rep[dsu.get(0)];
        int ans = 0;
        while (p + i <= N) {
            ans++;
            p = dsu.rep[dsu.get(p+i)];
        }
        cout << ans << " ";
        trav(a, pos[i]) {
//            cout << a << "FOUND" << nl;
            dsu.unify(a, a+1);
        }
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343