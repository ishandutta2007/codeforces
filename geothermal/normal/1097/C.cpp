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

    int n; cin >> n;

    int zero;
    map<int, int> pos, neg;


    zero = 0;

    string data[n]; F0R(i, n) cin >> data[i];

    F0R(i, n) {
        int minC = 0, maxC = 0, count = 0;
        F0R(j, data[i].length()) {
            if (data[i].at(j) == '(') {
                count++;
            } else count--;
            minC = min(minC, count);
            maxC = max(maxC, count);
        }
        if (count == 0 && minC == 0) {
            zero++;
        } else if (minC == count) {

            if (!neg.count(-1 * count)) {
                neg.insert(mp(-1 * count, 1));
            } else {
                neg.find(-1 * count)->s++;
            }
        } else if (minC == 0) {

            if (!pos.count(count)) {
                pos.insert(mp(count, 1));
            } else {
                pos.find(count)->s++;
            }

        }
    }

    int ans = 0;
    ans = zero / 2;
    FOR(i, 1, 500001) {
        if (pos.count(i) && neg.count(i)) {
            ans += min(pos.find(i)->s, neg.find(i)->s);
        }
    }

    cout << ans << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343