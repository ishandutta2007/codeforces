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
const int MX = 100001;

pl mulFrac(pl a, pl b) {
    return mp((a.f * b.f) % MOD, (a.s * b.s) % MOD);
}

pl addFrac(pl a, pl b) {
    return mp((a.f * b.s + b.f * a.s) % MOD, (a.s * b.s) % MOD);
}

ll powI(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = powI(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<pair<ll, int> > facs;

    ll n; int k; cin >> n >> k;

    FOR(i, 2, 50000000) {
        int count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count != 0) facs.push_back(mp(i, count));
    }
    if (n != 1) {
        facs.pb(mp(n % MOD, 1));
    }

    pl ans = mp(1, 1);
    F0R(i, sz(facs)) {
        pair<ll, int> cur = facs.at(i);
        ll prime = cur.f;
        int count = cur.s;

        ll num[count+1][k+1];
        ll den[count+1][k+1];
        F0R(i, count+1) {
            F0R(j, k+1) {
                num[i][j] = 0;
                den[i][j] = 1;
            }

        }
        num[count][0] = 1;
        F0R(x, k) {
            F0R(y, count+1) {
                pl newPair = mulFrac(mp(num[y][x], den[y][x]), mp(1LL, y+1));
                F0R(z, y+1) {
                    pl old = mp(num[z][x+1], den[z][x+1]);
                    pl newPair2 = addFrac(newPair, old);
                    num[z][x+1] = newPair2.f;
                    den[z][x+1] = newPair2.s;
                }
            }
        }

        ll curProd = 1;
        pl curAns = mp(0, 1);
        F0R(i, count+1) {
            ll curNum = num[i][k] * curProd;
            curNum = curNum % MOD;
            ll curDen = den[i][k];
            pl addition = addFrac(mp(curNum, curDen), curAns);
            curAns.f = addition.f;
            curAns.s = addition.s;
            curProd = curProd * prime; curProd = curProd % MOD;
        }

        pl mult = mulFrac(ans, curAns);
        ans.f = mult.f; ans.s = mult.s;

    }

    ll newS = powI(ans.s, MOD - 2);

    ll answer = ans.f * newS; answer = answer % MOD;
    cout << answer << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343