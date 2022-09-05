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

ll bit[262145];

ll prefixSum(int index) {
    ll sum = 0;

    index++;

    while (index > 0) {
        sum += bit[index];
        index -= index & (-1 * index);
    }

    return sum;
}

ll sumBit(int i, int j) {
    if (i == 0) return prefixSum(j);
    return prefixSum(j) - prefixSum(i-1);
}

void update(int index) {
    index++;
    while (index <=  262145) {
        bit[index]++;
        index += index & (-1 * index);
    }
    /*while (index > 0) {
        bit[index]++;
        index -= index & (-1 * index);
    }*/
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    F0R(i, 262145) {
        bit[i] = 0;
    }
    int n; cin >> n;
    ll t; cin >> t;

    ll data[n];
    F0R(i, n) {
        cin >> data[i];
    }

    vector<pair<ll, int> > prefixes;


    ll sum = 0;
    prefixes.pb(mp(0, 0));
    F0R(i, n) {
        sum += data[i];
        prefixes.pb(mp(sum, i + 1));
    }

    sort(all(prefixes));

    int index[n+1];

    F0R(i, sz(prefixes)) {
        index[prefixes[i].second] = i;
    }

    ll answer = 0;
    F0R(i, n+1) {
        int curIndex = index[i];
        ll curSum = prefixes[index[i]].first;
        ll minVal = curSum - t + 1;
        auto it = upper_bound(all(prefixes), mp(minVal, -1));
        int UBindex;
        if (it == prefixes.end()) {
            UBindex = n + 1;
        } else {
            UBindex = index[(*it).s];
        }

        answer += sumBit(UBindex, n + 10);

        update(curIndex);

    }

    cout << answer << endl;
    //cout << sumBit(0, 6);


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343