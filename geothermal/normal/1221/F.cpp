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


const ll SZ = 131072*4;

pl sum[2*SZ]; 
ll lazy[2*SZ];

pl combine(pl A, pl B) {
    if (A.s == SZ) return B;
    if (B.s == SZ) return A;
    if (A.f > B.f) {
        return A;
    } 
    return B;
}

pl combineUpd(pl A, ll B) {
    return {A.f+B, A.s};
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = 0;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

pl query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return {0, SZ};
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int X[N], Y[N];
    ll C[N];
    F0R(i, N) {
        cin >> X[i] >> Y[i] >> C[i];
        if (X[i] > Y[i]) swap(X[i], Y[i]);
    }
    vector<pair<pi, int> > xsi(N); F0R(i, N) xsi[i] = {{X[i], -C[i]}, i};
    sort(all(xsi));
    vpi xs(N); F0R(i, N) xs[i] = {xsi[i].f.f, xsi[i].s};

    vector<pair<pi, int> > ysi(N); F0R(i, N) ysi[i] = {{Y[i], C[i]}, i};
    sort(all(ysi));
    vpi ys(N); F0R(i, N) ys[i] = {ysi[i].f.f, ysi[i].s};

    int yp[N]; F0R(i, N) yp[ys[i].s] = i;
    set<pi> rem;
    F0R(i, 2*SZ) {
        lazy[i] = 0;
        sum[i] = {0, SZ};
    }
    F0R(i, N) {
        sum[i+SZ] = {0, i};
    }
    FORd(i, 1, SZ) {
        pull(i);
    }
    F0R(i, N) {
        int lst = 0;
        if (i > 0) lst = ys[i-1].f;
        update(i, N, C[ys[i].s]);
        update(i, i, -ys[i].f);
        rem.ins({ys[i].f, i});
    }
    update(N, SZ-1, -1e18);
    ll ans = 0;
    int L = 2000000000, R = 2000000000;
/*    F0R(j, N) {
        cout << j << " " << query(j, j).f << nl;
    }*/
    F0R(i, N) {
//        cout << i << " " << xs[i].f << " " << rem.lb({xs[i].f, -1})->s << " " << rem.lb({xs[i].f, -1})->f << nl;
        pl cur = query(rem.lb({xs[i].f, -1})->s, N);
        if (ckmax(ans, cur.f + xs[i].f)) {
            L = xs[i].f;
            R = cur.s;
            if (R == SZ) {
                R = 2000000000;
            } else {
                R = ys[R].f;
            }
//            cout << "at " << i << " got " << ans << nl;
        }
//        cout << xs[i].s << " " << yp[xs[i].s] << " " << C[xs[i].s] << nl;
        int y = yp[xs[i].s];
        update(y, N, -C[xs[i].s]);
/*        auto nxt = ++rem.find(ys[y]);
        int pb = ys[y].f;
        int ob = 0;
        if (rem.find(ys[y]) != rem.begin()) {
            auto prev = --rem.find(ys[y]);
            ob = prev->f;
        }
        int ind = nxt->s;
        update(ind, N, ob - pb);*/
/*        cout << "After " << i << nl;
        F0R(j, N) {
            cout << j << " " << query(j, j).f << nl;
        }*/
    }

    cout << ans << nl;
    cout << L << " " << L << " " << R << " " << R << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343