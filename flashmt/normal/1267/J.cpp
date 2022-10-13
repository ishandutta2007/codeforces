#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, a[2000200], cnt[2000200] = {0}, flag[2000200] = {0};
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }

    vector<int> allCnt;
    for (int i = 0; i < n; i++)
      if (flag[a[i]] != iTest)
      {
        flag[a[i]] = iTest;
        allCnt.push_back(cnt[a[i]]);
      }

    sort(allCnt.begin(), allCnt.end());
    set<int> screenSizes;
    int last = 0;
    for (int x : allCnt)
      if (x > last)
      {
        for (int i = 1; i * i <= x; i++)
        {
          int j = x / i;
          screenSizes.insert(i + 1);
          screenSizes.insert(j + 1);
          if (i * j == x)
          {
            screenSizes.insert(i);
            screenSizes.insert(j);
          }
        }
        last = x;
      }

    int ans = n;
    for (int s : screenSizes)
      if (s <= allCnt[0] + 1)
      {
        int total = 0;
        for (int i = 0; i < allCnt.size();)
        {
          int j = i + 1;
          while (j < allCnt.size() && allCnt[j] == allCnt[i])
            j++;
          int numScreen = (allCnt[i] + s - 1) / s;
          if (numScreen * s != allCnt[i] && allCnt[i] / numScreen + 1 != s)
          {
            total = n;
            break;
          }
          total += (j - i) * numScreen;
          i = j;
        }

        ans = min(ans, total);
      }

    cout << ans << '\n';
    for (int i = 0; i < n; i++)
      cnt[a[i]] = 0;
  }
}