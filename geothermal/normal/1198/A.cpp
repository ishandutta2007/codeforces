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

    int N; ll I; cin >> N >> I;
    I = 8*I/N;
    map<ll, int> values;
    F0R(i, N) {
        int X; cin >> X;
        if (!values.count(X)) values.insert(mp(X, 0));
        values[X]++;
    }

    if (I > 30) {
        cout << 0 << endl; return 0;
    }
    //cout << I << endl;
    int best = 0;
    vpl data;
    for(auto it = values.begin(); it != values.end(); it++) {
        data.pb(*it);
    }
    int start = 0;
    int prefix[sz(data)+1]; prefix[0] = 0;
    F0R(i, sz(data)) {
        start += data[i].s;
        prefix[i+1] = start;

        best = max(best, prefix[i+1] - prefix[max(0LL, (i+1 - (1LL << I)))]);
        //cout << best << " " << i << " " << start << endl;
    }

    cout << N-best << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE