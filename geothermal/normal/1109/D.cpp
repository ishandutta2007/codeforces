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
const int MX = 2000010; //check the limits, dummy

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

ll modInv(ll base) {
    return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
    return (A*B)%MOD;
}

ll add(ll A, ll B) {
    return (A+B)%MOD;
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

ll* facs = new ll[MX];
ll* invFacs = new ll[MX];

ll choose(ll a, ll b) {
    ll cur = facs[a];
    cur = mul(cur, invFacs[b]);
    cur = mul(cur, invFacs[a-b]);
    return cur;
}

void initFacs() {
    facs[0] = 1;
    invFacs[0] = 1;
    FOR(i, 1, MX) {
        facs[i] = (facs[i-1] * i) % MOD;
        invFacs[i] = modInv(facs[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    initFacs();

    int N, M; cin >> N >> M;

    ll* powsM = new ll[N];
    ll* powsN = new ll[N];
    powsM[0] = 1; powsN[0] = 1;
    FOR(i, 1, N) {
        powsM[i] = mul(powsM[i-1], M);
        powsN[i] = mul(powsN[i-1], N);
    }

    ll ans = 0;
    FOR(K, 2, min(N, M+1)+1) {
        //split M into K-1 bundles, each receiving at least one.  M-K+1 into K-1, M-1 choose K-2
        //cout << "Dealing with " << K << endl;
        ll cur = choose(M-1, K-2);
        //cout << cur << endl;
        cur = cur * powsM[N-K]; //assign weights to other edges
        cur = cur % MOD;
        //cout << cur << endl;

        cur = mul(cur, facs[N-2]);
        cur = mul(cur, invFacs[N-K]);

        if (N != K) {
            cur = mul(cur, K);
            cur = mul(cur, powsN[N-K-1]);
        }

        ans += cur;
        ans = ans % MOD;
        //cout << "final" << " " << cur << endl;
    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343