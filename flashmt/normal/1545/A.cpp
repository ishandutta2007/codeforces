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
    vector<int> a[2];
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[i % 2].push_back(x);
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    int ans = 1;
    for (int i = 0, last = 0; i < n; i++)
    {
      int cur = a[i % 2][i / 2];
      if (cur < last)
        ans = 0;
      last = cur;
    }

    cout << (ans ? "YES\n" : "NO\n");
  }
}