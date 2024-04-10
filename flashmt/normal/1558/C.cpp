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
    vector<int> a(n);
    int isGood = 1;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i]--;
      if ((i % 2) ^ (a[i] % 2))
        isGood = 0;
    }

    if (!isGood)
    {
      cout << -1 << endl;
      continue;
    }

    vector<int> ans;
    auto rev = [&](int len)
    {
      ans.push_back(len);
      reverse(begin(a), begin(a) + len);
    };

    for (int x = 0; x + 1 < n; x += 2)
    {
      int oddId = 0, evenId = 0;
      for (int i = 0; i < n; i++)
      {
        if (a[i] == x)
          evenId = i;
        if (a[i] == x + 1)
          oddId = i;
      }

      rev(evenId + 1);
      if (evenId > oddId)
        oddId = evenId - oddId;
      rev(oddId);
      rev(oddId + 2);
      rev(3);
      rev(n - x);
    }
    ans.push_back(n);
    reverse(begin(a), end(a));
    for (int i = 0; i < n; i++)
      assert(a[i] == i);

    cout << size(ans) << '\n';
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}