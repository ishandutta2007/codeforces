// read the question correctly (ll vs int)
// template by bqi343

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

ll mul(ll A, ll B) {
    ll ans = A * B;
    return ans % MOD;
}

ll compAns(int N, vi factors) {
    vi counts;
    int left = N;
    int curDig = 0;
    bool used = false;
    ll ans = 1;
    int added = 0;
    F0R(i, sz(factors)) {
        int nxt = left / factors[i];
        curDig++;
        counts.pb(left - nxt);
        left = nxt;
    }

    F0R(dig, sz(counts)) {
        int cur = counts[dig];
        ans = mul(ans, cur);
        cur--;
        F0R(i, cur) {
            ans = mul(ans, added + 1);
            added++;
        }
        added++;
    }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    ll total = 0;
    vi factors;
    int mulRes = 1;
    while (mulRes * 2 <= N) {
        factors.pb(2);
        mulRes *= 2;
    }

    total += compAns(N, factors);
    total = total % MOD;

    if (mulRes * 3 / 2 <= N) {
        factors.pop_back();
        factors.push_back(3);
        do {
            total += compAns(N, factors);
            total = total % MOD;
        } while (next_permutation(all(factors)));
    }



    cout << total << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343