#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, total = 0;
  multiset<int> s[30];
  long long sum[30] = {0};
  cin >> q;
  while (q--)
  {
    char op;
    int x;
    cin >> op >> x;

    int id = 31 - __builtin_clz(x);
    if (op == '+')
    {
      s[id].insert(x);
      sum[id] += x;
      total++;
    }
    else
    {
      s[id].erase(s[id].find(x));
      sum[id] -= x;
      total--;
    }

    int ans = total;
    long long sumSmaller = 0;
    for (int i = 0; i < 30; i++)
    {
      if (!s[i].empty())
        ans -= *s[i].begin() > 2 * sumSmaller;
      sumSmaller += sum[i];
    }
    cout << ans << '\n';
  }
}