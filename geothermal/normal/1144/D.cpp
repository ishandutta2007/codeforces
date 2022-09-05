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
    vi data(N);
    int counts[200010];
    int lasts[200010];
    int maxCount = 0;
    int best = -1;
    F0R(i, 200010) counts[i] = 0;
    F0R(i, N) {
        cin >> data[i];
        counts[data[i]]++;
        lasts[data[i]] = i;
        maxCount = max(counts[data[i]], maxCount);
        if (counts[data[i]] == maxCount) {
            best = data[i];
        }
    }

    cout << N - counts[best] << endl;
    F0Rd(i, lasts[best]) {
        if (data[i] < best) {
            cout << 1 << " " << i+1 << " " << i+2 << endl;
        } else if (data[i] > best) {
            cout << 2 << " " << i+1 << " " << i+2 << endl;
        }
    }
    FOR(i, lasts[best] + 1, N) {
        if (data[i] < best) {
            cout << 1 << " " << i+1 << " "<< i << endl;
        } else if (data[i] > best) {
            cout << 2 << " " << i+1 << " "<<i << endl;
        }
    }









    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343