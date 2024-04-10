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
 
const int D = 40; //length of masks

ll basis[D]; // basis[i] keeps the mask of the vector whose f value is i

int bs = 0; //basis size

vector<pair<pl, bool> > ops;
set<ll> board;

void insertVector(ll mask) {
	for (int i = 0; i < D; i++) {
		if ((mask & (1ll << i)) == 0) continue; 

		if (!basis[i]) { 
			basis[i] = mask;
			++bs;
			return;
		}

		if (!board.count(mask ^ basis[i])) {
            ops.pb({{mask, basis[i]}, 0});
        }
        mask ^= basis[i]; 
	}
}

bool inSpan(ll mask) {
    F0R(i, D) {
        if (mask & (1ll << i)) {
            mask ^= basis[i];
        }
    }
    return mask == 0;
}

void buildBasis(vl& masks) {
    F0R(i, D) basis[i] = 0;
    bs = 0;
    trav(a, masks) insertVector(a);
    masks.clear(); F0R(i, D) if (basis[i] != 0) masks.pb(basis[i]);
}

ll get(vl& masks) {
    ll val;
    val = 0;
    trav(a, masks) {
        if (uid(0, 1)) {
            val ^= a;
        }
    }
    return val;
            
}

void gen(ll mask) {
    ll cur = mask;
    ll val = 0;
    F0R(i, D) {
        if (cur & (1ll << i)) {
            cur ^= basis[i];
            if (!board.count(val ^ basis[i])) ops.pb({{val, basis[i]}, 0});
            val ^= basis[i];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll X; cin >> X;
    
    board.ins(X);
    ops.pb({{X, X}, 0});
    board.ins(0);
    vl cb = {X};
    buildBasis(cb);
    int cnt = 0;
    while (!inSpan(1)) {
//        cout << A << " " << B << " trying" << nl;
        ll A = get(cb);
        ll B = get(cb);
        if (A+B >= 1ll << D) continue;
//        cout << "Trying " << A << " " << B << nl;
        if (!inSpan(A+B)) {
//            cout << "adding " << A << " " << B << nl;
            cnt++;
            gen(A); gen(B);
            ops.pb({{A, B}, 1});
            cb.pb(A+B);
            int bef = sz(cb);
            buildBasis(cb);
            assert(bef == sz(cb));
//            cout << "Added " << A+B << " to span" << nl;
//            cout << "New basis: ";
//            trav(a, cb) cout << a << " ";
//            cout << nl;
        }
//        if (sz(cb) > 5) return 0;
//        assert(cnt <= 60);
    }

    gen(1);
    cout << sz(ops) << nl;
    trav(a, ops) {
        cout << a.f.f << " " << (a.s?"+":"^") << " " << a.f.s << nl;
    }
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343