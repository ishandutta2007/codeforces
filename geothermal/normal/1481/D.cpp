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
const int MX = 1001; //check the limits, dummy

int N;
char G[MX][MX];
int col[MX];

vi cyc;

int get(int v, char c) {
    if (col[v] == 1) {
        return v;
    } else if (col[v] == 2) return -1;
    col[v] = 1;
    F0R(i, N) {
        if (i == v || G[v][i] != c) continue;
        int X = get(i, c);
        if (X == MX) {
            return MX;
        } else if (X >= 0) {
            cyc.pb(v);
            if (v == X) X = MX;
            return X;
        }
    }
    col[v] = 2;
    return -1;
}


void solve() {

    int M; cin >> N >> M;
    F0R(i, N) F0R(j, N) cin >> G[i][j];
    cyc.clear();
    F0R(x, 2) {
        char c = 'a' + x;
        F0R(i, N) {
            col[i] = 0;
        }
        F0R(i, N) {
            if (col[i] == 0) {
                int K = get(i, c);
                if (K == MX) {
                    cout << "YES" << nl;
                    reverse(all(cyc));
                    F0R(i, M+1) {
                        cout << cyc[i%sz(cyc)] + 1 << " ";
                    }
                    cout << nl;
                    return;
                }
            }
        }
    }

    int p[N];
    F0R(i, N) {
        int cnt = 0;
        F0R(j, N) cnt += G[i][j] == 'a';
        p[cnt] = i;
    }

    if (M % 2) {
        cout << "YES" << nl;
        F0R(i, M+1) {
            cout << p[i%2]+1 << " ";
        }
        cout << nl;
    } else if (N == 2) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        F0R(i, M/2) {
            cout << p[(i%2)*2]+1 << " ";
        }
        cout << p[1]+1 << " ";
        FOR(i, M/2+1, M+1) {
            cout << p[(1-(i%2))*2]+1 << " ";
        }
        cout << nl;
    }
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