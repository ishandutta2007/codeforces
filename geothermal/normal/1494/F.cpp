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
const int MX = 3001; //check the limits, dummy

int N, M;
vector<vpi> graph(MX); //{ed, edNum}
vector<vpi::iterator> its(MX);
vector<bool> used(MX);

vpi eulerPath(int r) {
    F0R(i, N) its[i] = begin(graph[i]);
    F0R(i, M) used[i] = false;
    vpi ans, s{{r, -1}};
    int lst = -1;
    while (sz(s)) {
        int x = s.back().f; auto &it = its[x], en = end(graph[x]);
        while (it != en && used[it->s]) it++;

        if (it == en) {
            if (lst != -1 && lst != x) return {};
            ans.pb(s.back()); s.pop_back(); if (sz(s)) lst = s.back().f;
        } else {
            s.pb(*it);
            used[it->s] = 1;
        }
    }
    if (sz(ans) != M+1) return {};
    return ans;
}

vector<vi> init(MX);

void buildGraph(int st, int exc) {
    F0R(i, N) graph[i].clear();
    int nxt = 0;
    F0R(i, N) {
        trav(a, init[i]) {
            if (a < i) continue;
            if (a == st || i == st) continue;
            graph[i].pb({a, nxt});
            graph[a].pb({i, nxt});
            nxt++;
        }
    }
    trav(a, init[st]) {
        if ((sz(graph[a]) % 2 && exc != a) || (exc == a && sz(graph[a]) % 2 == 0)) {
            graph[st].pb({a, nxt});
            graph[a].pb({st, nxt});
            nxt++;
        }
    }
    M = nxt;
}


void solve() {

    cin >> N >> M;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        init[X].pb(Y); init[Y].pb(X);
    }

    F0R(i, N) {
        vi exc; trav(a, init[i]) exc.pb(a);
        exc.pb(-1);
        trav(a, exc) {
            buildGraph(i, a);
            vpi res = eulerPath(i);
            /*if (i == 1 && a == -1) {
                F0R(j, N) {
                    trav(b, graph[j]) {
                        cout << b.f << " ";
                    }
                    cout << nl;
                }
            }*/
            if (sz(res) == 0) continue;
            vi ans;
            set<int> unused;
            trav(a, res) ans.pb(a.f);
            ans.pb(-2);
            trav(a, init[i]) unused.ins(a);
            FOR(j, 1, sz(res)) {
                if (res[j].f == i) unused.erase(res[j-1].f);
                if (res[j-1].f == i) unused.erase(res[j].f);
            }
            trav(a, unused) {
                ans.pb(a);
                ans.pb(i);
            }

            cout << sz(ans) << nl;
            trav(a, ans) cout << a+1 << " ";
            return;
        }
    }
    cout << 0 << nl;

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343