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
const int MX = 300001;

int N, M;
int data[MX];

bool possible(int K) {
    int locMax = data[0];
    if (data[0] + K >= M) {
        locMax = 0;
    }
    FOR(i, 1, N) {
        int cur = data[i];
        if (data[i] < locMax) {
            int need = locMax - data[i];
            if (need > K) return false;
        } else if (data[i] > locMax) {
            if (data[i] + K < M + locMax) {
                locMax = data[i];
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    F0R(i, N) cin >> data[i];

    int lo = 0;
    int hi = M-1;
    F0R(i, 30) {
        int mid = (lo+hi)/2;
        if (possible(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    cout << lo << endl;


    return 0;
}