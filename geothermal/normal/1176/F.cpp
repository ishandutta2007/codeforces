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

    int N; cin >> N;
    ll dp[N+1][10];
    F0R(i, 10) F0R(j, N+1) dp[j][i] = -100000000000000000;
    dp[0][0] = 0;
    F0R(i, N) {
        int K; cin >> K;
        vl cards[3];
        F0R(j, K) {
            ll num, damage; cin >> num >> damage;
            cards[num-1].pb(damage);
        }
        F0R(j, 3) {
            sort(all(cards[j]));
            reverse(all(cards[j]));
        }

        F0R(j, 10) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (sz(cards[0]) >= 3) {
                ll damage = cards[0][0] + cards[0][1] + cards[0][2];
                if (j+3>=10) damage += max(cards[0][0], max(cards[0][1], cards[0][2]));
                dp[i+1][(j+3)%10] = max(dp[i+1][(j+3)%10], dp[i][j]+damage);
            }
            if (sz(cards[0]) >= 2) {
                ll damage = cards[0][0] + cards[0][1];
                if (j+2 >= 10) damage += max(cards[0][0], cards[0][1]);
                dp[i+1][(j+2)%10] = max(dp[i+1][(j+2)%10], dp[i][j]+damage);
            }
            if (sz(cards[0]) >= 1) {
                ll damage = cards[0][0];
                if (j+1 >= 10) damage += cards[0][0];
                dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10], dp[i][j]+damage);
            }
            if (sz(cards[1]) >= 1 && sz(cards[0]) >= 1) {
                ll damage = cards[1][0] + cards[0][0];
                if (j+2 >= 10) damage += max(cards[1][0], cards[0][0]);
                dp[i+1][(j+2)%10] = max(dp[i+1][(j+2)%10], dp[i][j]+damage);
            }
            if (sz(cards[1]) >= 1) {
                ll damage = cards[1][0];
                if (j+1 >= 10) damage += cards[1][0];
                dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10], dp[i][j]+damage);
            }
            if (sz(cards[2]) >= 1) {
                ll damage = cards[2][0];
                if (j+1 >= 10) damage += cards[2][0];
                dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10], dp[i][j]+damage);
            }
        }

    }

    ll ans = 0;
    F0R(i, 10) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343