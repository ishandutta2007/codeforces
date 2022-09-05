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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    vpi intervals, queries;
    int MX = 0;
    F0R(i, N) {
        int L, R;
        cin >> L >> R;
        MX = max(MX, R+1);
        intervals.pb(mp(L, R));
    }
    F0R(i, M) {
        int L, R;
        cin >> L >> R;
        MX = max(MX, R+1);
        queries.pb(mp(L, R));
    }
    int best[MX][20];
    sort(all(intervals));
    int index = 0;
    int maxReach = -1;
    F0R(i, MX) {
        F0R(j, 20) {
            best[i][j] = -1;
        }
    }
    F0R(i, MX) {
        while (index < N && intervals[index].f == i) {
            maxReach = max(maxReach, intervals[index].s);
            index++;
        }
        if (i >= maxReach) maxReach = -1;
        best[i][0] = maxReach;
    }
    F0Rd(i, MX) {
        FOR(j, 1, 20) {
            int cur = i;
            F0R(k, j) {
                cur = best[cur][k];
                if (cur == -1) goto bad;
            }
            cur = best[cur][0];
            best[i][j] = cur;
            bad:;
        }
    }

    F0R(i, M) {
        int X = queries[i].f, Y = queries[i].s;
        int cur = X;
        int ans = 0;
        while (true) {
            F0R(i, 20) {
                if (best[cur][i] == -1 || best[cur][i] >= Y) {
                    if (i == 0) {
                        if (best[cur][i] == -1) {
                            ans = -1;
                        } else {
                            ans++;
                        }
                        goto done;
                    }
                    ans += (1 << (i-1));
                    cur = best[cur][i-1];
                    goto cont;
                }
            }
            cont:;
        }
        done:;
        cout << ans << endl;
    }


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343