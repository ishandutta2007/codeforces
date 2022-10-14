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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--;
    b--;
    vector<int> s(m);
    for (int i = 0; i < m; i++)
      cin >> s[i];
    sort(s.begin(), s.end());

    int low = 1, high = min(m, abs(a - b) - 1), ans = 0;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int isGood = 1, timeToCatch = (a < b ? b : n - 1 - b);
      for (int i = mid - 1; i >= 0; i--)
        if (--timeToCatch < s[i])
          isGood = 0;

      if (!isGood) high = mid - 1;
      else
      {
        ans = mid;
        low = mid + 1;
      }
    }

    cout << ans << endl;
  }
}