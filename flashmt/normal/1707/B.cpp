#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
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
    cin >> n;
    vector<int> a;
    int zero = 0, last = 1;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      if (!x) zero++;
      else a.push_back(x);
    }

    for (int turn = n - 1; turn && !empty(a); turn--)
    {
      vector<int> b;
      if (zero)
      {
        b.push_back(a[0]);
        zero--;
      }

      for (int i = 1; i < size(a); i++)
        b.push_back(a[i] - a[i - 1]);
      sort(begin(b), end(b));

      int start = 0;
      while (start < size(b) && !b[start])
        start++;
      zero += start;
      b.erase(begin(b), begin(b) + start);
      swap(a, b);
    }

    cout << (empty(a) ? 0 : a[0]) << '\n';
  }
}