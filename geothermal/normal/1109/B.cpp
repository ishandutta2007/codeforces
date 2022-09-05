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

    char C = S[0];
    bool bad = true;
    FOR(i, 1, sz(S) / 2) {
        if (C != S[i]) {
            bad = false;
        }
    }


    if (bad) {
        cout << "Impossible" << endl;
        return 0;
    }

    bool found = false;

    FOR(cur, 1, sz(S)) {
        //cur maps to 0
        /*found = true;
        F0R(i, sz(S)) {
            int X = i+cur; X = X % sz(S);
            int Y = sz(S) - i - 1 + cur; Y = Y % sz(S);
            if (S[X] != S[Y]) found = false;
        }

        if (found) break;*/
        string test;
        FOR(i, cur, sz(S)) test += S[i];
        F0R(i, cur) test += S[i];
        found = true;
        bool foundDiff = false;
        F0R(i, sz(S)) {
            if (test[i] != test[sz(S) - i - 1]) found = false;
            if (test[i] != S[i]) foundDiff = true;
        }
        found = found && foundDiff;
        if (found) break;
    }

    if (found) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343