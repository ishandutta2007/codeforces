#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <array>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r, total = 0;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    vector<int> im, nonim;
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        if (t == 0) nonim.push_back(a[i]);
        else im.push_back(a[i]);
    }
    vector<int> how_many(total + 1, 0);
    sort(im.begin(), im.end(), greater<int>());
    vector<int> dp(total + 2, -100000);
    dp[total] = 0;
    for (int i : nonim)
    {
        for (int j = i; j <= total; j++)
        {
            dp[j - i] = max(dp[j - i], dp[j]);
        }
    }
    for (int i : im)
    {
        for (int j = i; j <= total; j++)
        {
            dp[j - i] = max(dp[j - i], dp[j] + (l <= (j - i) && (j - i) <= r));
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}