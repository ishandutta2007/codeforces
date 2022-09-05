
// read the question correctly (ll vs int)
// template by bqi343

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

    ll ans = 0;
    string S; cin >> S;
    set<int> data[2];

    int N = S.length();
    int start = 0;
    F0R(i, N) {
        int cur = S[i] - '0';
        bool good = true;
        while (good) {
            good = false;

            for (auto it = data[cur].begin(); it != data[cur].end(); it++) {
                int pos = *it;
                if (data[cur].count(2 * pos - i)) {
                    //do arithmetic sequence things
                    int lst = 2*pos-i;
                    FOR(j, start, lst+1) {
                        ans += N-i;
                        if (data[0].count(j)) {
                            data[0].erase(j);
                        } else {
                            data[1].erase(j);
                        }
                    }
                    start = lst+1;
                    good = true;
                    goto done;
                }
            }
            done:;

        }
        data[cur].insert(i);

    }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343