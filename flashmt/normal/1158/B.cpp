#include <bits/stdc++.h>
using namespace std;

string solve(int n, int k)
{
  string ans = string(n, '0');
  if (k == n)
    return ans;

  int dif = (n - k) / 2;
  for (int i = 0; i < n; i++)
    if (i % (dif + 1) == dif)
      ans[i] = '1';

  return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
}