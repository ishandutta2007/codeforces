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
    int w, l;
    cin >> w >> l;

    set<int> ans = {1, 2};
    auto solve = [&](int w, int l)
    {
      for (int i = 1; i * i <= w; i++)
        if (w % i == 0)
        {
          if (l % i == 0)
            ans.insert(i);
          if (l % (w / i) == 0)
            ans.insert(w / i);
        }
    };

    for (int i = 0; i < 3; i++)
      solve(w - i, l - 2 + i);

    cout << size(ans);
    for (int x : ans)
      cout << ' ' << x;
    cout << endl;
  }
}