#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  map<int, int> enterTime;
  set<int> inOffice, entered;
  vector<int> ans;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x > 0)
    {
      if (entered.count(x))
      {
        cout << -1 << endl;
        return 0;
      }
      inOffice.insert(x);
      entered.insert(x);
      enterTime[x] = i;
    }
    else
    {
      if (!inOffice.count(-x))
      {
        cout << -1 << endl;
        return 0;
      }
      inOffice.erase(-x);
      if (inOffice.empty())
      {
        int minEnterTime = i;
        for (int x : entered)
          minEnterTime = min(minEnterTime, enterTime[x]);
        ans.push_back(i - minEnterTime + 1);
        entered.clear();
      }
    }
  }

  if (!inOffice.empty()) cout << -1 << endl;
  else
  {
    cout << ans.size() << endl;
    for (int x : ans)
      cout << x << ' ';
  }
}