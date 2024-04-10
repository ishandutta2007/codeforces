#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<long long> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      sum[i] = sum[i - 1] + (i % 2 ? a[i] : -a[i]);
    }

    set<pair<long long, int>> s[2];
    s[0].insert({0, 0});
    map<long long, int> cnt;
    cnt[0] = 1;
    deque<int> q[2];
    q[0].push_back(0);
    long long ans = 0;
    for (int i = 1, j = 0; i <= n; i++)
    {
      s[i % 2].insert({sum[i], i});
      while (1)
        if ((!empty(s[0]) && rbegin(s[0])->first > sum[j]) || (!empty(s[1]) && begin(s[1])->first < sum[j]))
        {
          s[j % 2].erase({sum[j], j});
          j++;
        }
        else break;

      for (int z = 0; z < 2; z++)
        while (!empty(q[z]) && q[z].front() < j)
        {
          int k = q[z].front();
          q[z].pop_front();
          cnt[sum[k]]--;
        }

      ans += cnt[sum[i]];
      cnt[sum[i]]++;

      int z = i % 2;
      while (!empty(q[z]))
      {
        int k = q[z].back();
        if ((z == 1 && sum[i] < sum[k]) || (z == 0 && sum[i] > sum[k]))
        {
          cnt[sum[k]]--;
          q[z].pop_back();
        }
        else break;
      }
      q[z].push_back(i);
    }
    cout << ans << '\n';
  }
}