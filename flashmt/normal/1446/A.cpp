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
    long long capacity;
    vector<pair<int, int>> items;
    cin >> n >> capacity;
    for (int i = 0; i < n; i++)
    {
      int w;
      cin >> w;
      items.push_back({w, i});
    }
    sort(items.begin(), items.end(), greater<pair<int, int>>());

    int found = 0;
    long long sum = 0;
    vector<int> selected;
    for (auto [w, id] : items)
      if (w > capacity) continue;
      else if (sum + w <= capacity)
      {
        sum += w;
        selected.push_back(id);
        if (sum * 2 >= capacity)
        {
          found = 1;
          break;
        }
      }
      else
      {
        selected = {id};
        found = 1;
        break;
      }

    if (!found) cout << "-1\n";
    else
    {
      cout << selected.size() << '\n';
      for (int id : selected)
        cout << id + 1 << ' ';
      cout << '\n';
    }
  }
}