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

    int t; cin >> t;
    F0R(test, t) {
        int n; cin >> n;
        int best = 0;
        F0R(p, 8) {
            vi setOne; vi setTwo;
            F0R(i, n) {
                if (i & (1 << p)) {
                    setOne.pb(i+1);
                } else setTwo.pb(i+1);
            }
            if (!setOne.empty() && !setTwo.empty()) {
                cout << setOne.size() << " " << setTwo.size() << " ";
                F0R(i, setOne.size()) {
                    cout << setOne[i] << " ";
                }
                F0R(i, setTwo.size()) {
                    cout << setTwo[i] << " ";
                }
                cout << "\n";
                cout.flush();
                int ans; cin >> ans;
                if (ans == -1) return 0;
                best = max(best, ans);
            }
        }
        cout << "-1" << " " << best << "\n";
        cout.flush();
    }
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343