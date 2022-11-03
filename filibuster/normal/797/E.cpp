#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int B = 300;

int dp[B][N];
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int k = 0; k < B; k++)
        for(int i = n - 1; i >= 0; i--) {
            dp[k][i] = (i + k + a[i] >= n ? 1 : 1 + dp[k][i + k + a[i]]);
        }

    int q;
    cin >> q;

    while(q--) {
        int p, k;
        cin >> p >> k;

        p--;

        if(k < B)
            cout << dp[k][p] << '\n';
        else {
            int ans = 0;

            while(p < n) {
                p += a[p] + k;
                ans++;
            }

            cout << ans << '\n';
        }
    }
}