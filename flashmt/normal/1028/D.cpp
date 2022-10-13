#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30, BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, maxBuy = 0, minSell = oo;
  long long ans = 1;
  cin >> n;
  set<int> s;
  s.insert(0);
  s.insert(oo);
  while (n--)
  {
    string op;
    int x;
    cin >> op >> x;
    if (op == "ADD") s.insert(x);
    else
    {
      if (x > maxBuy && x < minSell) ans = ans * 2 % BASE;
      else if (x < maxBuy || x > minSell)
      {
        cout << 0 << endl;
        return 0;
      }

      s.erase(x);
      auto it = s.lower_bound(x);
      minSell = *it;
      maxBuy = *(--it);
    }
  }

  int cnt = 0;
  for (int x : s)
    cnt += x > maxBuy && x < minSell;
  ans = ans * (cnt + 1) % BASE;
  cout << ans << endl;
}