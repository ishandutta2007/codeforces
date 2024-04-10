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
    int n, k;
    cin >> n >> k;
    vector<int> a(n * 2, -1);
    for (int i = 0; i < k; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x] = --y;
      a[y] = x;
    }

    vector<int> b;
    for (int i = 0; i < n * 2; i++)
      if (a[i] < 0)
        b.push_back(i);

    for (int i = 0; i < n - k; i++)
    {
      a[b[i]] = b[i + n - k];
      a[b[i + n - k]] = b[i];
    }

    int ans = 0;
    for (int i = 0; i < n * 2; i++)
      for (int j = i + 1; j < n * 2; j++)
        if (i < a[i] && j < a[j])
          ans += j < a[i] && a[i] < a[j];

    cout << ans << endl;
  }
}