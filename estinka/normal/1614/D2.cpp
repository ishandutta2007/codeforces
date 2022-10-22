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

const int maxa = 2e7 + 5;
int cnt[maxa];
ll dp[maxa];
int lp[maxa];
vector<int> pr;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 2; i < maxa; i++)
    {
        if (lp[i] == 0) pr.push_back(i), lp[i] = i;
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < maxa; j++)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
    for (int i = 1; i < maxa; i++)
    {
        for (int j = i * 2; j < maxa; j += i)
        {
            cnt[i] += cnt[j];
        }
    }
    for (int i = maxa - 1; i > 0; i--) if (cnt[i])
    {
        dp[i] = cnt[i] * 1ll * i;
        for (int j = 0; j < pr.size() && i * pr[j] < maxa; j++) if (cnt[i * pr[j]])
        {
            dp[i] = max(dp[i], dp[i * pr[j]] + (cnt[i] - cnt[i * pr[j]]) * 1ll * i);
        }
    }
    cout << dp[1] << "\n";
    return 0;
}