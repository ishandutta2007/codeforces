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

    string S; cin >> S;

    vector<char> start;
    int N = sz(S);
    int lo, hi;
    if (N % 4 == 0) {
        int loVal = N/2 - 2;
        if (S[loVal] == S[loVal + 2]) {
            lo = loVal; hi = loVal + 2;
        } else if (S[loVal] == S[loVal + 3]) {
            lo = loVal; hi = loVal + 3;
        } else if (S[loVal + 1] == S[loVal + 3]) {
            lo = loVal + 1; hi = loVal + 3;
        }
        start.pb(S[lo]); start.pb(S[hi]);
    } else {
        lo = N/2; hi = N/2;
        start.pb(S[N/2]);
    }

    vector<char> pal;

    while (sz(pal) * 2 + sz(start) < N/2) {
        if (S[lo-1] == S[hi+1]) {
            lo = lo-1; hi = hi+1;
        } else if (S[lo-1] == S[hi+2]) {
            lo = lo-1; hi = hi+2;
        } else if (S[lo-2] == S[hi+1]) {
            lo -= 2; hi += 1;
        } else if (S[lo-2] == S[hi+2]) {
            lo -= 2; hi += 2;
        }
        pal.pb(S[lo]);
    }

    reverse(all(pal));
    F0R(i, sz(pal)) cout << pal[i];
    F0R(i, sz(start)) cout << start[i];
    reverse(all(pal));
    F0R(i, sz(pal)) cout << pal[i];

    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343