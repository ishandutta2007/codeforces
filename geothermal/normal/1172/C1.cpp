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

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

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

ll modInv(ll base) {
    return powI(base, MOD-2);
}

ll adMod(ll A, ll B) {
    return (A+B) % MOD;
}
ll mulMod(ll A, ll B) {
    return (A*B) % MOD;
}

pl add(pl A, pl B) {
    ll top = adMod(mulMod(A.f, B.s), mulMod(A.s, B.f));
    ll bot = mulMod(A.s, B.s);
    return mp(top, bot);
}

pl mul(pl A, pl B) {
    return mp(mulMod(A.f, B.f), mulMod(A.s, B.s));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int N; cin >> N;
    int M; cin >> M;
    bool likes[N];
    F0R(i, N) {
        int cur; cin >> cur;
        likes[i] = cur ? 1 : 0;
    }
    ll init[N], sum = 0, inNeg = 0, inPos = 0;
    F0R(i, N) {
        cin >> init[i];
        sum += init[i];
        if (likes[i]) {
            inPos += init[i];
        } else {
            inNeg += init[i];
        }
    }

    pl change[M+1][6001]; //+j-3000
    F0R(i, 6001) {
        F0R(j, M+1) {


            change[j][i] = mp(0, 1);
        }
    }
    change[0][3000] = mp(1, 1);
    F0R(i, M) {
        F0R(j, 6001) {
            if (change[i][j].f == 0) continue;
            ll curSum = sum + j - 3000;
            ll countPos = i - (j - 3000); countPos = countPos / 2;
            countPos = i - countPos;
            ll curPos = inPos + countPos;
            ll curNeg = curSum - curPos;
            change[i+1][j+1] = add(change[i+1][j+1], mul(change[i][j], mp(curPos, curSum)));
            change[i+1][j-1] = add(change[i+1][j-1], mul(change[i][j], mp(curNeg, curSum)));
        }
    }

    pl ans[N]; F0R(i, N) {
        ans[i] = mp(0, 1);
    }
    pl expPos=mp(0, 1), expNeg = mp(0, 1);
    F0R(i, 6001) {
        if (i == 2999) {
            //cout << "wheeeee" << endl;
        }
        if (change[M][i].f == 0) continue;
        ll countNeg = M - (i - 3000); countNeg = countNeg / 2;
        ll countPos = M - countNeg;
        expPos = add(expPos, mul(mp(countPos, 1), change[M][i]));
        expNeg = add(expNeg, mul(mp(countNeg, 1), change[M][i]));
    }

    F0R(i, N) {
        if (likes[i]) {
            pl dif = mul(expPos, mp(init[i], inPos));
            ans[i] = add(mp(init[i], 1), dif);
        } else {
            pl dif = mul(expNeg, mp(init[i], inNeg));
            dif.f = dif.f * -1 + MOD;
            ans[i] = add(mp(init[i], 1), dif);
        }

        cout << mulMod(ans[i].f, modInv(ans[i].s)) << endl;
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343