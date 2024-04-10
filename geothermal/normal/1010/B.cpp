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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int M, N; cin >> M >> N;
    bool truth[N];
    F0R(i, N) {
        cout << 1 << endl;
        int ans; cin >> ans;
        if (ans == -2) return 0;
        if (ans == 0) return 0;
        truth[i] = ans == 1;
    }

    int lo = 1;
    int hi = M;
    int num = 0;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        cout << mid << endl;
        int ans; cin >> ans;
        if (ans == -2) return 0;
        if (!truth[num]) ans *= -1;
        num++; num = num % N;
        if (ans == 0) return 0;
        if (ans == 1) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
    int ans; cin >> ans;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343