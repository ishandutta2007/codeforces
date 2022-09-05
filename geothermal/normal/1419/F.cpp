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
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], cc;

    DSU(int N) {
        F0R(i, SZ) parent[i] = i, size[i] = 1;
        cc = N;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        cc--;
        if (size[x] < size[y]) swap(x, y);
        size[x]+=size[y];
        parent[y] = x;

    }
};
int N;
ll X[MX], Y[MX];
map<ll, vpl> Xs, Ys;
vector<array<ll, 5> > H, V;

bool check(ll T) {
    DSU<MX> dsu(N);

    F0R(i, N) {
        FOR(j, i+1, N) {
            if (X[i] != X[j] && Y[i] != Y[j]) continue;
            ll dist = abs(X[i] - X[j] + Y[i] - Y[j]);
//            cout << "Testing " << i << " " << j << " " << dist << nl;
            if (dist <= T) {
//                cout << "Connecting " << i << " " << j << nl;
                dsu.unify(i, j);
            }
        }
    }
//    cout << dsu.cc << " " << T << nl;
    if (dsu.cc == 1) {
        return true;
    } 
    if (dsu.cc == 2) {
        F0R(i, N) {
            FOR(j, i+1, N) {
                if (X[i] != X[j] && Y[i] != Y[j]) continue;
                ll dist = abs(X[i] - X[j] + Y[i] - Y[j]);
                if (dist <= 2*T && dsu.get(i) != dsu.get(j)) return true;
            }
        }
    }
    Xs.clear(); Ys.clear();
    F0R(i, N) {
        Xs[X[i]].pb({Y[i], i});
        Ys[Y[i]].pb({X[i], i});
    }
    H.clear(); V.clear();
    trav(a, Xs) {
        sort(all(a.s));
        F0R(i, sz(a.s) - 1) {
            if (a.s[i+1].f - a.s[i].f <= 2*T) H.pb({a.f, max(a.s[i].f, a.s[i+1].f - T), min(a.s[i].f+T, a.s[i+1].f), a.s[i].s, a.s[i+1].s});
        }
        F0R(i, sz(a.s)) {
            H.pb({a.f, a.s[i].f-T, a.s[i].f+T, a.s[i].s, a.s[i].s});
        }
    }
    trav(a, Ys) {
        sort(all(a.s));
        F0R(i, sz(a.s) - 1) {
            if (a.s[i+1].f - a.s[i].f <= 2*T) V.pb({a.f, max(a.s[i].f, a.s[i+1].f - T), min(a.s[i].f+T, a.s[i+1].f), a.s[i].s, a.s[i+1].s});
        }
        F0R(i, sz(a.s)) {
            V.pb({a.f, a.s[i].f-T, a.s[i].f+T, a.s[i].s, a.s[i].s});
        }
    }
    map<int, int> m;
    F0R(i, N) {
        if (!m.count(dsu.get(i))) m.ins({dsu.get(i), sz(m)});
    }
    int val[N]; F0R(i, N) val[i] = m[dsu.get(i)];
    bool found[dsu.cc]; 
    trav(a, H) {
        trav(b, V) {
            if (b[1] <= a[0] && a[0] <= b[2] && a[1] <= b[0] && b[0] <= a[2]) {
                F0R(i, dsu.cc) found[i] = false;
                FOR(i, 3, 5) {
                    found[val[a[i]]] = true;
                    found[val[b[i]]] = true;
                }
                F0R(i, dsu.cc) if (!found[i]) goto done;
                return true;
                done:
                ;
            }
        }
    }
    return false;


}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N; F0R(i, N) cin >> X[i] >> Y[i];

    ll lo = 0, hi = 1e11;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if (lo < 1e10) {
        cout << lo << nl;
    } else {
        cout << -1 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343