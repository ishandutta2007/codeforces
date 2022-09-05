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

int minVal(vi data) {
    int ans = 1000000;
    F0R(i, sz(data)) {
        if (data[i] < ans) ans = data[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vi data(n);
    F0R(i, n) {
        cin >> data[i];
    }

    vi start(m), end(m); F0R(i, m) {
        cin >> start[i] >> end[i];
        start[i]--; end[i]--;
    }
    vpi sE, eE; F0R(i, m) {
        sE.pb(mp(start[i], i));
        eE.pb(mp(end[i], i));
    }
    sort(all(sE));
    sort(all(eE));

    F0R(i, m) {
        FOR(j, start[i], end[i] + 1) {
            data[j]--;
        }
    }
    int curMin = minVal(data);

    int curStart = 0;
    int curEnd = 0;
    int ans = -1;
    int bestI = -1;
    F0R(i, n) {
        while (curStart < m && sE.at(curStart).f == i) {
            int x = sE.at(curStart).s;
            FOR(j, start[x], end[x] + 1) {
                data[j]++;
            }
            curStart++;
            curMin = minVal(data);
        }
        ans = max(ans, data[i] - curMin);
        if (ans == data[i] - curMin) bestI = i;
        while (curEnd < m && eE.at(curEnd).f == i) {
            int x = eE.at(curEnd).s;
            FOR(j, start[x], end[x] + 1) {
                data[j]--;
            }
            curEnd++;
            curMin = minVal(data);
        }
    }

    vi list;

    F0R(i, m) {
        if (start[i] > bestI || bestI > end[i]) {
            list.pb(i);
        }
    }
    cout << ans << endl;

    cout << sz(list) << endl;
    F0R(i, sz(list)) {
        cout << (list.at(i) + 1) << " ";
    }
    cout << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343