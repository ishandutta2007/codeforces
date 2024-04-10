#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, c;
    cin >> n >> c;
    vector<int> a(n), cnt(c + 1), sumCnt(c + 1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }
    for (int i = 1; i <= c; i++)
      sumCnt[i] = sumCnt[i - 1] + cnt[i];

    int ans = cnt[1] > 0;
    for (int i = 2; i <= c; i++)
      if (cnt[i])
        for (int j = i * 2; j <= c; j += i)
          if (sumCnt[min(c, j + i - 1)] > sumCnt[j - 1] && !cnt[j / i])
            ans = 0;

    cout << (ans ? "Yes" : "No") << '\n';
  }
}