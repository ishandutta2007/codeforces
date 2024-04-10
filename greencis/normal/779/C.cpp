#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, ans;
pii a[200105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    sort(a, a + n, [] (const pii & lhs, const pii & rhs) -> int {
        return lhs.first - lhs.second < rhs.first - rhs.second;
    });
    int i = 0;
    for (; i < k || a[i].first < a[i].second; ++i)
        ans += a[i].first;
    for (; i < n; ++i)
        ans += a[i].second;
    cout << ans;

    return 0;
}