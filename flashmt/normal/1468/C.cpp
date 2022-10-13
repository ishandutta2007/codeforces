#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q, id = 0, money[500500];
  set<int> mono;
  set<pair<int, int>> poly;
  cin >> q;
  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      cin >> money[++id];
      mono.insert(id);
      poly.insert({-money[id], id});
    }
    else
    {
      int x = op == 2 ? *mono.begin() : poly.begin()->second;
      mono.erase(x);
      poly.erase({-money[x], x});
      cout << x << ' ';
    }
  }
}