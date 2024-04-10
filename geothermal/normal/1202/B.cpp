#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string S; cin >> S;

    F0R(X, 10) {
        F0R(Y, 10) {
            int dist[10][10];
            F0R(i, 10) {
                F0R(j, 10) {
                    dist[i][j] = -1;
                }
            }
            F0R(i, 10) {
                dist[i][(i+X)%10] = 0;
                dist[i][(i+Y)%10] = 0;
                queue<int> q; q.push((i+X)%10);
                q.push((i+Y)%10);
                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    int nxt = (cur+X)%10;
                    if (dist[i][nxt] == -1) {
                        dist[i][nxt] = dist[i][cur]+1;
                        q.push(nxt);
                    }

                    nxt = (cur+Y)%10;
                    if (dist[i][nxt] == -1) {
                        dist[i][nxt] = dist[i][cur]+1;
                        q.push(nxt);
                    }
                }
            }

            int ans = 0;

            F0R(i, sz(S)-1) {
                int A = S[i] - '0', B = S[i+1] - '0';
                if (dist[A][B] == -1) {
                    cout << -1 << " "; goto done;
                }
                ans += dist[A][B];
            }
            cout << ans << " ";

            done:;
        }
        cout << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE