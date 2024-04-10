#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a[200200];

int main()
{
  ios::sync_with_stdio(0);
  int x, y, Q, num, q[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
  }

  set < pair<int,int> > last;
  for (int i = 1; i <= n; i++)
    if (!a[i].empty())
      last.insert({-a[i].back(), i});

  cin >> Q;
  while (Q--)
  {
    cin >> num;
    for (int i = 0; i < num; i++)
    {
      cin >> q[i];
      if (!a[q[i]].empty())
        last.erase({-a[q[i]].back(), q[i]});
    }

    if (last.empty()) cout << "0 0\n";
    else 
    {
      auto it = last.begin();
      int ans = it->second;
      cout << ans << ' ';
      if (last.size() == 1) cout << a[ans][0] << '\n';
      else
      {
        it++;
        cout << *lower_bound(a[ans].begin(), a[ans].end(), a[it->second].back()) << '\n';
      }
    }

    for (int i = 0; i < num; i++)
      if (!a[q[i]].empty())
        last.insert({-a[q[i]].back(), q[i]});
  }
}