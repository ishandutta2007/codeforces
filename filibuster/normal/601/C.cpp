#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1003;
const int N = 103;
const int MAX = M * N;

/*
2 1 9
1 2 1
*/

int a[N];
ld dp[N][MAX];
//ld p[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    if(m == 1) {
        cout << 1 << endl;
        return 0;
    }

    dp[0][0] = m - 1;
    for(int i = 1; i <= n; i++) {
        ld cur = 0;
        for(int s = 1; s <= m * i + m; s++) {
            cur += dp[i - 1][s - 1];
            if(s > m)
                cur -= dp[i - 1][s - m - 1];
            dp[i][s] = cur;

            if(s >= a[i - 1])
                dp[i][s] -= dp[i - 1][s - a[i - 1]];

            dp[i][s] /= m - 1;
        }
    }

    ld ans = 0;
    for(int i = 0; i < sum; i++)
        ans += dp[n][i];

    cout << setprecision(25) << fixed << 1 + ans/* * (m - 1)*/ << endl;
}