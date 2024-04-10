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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
    return (A*B)%MOD;
}

ll add(ll A, ll B) {
    return (A+B)%MOD;
}

vector<vl> matMul(vector<vl> A, vector<vl> B) {
    vector<vl> result(sz(A));
    vl blank(sz(B[0]));
    F0R(i, sz(result)) {
        result[i] = blank;
    }
    int R = sz(A), C = sz(B[0]);
    F0R(i, R) F0R(j, C) result[i][j] = 0;

    F0R(i, R) {
        F0R(j, C) {
            ll sum = 0;
            int P = sz(B);
            F0R(k, P) {
                sum += A[i][k] * B[k][j];
                sum = sum % (MOD-1);
            }
            result[i][j] = sum;
        }
    }
    return result;
}

vector<vl> matPow(vector<vl> base, ll power) {
    vector<vl> binPows[60];
    binPows[0] = base;
    FOR(i, 1, 60) {
        binPows[i] = matMul(binPows[i-1], binPows[i-1]);
    }
    bool started = false;
    vector<vl> result;
    F0R(i, 60) {
        if (power & (1LL << i)) {
            if (started) {
                result = matMul(result, binPows[i]);
            } else {
                started = true; result = binPows[i];
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<vl> transition(5);
    vl blank(5); F0R(i, 5) transition[i] = blank;
    F0R(i, 5) F0R(j, 5) transition[i][j] = 0;
    transition[0][0] = 1; transition[0][1] = 1; transition[0][2] = 1; transition[1][0] = 1; transition[2][1] = 1; transition[3][0] = 1; transition[3][3] = 1; transition[4][3] = 1; transition[4][4] = 1;

    ll N, f1, f2, f3, C; cin >> N >> f1 >> f2 >> f3 >> C;

    vl blankZero; blankZero.pb(0);
    vl blankOne; blankOne.pb(1);

    ll ans = 1;


    vector<vl> resF1;
    resF1.pb(blankZero); resF1.pb(blankZero); resF1.pb(blankOne); resF1.pb(blankZero); resF1.pb(blankZero);
    resF1 = matMul(matPow(transition, N-3), resF1);
    ans = ans * modExp(f1, resF1[0][0]);
    ans = ans % MOD;

    vector<vl> resF2;
    resF2.pb(blankZero); resF2.pb(blankOne); resF2.pb(blankZero); resF2.pb(blankZero); resF2.pb(blankZero);
    resF2 = matMul(matPow(transition, N-3), resF2);
    ans = ans * modExp(f2, resF2[0][0]);
    ans = ans % MOD;

    vector<vl> resF3;
    resF3.pb(blankOne); resF3.pb(blankZero); resF3.pb(blankZero); resF3.pb(blankZero); resF3.pb(blankZero);
    resF3 = matMul(matPow(transition, N-3), resF3);
    ans = ans * modExp(f3, resF3[0][0]);
    ans = ans % MOD;

    vector<vl> resC;
    resC.pb(blankOne); resF3.pb(blankZero); resF3.pb(blankZero); resF3.pb(blankZero); resF3.pb(blankZero);
    resC = matMul(matPow(transition, N-2), resC);
    ans = ans * modExp(C, (2*resC[4][0])% (MOD-1));
    ans = ans % MOD;

    cout << ans << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343