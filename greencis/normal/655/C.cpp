#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, k, sum[100105];
int ans = 2e9;
char s[100105];

int main()
{
    cin >> n >> k >> s + 1;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + (s[i] == '1');

    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') continue;
        int L = 1, R = n;
        while (L < R) {
            int mid = (L + R) / 2;
            int lb = max(1, i - mid);
            int rb = min(n, i + mid);
            int cnt = (rb - lb + 1) - (sum[rb] - sum[lb - 1]);
            if (cnt >= k + 1)
                R = mid;
            else
                L = mid + 1;
        }
        ans = min(ans, L);
    }
    cout << ans;

    return 0;
}