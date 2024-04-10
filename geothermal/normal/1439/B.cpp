#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {

    int N, M, K; cin >> N >> M >> K;

    gp_hash_table<int, int, custom_hash> ed[N];
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        ed[X].ins({Y, 0});
        ed[Y].ins({X, 0});
    }

    priority_queue<pi, vpi, greater<pi> > q;
    F0R(i, N) q.push({sz(ed[i]), i});
    bool cliq = false;
    while (!q.empty()) {
        int X = q.top().s;
        if (q.top().f != sz(ed[X])) {
            q.pop(); continue;
        }
        if (sz(ed[X]) >= K) {
            cliq = true; break;
        } else if (sz(ed[X]) >= K-1) {
            vi cur; trav(a, ed[X]) cur.pb(a.f);
            F0R(i, K-1) {
                FOR(j, i+1, K-1) {
                    if (ed[cur[i]].find(cur[j]) == ed[cur[i]].end()) goto done;
                }
            }
            cout << 2 << nl;
            cout << X+1 << " ";
            trav(a, cur) {
                cout << a+1 << " ";
            }
            cout << nl; return;
            done:
            ;
        }
        q.pop();
        trav(a, ed[X]) {
            ed[a.f].erase(X);
            q.push({sz(ed[a.f]), a.f});
        }
    }

    if (cliq) {
        vi vals;
        while (!q.empty()) {
            if (q.top().f == sz(ed[q.top().s])) {
                vals.pb(q.top().s);
            }
            q.pop();
        }
        cout << 1 << " " << sz(vals) << nl;
        trav(a, vals) {
            cout << a+1 << " ";
        }
        cout << nl;
        return;
    }
    cout << -1 << nl;

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