#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, t, a[100105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int L = 0, R = -1, sum = 0;
    int ans = 0;
    while (L < n)  {
        while (R < n - 1 && sum <= t)
            sum += a[++R];
        ans = max(ans, R - L + (sum <= t));
        sum -= a[L++];
    }
    cout << ans;
}