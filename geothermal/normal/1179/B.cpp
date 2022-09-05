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

    int N, M; cin >> N >> M;
    //vpi data;
    F0R(i, N/2) {
        F0R(j, M) {
            printf("%d %d\n", i+1, j+1);
            //cout << i+1 << " " << j+1 << endl;
            //data.pb(mp(i+1, j+1));
            printf("%d %d\n", N-i, M-j);
            //cout << (N-i) << " " << (M-j) << endl;
            //data.pb(mp(N-i, M-j));
        }
    }

    if (N % 2 == 1) {
        int val = N / 2;
        F0R(i, M/2) {
            printf("%d %d\n", val+1, i+1);
            //cout << val+1 << " " << i+1 << endl;
            //data.pb(mp(val+1, i+1));
            printf("%d %d\n", val+1, M-i);
            //cout << val+1 << " " << M-i << endl;
            //data.pb(mp(val+1, M-i));
        }
        if (M % 2 == 1) {
            int val2 = M / 2;
            printf("%d %d\n", val+1, val2+1);
            //cout << val+1 << " " << val2+1 << endl;
            //data.pb(mp(val+1, val2+1));
        }
    }

    /*set<pi> used;
    F0R(i, sz(data) - 1) {
        pi sec = data[i+1]; pi fir = data[i];
        pi res = mp(sec.f - fir.f, sec.s - fir.s);
        if (used.count(res)) {
            cout << "WA" << endl; return 0;
        }
        used.insert(res);
    }

    bool visited[N][M];
    F0R(i, N) F0R(j, M) visited[i][j] = false;
    F0R(i, sz(data)) {
        visited[data[i].f-1][data[i].s-1] = true;
    }
    F0R(i, N) {
        F0R(j, M) {
            if (!visited[i][j]) {
                cout << "WA" << endl; return 0;
            }
        }
    }*/

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343