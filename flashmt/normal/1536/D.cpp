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
    int n, ans = 1, last;
    cin >> n >> last;
    set<int> s = {last};
    for (int i = 1; i < n; i++)
    {
      int x, isGood = 0;
      cin >> x;
      s.insert(x);
      if (x != last)
      {
        auto it = s.lower_bound(last);
        if (it != s.begin())
          isGood |= *prev(it) == x;
        it++;
        if (it != s.end())
          isGood |= *it == x;
        last = x;
        ans &= isGood;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}