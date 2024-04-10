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
const int MX = 2001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int K; cin >> K;

    char data[N][N];
    F0R(i, N) {
        F0R(j, N) {
            cin >> data[i][j];
        }
    }

    int dp[N][N];
    F0R(i, N) F0R(j, N) dp[i][j] = 0;



    int best = -1;

    F0R(i, N) {
        F0R(j, N) {
            if (data[i][j] == 'a') dp[i][j]++;
            if (i+1 < N) {
                dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
            }
            if (j+1 < N) {
                dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
            }

            if (dp[i][j] + K > i+j) {
                best = max(best, i+j);
            }
        }
    }


    bool up[N][N];
    vi candidates;

    F0R(i, N) {
        if (best - i >= 0 && best - i < N) {
            if (dp[i][best - i] + K > best) {
                candidates.pb(i);
            }
        }
    }
    bool isZero = best == -1;
    up[0][0] = false;

    if (best < 0) { candidates.pb(0); best++; }

    bool visited[N][N]; F0R(i, N) F0R(j, N) visited[i][j] = false;

    FOR(level, best, 2*N-2) {
        vi nxt;
        char leastCharacter = 'z'+1;
        F0R(curCand, sz(candidates)) {
            int i = candidates[curCand];
            if (i < N-1 && data[i+1][level-i] < leastCharacter && !visited[i+1][level-i]) {
                leastCharacter = data[i+1][level-i];
                up[i+1][level-i] = false;
                vi().swap(nxt);
                nxt.pb(i+1);
                visited[i+1][level-i] = true;
            } else if (i < N-1 && data[i+1][level-i] == leastCharacter && !visited[i+1][level-i]) {
                up[i+1][level-i] = false;
                nxt.pb(i+1);
                visited[i+1][level-i] = true;
            }

            if (level-i < N-1 && data[i][level-i+1] < leastCharacter && !visited[i][level-i+1]) {
                leastCharacter = data[i][level-i+1];
                up[i][level-i+1] = true;
                vi().swap(nxt);
                nxt.pb(i);
                visited[i][level-i+1]= true;
            } else if (level-i < N-1 && data[i][level-i+1] == leastCharacter && !visited[i][level-i+1]) {
                leastCharacter = data[i][level-i+1];
                up[i][level-i+1] = true;
                nxt.pb(i);
                visited[i][level-i+1]= true;
            }
        }
        candidates.swap(nxt);
        vi().swap(nxt);
    }

    vector<char> reconstruct;
    int curI = N-1, curJ = N-1;
    if (isZero) best--;
    while (curI + curJ > best) {
        reconstruct.pb(data[curI][curJ]);
        if (up[curI][curJ]) {
            curJ--;
        } else {
            curI--;
        }
    }


    F0R(i, best+1) {
        reconstruct.pb('a');
    }

    reverse(all(reconstruct));
    F0R(i, sz(reconstruct)) {
        cout << reconstruct[i];
    }

    cout << endl;



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343