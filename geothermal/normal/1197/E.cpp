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
    vpi data;
    F0R(i, N) {
        int A, B; cin >> A >> B; data.pb(mp(B, A));
    }
    sort(all(data));
    set<pi> locs;
    ll minVal[N+2], ways[N+2];
    F0R(i, N+2) {
        minVal[i] = 100000001000; ways[i] = 0;
    }
    minVal[0] = 0; ways[0] = 1;

    F0R(i, N) {
        pi cur = mp(data[i].f, i+1); locs.insert(cur);
    }

    FOR(i, 1, N+1) {
        if (minVal[i-1] < minVal[i]) {
            ways[i] = ways[i-1]; minVal[i] = minVal[i-1];
        } else if (minVal[i-1] == minVal[i]) {
            ways[i] += ways[i-1];
            ways[i] %= MOD;
        }

        int end = data[i-1].s;
        ll val = data[i-1].f - data[i-1].s;
        auto it = locs.lower_bound(mp(end, -1));
        //cout << i << " " << val << endl;
        if (it == locs.end()) {
            if (minVal[i] + data[i-1].f < minVal[N+1]) {
                minVal[N+1] = minVal[i] + data[i-1].f;
                ways[N+1] = 0;
            }
            if (minVal[i] + data[i-1].f == minVal[N+1]) {
                ways[N+1] += ways[i];
                ways[N+1] %= MOD;
            }
        } else {
            int nxtPos = it->s;
            if (minVal[i] + val < minVal[nxtPos]) {
                minVal[nxtPos] = minVal[i] + val;
                ways[nxtPos] = 0;
            }

            if (minVal[i] + val == minVal[nxtPos]) {
                ways[nxtPos] += ways[i];
                ways[nxtPos] %= MOD;
            }
        }
    }

    /*F0R(i, N+2) {
        cout << minVal[i] << " ";
    }
    cout << endl;


    F0R(i, N+2) {
        cout << ways[i] << " ";
    }
    cout << endl;*/
    cout << ways[N+1] << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343