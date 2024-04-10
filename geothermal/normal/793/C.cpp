#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

pl larger(pl A, pl B) {
    if (A.f * B.s > A.s * B.f) {
        return A;
    } else {
        return B;
    }
}

pl getNewCoord(ll X, pl T, ll V) {
    T.f *= V;
    T.f += T.s*X;
    return T;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    ll X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;

    pl frac = {0, 1}; //time = frac + epsilon

    vector<pair<pl, pl> > data;
    F0R(i, N) {
        ll A, B, C, D; cin >> A >> B >> C >> D;
        data.pb({{A, B}, {C, D}});
    }

    F0R(i, N) {
        ll X = data[i].f.f, V = data[i].s.f;
        pl xFrac; 
        if (X1 <= X && X <= X2) {
            xFrac = {0, 1};
        } else if (X <= X1) {
            if (V <= 0) {
                cout << -1 << endl; return 0;
            }
            xFrac = {X1-X, V};
        } else {
            if (V >= 0) {
                cout << -1 << endl; return 0;
            }
            xFrac = {X - X2, -1*V};
        }

        pl yFrac;
        ll Y = data[i].f.s;
        V = data[i].s.s;
        if (Y1 <= Y && Y <= Y2) {
            yFrac = {0, 1};
        } else if (Y <= Y1) {
            if (V <= 0) {
                cout << -1 << endl; return 0;
            }
            yFrac = {Y1-Y, V};
        } else {
            if (V >= 0) {
                cout << -1 << endl; return 0;
            }
            yFrac = {Y-Y2, -1*V};
        }

        frac = larger(frac, larger(xFrac, yFrac));
        
    }

    F0R(i, N) {
        pl X = getNewCoord(data[i].f.f, frac, data[i].s.f);
        ll xVal = X.f / X.s;
        if (X.f < X1 * X.s) {
            cout << -1 << endl; return 0;
        }
        if (X.f > X2 * X.s) {
            cout << -1 << endl; return 0;
        }
        if (X.f % X.s != 0) {
            goto doneX;
        }
        if (xVal == X1 && data[i].s.f <= 0) {
            cout << -1 << endl;
            return 0;
        }
        if (xVal == X2 && data[i].s.f >= 0) {
            cout << -1 << endl;
            return 0;
        }
        doneX:
        ;
        pl Y = getNewCoord(data[i].f.s, frac, data[i].s.s);
        if (Y.f < Y1 * Y.s) {
            cout << -1 << endl; return 0;
        }
        if (Y.f > Y2 * Y.s) {
            cout << -1 << endl; return 0;
        }
        ll yVal = Y.f / Y.s;
        if (Y.f % Y.s != 0) {
            goto doneY;
        }
        if (yVal == Y1 && data[i].s.s <= 0) {
            cout << -1 << endl;
            return 0;
        }
        if (yVal == Y2 && data[i].s.s >= 0) {
            cout << -1 << endl; return 0;
        }
        doneY:
        ;
    }


    cout << setprecision(20) << ((ld) frac.f) / ((ld) frac.s) << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343