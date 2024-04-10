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
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }

    vector<int> ans;
    while (1)
    {
      int toFixId = -1;
      for (int i = 0; i + 1 < n; i++)
        if (a[i] > a[i + 1])
        {
          toFixId = i;
          break;
        }
      if (toFixId < 0)
        break;

      int mex = 0;
      while (cnt[mex])
        mex++;

      int id = mex < n ? mex : toFixId;
      ans.push_back(id);
      cnt[a[id]]--;
      a[id] = mex;
      cnt[mex]++;
    }

    cout << ans.size() << endl;
    for (int x : ans)
      cout << x + 1 << ' ';
    cout << endl;
  }
}