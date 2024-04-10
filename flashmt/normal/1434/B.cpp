#include <bits/stdc++.h>
using namespace std;

void no()
{
  cout << "NO" << endl;
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100];
  vector<pair<int, int>> ops;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++)
    s.insert(i);
  for (int i = 0, cnt = 0; i < n * 2; i++)
  {
    char c;
    cin >> c;
    if (c == '+')
    {
      cnt++;
      ops.push_back({0, 0});
    }
    else
    {
      int x;
      cin >> x;
      ops.push_back({1, x});
      auto it = s.lower_bound(cnt);
      if (it == s.begin())
        no();
      it--;
      a[*it] = x;
      s.erase(it);
    }
  }

  set<int> items;
  int cnt = 0;
  for (auto [op, x] : ops)
    if (!op) items.insert(a[cnt++]);
    else
    {
      if (items.empty())
        no();
      if (*items.begin() != x)
        no();
      items.erase(x);
    }

  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
}