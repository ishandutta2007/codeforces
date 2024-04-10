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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    string S; cin >> S;
    vector<char> processed;
    F0R(i, N) {
        int cur = sz(processed);
        if (cur < 2 || processed[cur-1] != S[i] || processed[cur-2] != S[i]) {
            processed.pb(S[i]);
        }
    }
    vector<char> result;
    F0R(i, sz(processed)) {
        int cur = sz(result);
        if (cur % 2 != 1 || result[cur-1] != processed[i]) {
            result.pb(processed[i]);
        }
    }

    int ansSum = result.size();
    if (result.size() % 2 == 1) {
        ansSum--;
    }
    cout << (N - ansSum) << endl;
    F0R(i, ansSum) {
        cout << result[i];
    }
    cout << endl;



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343