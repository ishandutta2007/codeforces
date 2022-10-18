#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n, k, a[300105], sum[300105];
int ans, ansl, ansr;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        int L = 1, R = i;
        while (L < R) {
            int mid = (L + R) >> 1;
            if ((i - mid + 1) - (sum[i] - sum[mid - 1]) <= k)
                R = mid;
            else L = mid + 1;
        }
        if ((i - L + 1) - (sum[i] - sum[L - 1]) <= k) {
            int cans = (i - L + 1);
            if (cans > ans) {
                ans = cans;
                ansl = L;
                ansr = i;
            }
        }
    }
    for (int i = ansl; i <= ansr; ++i)
        a[i] = 1;
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";

    return 0;
}