#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, w, len, a[1000100];
  long long ans[1000100] = {0};

  cin >> n >> w;
  while (n--)
  {
    cin >> len;
    int maxA = -oo;
    for (int i = 0; i < len; i++)
    {
      cin >> a[i];
      maxA = max(maxA, a[i]);
    }

    deque<pair<int, int>> dq;
    for (int i = 0; i < len; i++)
    {
      while (!dq.empty() && a[i] >= dq.back().first)
        dq.pop_back();
      dq.push_back({a[i], i});
      while (i - dq.front().second > w - len)
        dq.pop_front();
      if (dq.front().first >= 0 || i + len >= w)
      {
        ans[i] += dq.front().first;
        ans[i + 1] -= dq.front().first;
      }
    }

    dq.clear();
    for (int i = len - 1, j = w - 1; i >= 0 && j >= len; i--, j--)
    {
      while (!dq.empty() && a[i] >= dq.back().first)
        dq.pop_back();
      dq.push_back({a[i], i});
      while (j - dq.front().second > w - len)
        dq.pop_back();
      if (dq.front().first >= 0 || j < len)
      {
        ans[j] += dq.front().first;
        ans[j + 1] -= dq.front().first;
      }
    }

    if (maxA >= 0 && len * 2 < w)
    {
      ans[len] += maxA;
      ans[w - len] -= maxA;
    }
  }

  for (int i = 0; i < w; i++)
  {
    if (i)
      ans[i] += ans[i - 1];
    cout << ans[i] << " \n"[i == w - 1];
  }
}