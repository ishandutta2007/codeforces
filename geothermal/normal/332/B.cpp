#pragma GCC optimize("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> pvi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;

    ll data[N+1]; F0R(i, N) cin >> data[i];

    data[N] = 0;
    F0Rd(i, N-1) data[i] = data[i] + data[i+1];

    ll dp[N+1][2];

    int pos[N][2];

    F0R(i, N+1) F0R(j, 2) dp[i][j] = 0;
    F0R(i, N) F0R(j, 2) pos[i][j] = N-1;

    F0Rd(i, N) {
        if (i < N-1) {
            pos[i][0] = pos[i+1][0];
            pos[i][1] = pos[i+1][1];
        }
        if (i + K <= N) dp[i][0] = max(dp[i+1][0], data[i] - data[i+K]);
        if (i+K <= N && dp[i][0] == data[i] - data[i+K]) pos[i][0] = i;
        if (i + 2*K <= N) dp[i][1] = max(dp[i+1][1], data[i] - data[i+K] + dp[i+K][0]);
        if (i+2*K <= N && dp[i][1] == data[i] - data[i+K] + dp[i+K][0]) pos[i][1] = i;
        
    }

    cout << pos[0][1] + 1 << " " << pos[pos[0][1] + K][0] + 1 << endl;

    return 0;
}