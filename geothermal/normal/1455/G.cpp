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
const int MX = 200011; //check the limits, dummy

int T[MX];
int val[MX];
ll cost[MX];
int p = 0;
int N, S;
map<int, ll> res[MX];
int nc = 0;
priority_queue<pl, vpl, greater<pl> > q[MX];
pl go(int ini) {
    int lev = nc; nc++;
    res[lev][ini] = 0;
    ll con = 0;
    q[lev].push({0, ini});
    while (true) {
        if (p >= N || T[p] == 2) {
            p++;
            return {lev, con};
        }
        if (T[p]) {
            ll cost = 1e18; if (res[lev].count(val[p])) cost = res[lev][val[p]];
            res[lev].erase(val[p]);
            int nv = val[p]; p++;
            pl ans = go(nv);
            int nlev = ans.f;
            ll ncon = ans.s;
            if (cost > 1e17) continue;
            if (sz(res[lev]) > sz(res[nlev])) {
                trav(a, res[nlev]) {
                    a.s += cost + ncon;
                    q[lev].push({a.s, a.f});
                    if (!res[lev].count(a.f)) {
                        res[lev].ins(a);
                    } else {
                        ckmin(res[lev][a.f], a.s);
                    }
                }
            } else {
/*                trav(a, res[lev]) {
                    cout << "OLD " << a.f << " " << a.s << nl;
                }
                cout << con << nl;
                trav(a, res[nlev]) {
                    cout << "NEW " << a.f << " " << a.s << nl;
                }
                cout << ncon << nl;*/
                trav(a, res[lev]) {
                    a.s -= ncon + cost;
                    q[nlev].push({a.s, a.f});
                    if (!res[nlev].count(a.f)) {
                        res[nlev].ins(a);
                    } else {
                        ckmin(res[nlev][a.f], a.s);
                    }
                }
                lev = nlev;
                con += ncon + cost;
//                cout << con << endl;
            }
        } else {
            while (res[lev][q[lev].top().s] != q[lev].top().f) q[lev].pop();
            con += cost[p];
            if (val[p] != S) {
                res[lev][val[p]] = q[lev].top().f - cost[p];
                q[lev].push({res[lev][val[p]], val[p]});
            }
            p++;
        }
    }

    return {lev, con};
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> S;
    F0R(i, N) {
        string S; cin >> S;
        if (S == "set") {
            T[i] = 0; cin >> val[i] >> cost[i];
        } else if (S == "if") {
            T[i] =1 ; cin >> val[i];
        } else {
            T[i] = 2;
        }
    }
    pl nums = go(0);
    ll ans = 1e15;
    trav(a, res[nums.f]) {
        ckmin(ans, a.s + nums.s);
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343