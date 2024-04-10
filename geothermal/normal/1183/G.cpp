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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int Q; cin >> Q;
    F0R(testCase, Q) {
        int N; cin >> N;
        vi counts(N+1);
        F0R(i, N+1) counts[i] = 0;
        vpi typeData(N+1);
        F0R(i, N+1) {
            typeData[i] = mp(0, 0);
        }
        F0R(i, N) {
            int cur; cin >> cur; counts[cur]++;
            int good; cin >> good;
            typeData[cur].f++;
            if (good == 1) typeData[cur].s++;
        }
        sort(all(counts));
        int ans = 0;
        set<int> available;
        FOR(i, 1, N+1) {
            available.insert(-1 * i);
        }
        set<int> used;
        F0R(i, N+1) {
            auto it = available.lower_bound(-1 * counts[i]);
            if (it == available.end()) continue;
            ans -= *it;
            used.insert(-1 * *it);
            available.erase(it);
        }
        cout << ans << " ";
        int ans2 = 0;

        priority_queue<int> toBeUsed;
        sort(all(typeData));
        int nxtVal = N;
        auto it = used.end();
        while (it != used.begin()) {
            it--;
            int val = *it;
            while (nxtVal > 0 && typeData[nxtVal].f >= val) {
                toBeUsed.push(typeData[nxtVal].s);
                nxtVal--;
            }
            ans2 += min(toBeUsed.top(), val);
            toBeUsed.pop();
        }

        cout << ans2 << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343