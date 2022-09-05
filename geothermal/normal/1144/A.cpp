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

    int N;
    cin >> N;
    F0R(test, N) {
        string str; cin >> str;
        if (str.length() > 26) {
            cout << "No" << endl; continue;
        }
        int count[26], lo, hi; lo = 100000000; hi = 0;
        F0R(i, 26) count[i] = 0;
        F0R(i, str.length()) {
            count[str[i] - 'a']++;
            lo = min(lo, (int) str[i]);
            hi = max(hi, (int) str[i]);

        }
        F0R(i, 26) {
            if (count[i] > 1) {
                cout << "No" << endl; goto done;
            }
        }
        if (hi - lo + 1 != str.length()) {
            cout << "No" << endl; goto done;
        }

        cout << "Yes" << endl;
        done:;
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343