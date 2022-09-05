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
        set<int> dataPrune;
        F0R(i, N) {
            int cur; cin >> cur;
            dataPrune.insert(cur);
        }
        vi data;
        for (auto it = dataPrune.begin(); it != dataPrune.end(); it++) {
            data.pb(*it);
        }

        sort(all(data)); reverse(all(data));
        N = sz(data);
        int ans = data[0];
        int bestTwo = 0;
        F0R(i, min(N, 350)) {
            F0R(j, 200) {
                if (i+j >= N) goto done2;
                if (data[i] % data[i+j] != 0) {
                    bestTwo = max(bestTwo, data[i]+data[i+j]);
                }
            }
            done2:;
        }

        ans = max(ans, bestTwo);

        int bestThree = 0;

        ans = max(ans, bestTwo);

        F0R(i, min(N, 350)) {
            vi candidates;
            FOR(j, i+1, N) {
                if (data[i] % data[j] != 0) {
                    candidates.pb(data[j]);
                }
                if (sz(candidates) > 200) goto done3;
            }
            done3:;
            if (sz(candidates) < 2) continue;
            int curBest = 0;
            stack<int> tbd;
            tbd.push(candidates[0]);
            FOR(j, 1, sz(candidates)) {
                while (!tbd.empty() && tbd.top() % candidates[j] != 0) {
                    curBest = max(curBest, tbd.top() + candidates[j]);
                    tbd.pop();
                }
                if (tbd.empty()) break;
                tbd.push(candidates[j]);
            }
            bestThree = max(bestThree, curBest + data[i]);
        }

        cout << max(ans, bestThree) << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343