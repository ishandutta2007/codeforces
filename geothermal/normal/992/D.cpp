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
const int MX = 300001; //check the limits, dummy

bool overflow(ll a, ll b) {
    /*if (a == 0 || b == 0) return false;
    ll result = a*b;
    if (a == result / b && b == result / a) {
        return false;
    } else return true;*/
    ld A = (ld) a; ld B = (ld) b;
    ll yuge = 4000000000000000000LL;
    ld YUGE = (ld) yuge;
    if (log2(A) + log2(B) < log2(YUGE)) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, k; cin >> N >> k;
    ll data[N]; F0R(i, N) cin >> data[i];
    int val = 0;
    vl procOld;
    F0R(i, N) {
        if (data[i] == 1) {
            if (val > 0) {
                procOld.pb(val); val = 0;
            }
            val--;
        } else {
            procOld.pb(val);
            val = data[i];
        }
    }
    procOld.pb(val);
    if (val > 0) procOld.pb(0);

    vl proc;
    proc.pb(procOld[0]);
    FOR(i, 1, sz(procOld)) {
        if (procOld[i] > 0 && proc[sz(proc)-1] > 0) {
            proc.pb(0);
        }
        proc.pb(procOld[i]);
    }

    ll ans = 0;

    for (int i = 1; i < sz(proc); i += 2) {
        ll prod = 1;
        ll sum = 0;
        for (int j = 0; j <= 100 && i+j < sz(proc); j += 2) {
            if (overflow(prod, proc[i+j])) {
                break;
            }
            prod = prod * proc[i+j];
            sum += proc[i+j]; if (j > 0) sum += -1 * proc[i+j-1];
            if (prod % k != 0) continue;
            ll goalSum = prod / k;
            if (sum > goalSum) continue;
            ll availableOnes = -1 * (proc[i-1] + proc[i+j+1]);
            if (sum + availableOnes < goalSum) continue;
            ll needOnes = goalSum - sum;
            ll lo = min(-1*proc[i-1], -1*proc[i+j+1]);
            ll hi = max(-1*proc[i-1], -1*proc[i+j+1]);
            ll maxLo = lo; if (maxLo > needOnes) maxLo = needOnes;
            ll minLo = 0; if (hi < needOnes) minLo = needOnes - hi;

            ans += maxLo - minLo + 1;
        }
    }

    if (k == 1) {
        for (int i = 0; i < sz(proc); i+= 2) {
            ll val = -1 * proc[i];
            ans += val;
        }
    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343