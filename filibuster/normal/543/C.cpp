#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;

const int N = 20 + 1;
const int A = 26;

/*
5 2
aa
aa
ab
bb
bb
1 100
100 100
1 1
100 100
100 1

*/

int dp[1 << N];
int a[N][N], b[N][N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;

            a[i][j] = c - 'a';
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];

    for(int i = 0; i < (1 << n); i++)
        dp[i] = INF;

    dp[0] = 0;
    for(int i = 0; i < m; i++) {
        for(int x = 0; x < A; x++) {
            int sum = 0;
            int msk = 0;
            int mx = 0;
            for(int j = 0; j < n; j++) {
                if(a[j][i] == x) {
                    sum += b[j][i];
                    mx = max(mx, b[j][i]);
                    msk |= (1 << j);
                }
            }

            for(int mask = 0; mask < (1 << n); mask++)
                dp[mask | msk] = min(dp[mask | msk], dp[mask] + sum - mx);

//            if(x < 2)
//                cout << x << ' ' << dp[(1 << n) - 1] << ' ' << msk << ' ' << sum << ' ' << mx << endl;
        }

        for(int j = 0; j < n; j++) {
            for(int mask = 0; mask < (1 << n); mask++)
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + b[j][i]);
        }
//        cout << dp[(1 << n) - 1] << endl;
    }

    cout << dp[(1 << n) - 1];
}