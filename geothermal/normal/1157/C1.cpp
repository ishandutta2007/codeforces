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
    int data[N]; F0R(i, N) cin >> data[i];

    int maxVal = -1;
    int ans = 0;
    int lo = 0;
    int hi = N-1;
    vector<char> result;
    F0R(i, N) {
        bool takeLo = true;
        if (data[lo] == data[hi]) break;
        if (data[lo] < data[hi]) {
            takeLo = false;
            if (maxVal < data[lo]) takeLo = true;
            if (maxVal >= data[hi]) break;
        } else {
            takeLo = true;
            if (maxVal < data[hi]) takeLo = false;
            if (maxVal >= data[lo]) break;
        }
        if (takeLo) {
            if (maxVal >= data[lo]) break;
            maxVal = data[lo];
            lo++;
            ans++; result.pb('L');

        } else {
            if (maxVal >= data[hi]) break;
            maxVal = data[hi];
            hi--;
            ans++; result.pb('R');

        }

        if (lo > hi) break;
    }

    if (lo <= hi && data[lo] == data[hi]) {
        int oldMax = maxVal; int oldLo = lo; int lPos = 0;
        while (lo <= hi && maxVal < data[lo]) {
            maxVal = data[lo]; lo++; lPos++;
        }
        maxVal = oldMax; lo = oldLo; int rPos = 0;
        while (lo <= hi && maxVal < data[hi]) {
            maxVal = data[hi]; hi--; rPos++;
        }
        ans += max(lPos, rPos);
        if (lPos >= rPos) {
            F0R(i, lPos) result.pb('L');
        } else {
            F0R(i, rPos) result.pb('R');
        }
    }

    cout << ans << endl;
    F0R(i, ans) cout << result[i];
    cout << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343