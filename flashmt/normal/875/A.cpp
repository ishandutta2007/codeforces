#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int sumDigit(int x)
{
  return x < 10 ? x : sumDigit(x / 10) + x % 10;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 1; i <= 81; i++)
    if (i < n && sumDigit(n - i) == i)
      ans.push_back(n - i);
  reverse(begin(ans), end(ans));
  cout << size(ans) << endl;
  for (int x : ans)
    cout << x << endl;
}