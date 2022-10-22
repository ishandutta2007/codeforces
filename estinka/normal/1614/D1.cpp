#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

const int maxa = 5e6 + 5;
int main()
{
    vector<int> cnt(maxa, 0); // cnt[i] = number of a divisible by i
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i < maxa; i++)
    {
        for (int j = i * 2; j < maxa; j += i)
        {
            cnt[i] += cnt[j];
        }
    }
    vector<ll> dp(maxa, 0);
    for (int i = maxa - 1; i > 0; i--)
    {
        dp[i] = cnt[i] * 1ll * i;
        for (int j = i * 2; j < maxa; j += i)
        {
            dp[i] = max(dp[i], dp[j] + (cnt[i] - cnt[j]) * 1ll * i);
        }
    }
    cout << dp[1] << "\n";
    return 0;
}