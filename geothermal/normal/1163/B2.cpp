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

    int data[N];

    int counts[MX]; F0R(i, MX) counts[i] = 0;

    int numMax, numMin; numMax = 1; numMin = 0;
    int countSeen = 1;
    int maxSoFar = 1;
    int ans = 1;
    int countOnes = 1;
    F0R(i, N) {
        cin >> data[i];
    }
    counts[data[0]] = 1;

    FOR(i, 1, N) {
        int cur = data[i];
        if (counts[cur] == 0) {
            countSeen++;
            countOnes++;
        } else if (counts[cur] == 1) {
            countOnes--;
        }
        if (counts[cur] == maxSoFar) {
            maxSoFar = counts[cur] + 1;
            numMin = numMax-1; numMax = 1;
        } else if (counts[cur] == maxSoFar - 1) {
            numMax++;
            if (counts[cur] != 0) numMin--;
        } else if (counts[cur] == maxSoFar - 2) {
            numMin++;
        }
        counts[cur]++;

        if ((numMax == 1 && numMin == countSeen - 1) || (countOnes == 1 && numMax == countSeen - 1) || (countOnes == countSeen)) {
            ans = i+1;
        }

    }

    cout << ans << endl;




    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343