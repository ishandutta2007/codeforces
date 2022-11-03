#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2000 + 13;

/*
*/

li dp[N];
int a[N], l[N], r[N];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i];
    }

    for(int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[0] = 0;

    li ans = INF;
    for(int i = 0; i < n; i++) {
        if(dp[i] >= INF)
            continue;

        int cur = k;
        for(int j = i; j < n; j++) {
            if(cur + (r[j] - l[j]) * 1ll * k >= a[j]) {

                if(cur + (r[j] - l[j] - 1) * 1ll * k >= a[j] || l[j + 1] != r[j])
                    dp[j + 1] = min(dp[j + 1], dp[i] + cur + (a[j] - cur + k - 1) / k * k - a[j]);

                cur = cur + (a[j] - cur + k - 1) / k * k - a[j];
                if(j == n - 1) {
                    ans = min(ans, dp[i]);
                }
            } else {
                break;
            }
        }
    }

    li s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }

    cout << (ans < INF ? ans + s : -1) << endl;

}