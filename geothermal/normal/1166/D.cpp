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

    int Q;
    cin >> Q;
    F0R(query, Q) {
        ll A, B, M; cin >> A >> B >> M;
        vl data;
        data.pb(A); ll nxt = A+1;
        M--;
        while (nxt <= B) {
            data.pb(nxt);
            nxt += nxt;
        }

        ll cumInc = 0;
        ll needInc = B - data[sz(data) - 1];


        ll powsTwo[56]; powsTwo[0] = 1; powsTwo[1] = 1; FOR(i, 2, 55) powsTwo[i] = powsTwo[i-1] * 2;

        FOR(i, 1, sz(data)) {
            ll newInc = min(needInc / powsTwo[sz(data) - 1 - i], M);
            data[i] += newInc;
            FOR(j, i+1, sz(data)) {
                data[j] += newInc * powsTwo[j-i];
            }
            needInc -= newInc * powsTwo[sz(data) - 1 - i];

        }

        if (data[sz(data) - 1] < B) {
            cout << -1 << endl; goto done;
        }

        cout << sz(data) << " ";
        F0R(i, sz(data)) {
            cout << data[i] << " ";
        }
        cout << endl;

        done:;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343