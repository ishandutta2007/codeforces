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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll getVal(ll X, int other, bool first) {
    ll ans = 0;
    ll nxtVal = 1;
    while (X > 0) {
        if (first && other > 0) {
            nxtVal *= 10; nxtVal %= MOD;
            other--;
        }
        ll dig = X % 10; X /= 10;
        ans += dig * nxtVal; ans = ans % MOD;
        nxtVal *= 10; nxtVal %= MOD;
        if (!first && other > 0) {
            nxtVal *= 10; nxtVal %= MOD;
            other--;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    ll data[N]; F0R(i, N) cin >> data[i];

    ll countAt[12]; F0R(i, 12) countAt[i] = 0;

    F0R(i, N) {
        ll cur = data[i];
        int curCount = 0;
        while (cur > 0) {
            cur /= 10;
            curCount++;
        }
        countAt[curCount]++;
    }

    ll ans = 0;
    F0R(i, N) {
        F0R(j, 12) {
            ll val = getVal(data[i], j, true);
            val += getVal(data[i], j, false); val %= MOD;
            val = val * countAt[j]; val = val % MOD;
            ans += val; ans = ans % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343