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
const int MX = 200001; //check the limits, dummy

int vis[MX]; 
bool l1[MX], l2[MX];
vector<vi> G(MX), T(MX);
bool check(int v, int r) {
    bool ans = false;
    vis[v] = 1;
    F0R(i, sz(G[v])) {
        int nxt = G[v][i];
        if (vis[nxt] == 1) return true;
        if (vis[nxt] == 2) continue;
        ans = ans || check(nxt, r);
    }
	vis[v] = 2;
    return ans;
}

void dg(int v) {
    l1[v] = true;
    F0R(i, sz(G[v])) {
        int nxt = G[v][i];
        if (l1[nxt]) continue;
        dg(nxt);
    }
}

void dt(int v) {
    l2[v] = true;
    F0R(i, sz(T[v])) {
        int nxt = T[v][i];
        if (l2[nxt]) continue;
        dt(nxt);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        G[X].pb(Y);
        T[Y].pb(X);
    }
    F0R(i, N) vis[i] = 0;
    F0R(i, N) {
        if (vis[i] == 0) {
            if (check(i, i)) {
                cout << -1 << nl; return 0;
            }
        }
    }
    int cnt = 0;
    string ans;
    F0R(i, N) {
        l1[i] = false; l2[i] = false;
    }
    F0R(i, N) {
        if (!l1[i] && !l2[i]) {
            ans += 'A'; cnt++;
        } else {
            ans += 'E';
        }
        dg(i); dt(i);
    }
    cout << cnt << nl;
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343