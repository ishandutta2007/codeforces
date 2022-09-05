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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    bool defBlack;
    cout << 1 << " 500000000" << endl;

    string S; cin >> S;
    if (N == 1) {
        cout << "0 0 1 0" << endl;
        return 0;
    }
    bool data[N];

    data[0] = S == "black";

    cout << 1000000000 - 29 << " 0" << endl;
    cin >> S;
    data[1] = S == "black";

    int lo, hi;
    if (data[0] == data[1]) {
        lo = 500000001;
        hi = 1000000000;
    } else {
        lo = 1;
        hi = 499999999;
    }
    FOR(i, 2, N) {
        int mid = (lo+hi)/2;
        cout << 1000000000 - 30 + i << " " << mid << endl;
        cin >> S;
        data[i] = S == "black";

        if (data[0] != data[1]) {
            if (data[i] == data[0]) {
                hi = mid - 1;
            } else lo = mid + 1;
        } else {
            if (data[i] == data[0]) {
                lo = mid+1;
            } else hi = mid-1;
        }
    }

    int mid = (lo+hi)/2;
    cout << 0 << " " << 500000000 << " " << 1000000000 << " " << mid << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE