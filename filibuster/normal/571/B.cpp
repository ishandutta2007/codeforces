#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int K = 5013;

int a[N];
li dp[K][K];
int n, k;

li get(int x, int y) {
    if(dp[x][y] != -1)
        return dp[x][y];

    if(x > 0) {
        int i = x * (n / k) + y * (n / k + 1);
        dp[x][y] = max(dp[x][y], get(x - 1, y) + a[i] - a[i - 1]);
    }

    if(y > 0) {
        int i = x * (n / k) + y * (n / k + 1);
        dp[x][y] = max(dp[x][y], get(x, y - 1) + a[i] - a[i - 1]);
    }

//    cout << x << ' ' << y <<' ' << dp[x][y] << ' ' << x * (n / k) + y * (n / k + 1) << endl;

    return dp[x][y];
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    a[n] = a[n - 1];

    li sum = 0;
    for(int i = 0; i < n - 1; i++)
        sum += a[i + 1] - a[i];

    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;

//    cout << sum << endl;

    cout << sum - get(k - n % k, n % k) << endl;
}