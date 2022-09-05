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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    

    int N, M; cin >> N >> M;
    map<ll, vl> pts;
    set<ll> used;
    map<ll, set<pl>> diags; //Y-X, ranges of X
    F0R(i, N) {
        int X, Y; cin >> X >> Y;
        pts[X].pb(Y);
    }
    pts[0].pb(0);
    pts[2000000000] = {};
    ll nxt = 0;
    trav(a, pts) {
        if (sz(a.s) == 0) break;
        //first: add points
        sort(all(a.s));
        trav(b, a.s) {
            diags[b - a.f].ins({a.f, a.f});
            used.ins(b);
        }
        while (used.lb(nxt) != used.end() && *used.lb(nxt) == nxt) nxt++;
        if (!used.count(nxt) && nxt < a.s[0]) {
            diags[nxt - a.f].ins({a.f, a.f});
            nxt++;
        }
        ll curT = a.f + 1;
        ll nxtTime = pts.ub(a.f)->f;
        while (true) {
            if (curT >= nxtTime) break;
            if (used.lb(nxt) == used.end()) {
                diags[nxt-curT].ins({curT, nxtTime - 1});
                nxt += nxtTime - curT;
                curT = nxtTime;
            } else if (*used.lb(nxt) - nxt <= nxtTime - curT) {
                diags[nxt - curT].ins({curT, curT + *used.lb(nxt) - nxt - 1});
                curT += *used.lb(nxt) - nxt;
                nxt = *used.lb(nxt) + 1;
            } else {
                diags[nxt-curT].ins({curT, nxtTime - 1});
                nxt += nxtTime - curT;
                curT = nxtTime;
            }
        }

    }
/*    trav(a, diags) {
        cout << a.f << ": ";
        trav(b, a.s) {
            cout << b.f << " to " << b.s << ", ";
        }
        cout << nl;
    }*/

    /*    F0R(i, M) {
          int X, Y; cin >> X >> Y;*/
/*    F0R(X, 10) {
        F0R(Y, 10) {*/
    F0R(i, M) { ll X, Y; cin >> X >> Y;
            if (diags.count(Y-X)) {
                auto it = diags[Y-X].lb({X+1, -1});
                if (it != diags[Y-X].begin()) {
                    it--;
                    if (it->s >= X) {
                        cout << "LOSE" << nl; goto done;
                        //cout << 0; goto done;
                    }
                }
            }
            cout << "WIN" << nl;
//            cout << 1;
            done:
            ;
/*        }
        cout << nl;*/
    }


return 0;
}

// read the question correctly (ll vs int)
// template by bqi343