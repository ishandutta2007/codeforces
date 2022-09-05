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

    int n; cin >> n; string str; cin >> str;
    vi data; F0R(i, n) {
        if (str[i] == 'R') {
            data.pb(0);
        } else if (str[i] == 'G') {
            data.pb(1);
        } else data.pb(2);
    }

    int best = n + 1;
    int bestVals[3];
    F0R(caseNum, 27) {
        int curCase[3]; curCase[0] = caseNum % 3;
        int cx = caseNum / 3;
        curCase[1] = cx % 3;
        curCase[2] = cx / 3;
        if (curCase[0] == curCase[1] || curCase[0] == curCase[2] || curCase[1] == curCase[2]) continue;
        int ans = 0;
        F0R(i, n) {
            if (data[i] != curCase[i % 3]) {
                ans++;
            }
        }
        if (ans < best) {
            best = ans;
            bestVals[0] = curCase[0];
            bestVals[1] = curCase[1];
            bestVals[2] = curCase[2];
        }
    }

    cout << best << endl;
    vi endResult(n); F0R(i, n) {
        if (bestVals[i % 3] == 0) {
            cout << 'R';
        } else if (bestVals[i % 3] == 1) {
            cout << 'G';
        } else cout << 'B';
    }

    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343