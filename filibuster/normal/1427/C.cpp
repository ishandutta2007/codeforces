#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

int t[N], a[N], b[N], dp[N];

int main() {
    int r, n;
    cin >> r >> n;

    for(int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    dp[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] + b[i] <= t[i]) {
            dp[i + 1] = 1;
            for(int j = max(0, i - 4 * r - 4); j < i; j++) {
                if(abs(a[i] - a[j]) + abs(b[i] - b[j]) <= t[i] - t[j])
                    dp[i + 1] = max(dp[i + 1], dp[j + 1] + 1);
            }
        }
        ans = max(ans, dp[i + 1]);
    }

    cout << ans << endl;
}