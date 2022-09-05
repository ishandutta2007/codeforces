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
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 300001; //check the limits, dummy

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

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

struct Frac {
    ll A, B;

    Frac(ll X, ll Y) {
        A = X; B = Y;
    }

    ll ans() {
        return dvd(A, B);
    }

    Frac operator+(const Frac& F) {
        ll num = add(mul(A, F.B), mul(B, F.A));
        ll den = mul(B, F.B);
        Frac res(num, den);
        return res;
    }

    Frac operator-(const Frac& F) {
        ll num = sub(mul(A, F.B), mul(B, F.A));
        ll den = mul(B, F.B);
        Frac res(num, den);
        return res;
    }

    Frac operator*(const Frac& F) {
        ll num = mul(A, F.A);
        ll den = mul(B, F.B);
        Frac res(num, den);
        return res;
    }

    Frac operator/(const Frac& F) {
        ll num = mul(A, F.B);
        ll den = mul(B, F.A);
        Frac res(num, den);
        return res;
    }

    Frac& operator+=(const Frac& F) { return *this = (*this) + F; }
    Frac& operator-=(const Frac& F) { return *this = (*this) - F; }
    Frac& operator*=(const Frac& F) { return *this = (*this) * F; }
    Frac& operator/=(const Frac& F) { return *this = (*this) / F; }
};

ll* facs = new ll[MX];

ll choose(ll a, ll b) {
    ll cur = facs[a];
    cur = mul(cur, inv(facs[b]));
    cur = mul(cur, inv(facs[a-b]));
    //cout << "Choose " << a << " " << b << " " << cur << endl;
    return cur;
}

void initFacs() {
    facs[0] = 1;
    FOR(i, 1, MX) {
        facs[i] = (facs[i-1] * i) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    initFacs();

    Frac half(1, 2);

    int N; ll T; cin >> N >> T;

    ll data[N]; F0R(i, N) cin >> data[i];
    Frac ans(0, 1);

    ll sum = 0;
    ll curWays = 1;
    ll curOpts = 0;
    FOR(i, 1, N+1) {
        sum += data[i-1];
        curWays *= 2; curWays %= MOD; curWays = sub(curWays, choose(i-1, curOpts));
        ll maxBad = T - sum;
        maxBad = min(maxBad, (ll) i);
        if (maxBad < 0) {
            break;
        }
        //cout << i << " " << curWays << endl;
        FORd(j, maxBad, curOpts) {
            curWays = sub(curWays, choose(i, curOpts));
            curOpts--;
        }
        FOR(j, curOpts, maxBad) {
            curWays = add(curWays, choose(i, curOpts+1));
            curOpts++;
        }

        //cout << i << " " << curWays << " " << curOpts << endl;

        if (maxBad > i+1) {
            ans += Frac(1, 1);
        } else {
            ans += Frac(curWays, modExp(2, i));
        }
    }

    cout << ans.ans() << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343