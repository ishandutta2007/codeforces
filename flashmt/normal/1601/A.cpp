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
    vector<int> a, cnt(30);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      for (int j = 0; j < 30; j++)
        if (x >> j & 1)
          cnt[j]++;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
      int isGood = 1;
      for (int j = 0; j < 30; j++)
        if (cnt[j] % i)
          isGood = 0;
      if (isGood)
        cout << i << ' ';
    }
    cout << '\n';
  }
}