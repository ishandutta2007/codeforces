#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <bitset>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1 << 18;
vector<int> st(maxn * 2, -1e9);
void update(int i, int x)
{
    for (i += maxn; i > 0; i >>= 1) st[i] = max(st[i], x);
}
int query(int l, int r)
{
    int ans = -1e9;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) ans = max(ans, st[l++]);
        if (r & 1) ans = max(ans, st[--r]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    update(0, 0);
    vector<int> a(n + 1), first(n + 1, n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (first[a[i]] == n + 1) first[a[i]] = i;
        int k = min(first[a[i]], i - 1);
        dp[i] = query(k, i) + i - 1;
        update(i, dp[i] - i);
    }
    cout << dp[n] << "\n";
    return 0;
}