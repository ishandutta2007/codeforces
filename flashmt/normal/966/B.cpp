#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, x[2], good[2];
vector < pair<int,int> > a;
vector <int> ans[2];

int main()
{
  ios::sync_with_stdio(0);
  int c;
  cin >> n >> x[0] >> x[1];
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    a.push_back({c, i});
  }

  sort(a.begin(), a.end(), greater< pair<int,int> >());
  for (int i = 0; i < 2; i++)
  {
    good[i] = oo;
    for (int j = 0; j < n; j++)
      if ((j + 1LL) * a[j].first >= x[i]) 
      {
        good[i] = j + 1;
        break;
      }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
    {
      int need = (x[j] + a[i].first - 1) / a[i].first;
      if (good[j ^ 1] + need <= i + 1)
      {
        for (int k = 0; k < good[j ^ 1] + need; k++)
          if (k < good[j ^ 1]) ans[j ^ 1].push_back(a[k].second);
          else ans[j].push_back(a[k].second);
        cout << "Yes\n";
        cout << ans[0].size() << ' ' << ans[1].size() << '\n';
        for (int z = 0; z < 2; z++)
          for (int k = 0; k < ans[z].size(); k++)
            cout << ans[z][k] + 1 << (k == ans[z].size() - 1 ? '\n' : ' ');
        return 0;
      }
    }
  cout << "No\n";
}