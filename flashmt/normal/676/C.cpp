#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int solve(char c)
{
  int a[100100] = {0}, res = 0;
  for (int i = 0; i < n; i++)
    a[i + 1] = a[i] + (s[i] == c);

  for (int i = 1, j = 0; i <= n; i++)
  {
    while (a[i] - a[j] > k)
      j++;
    res = max(res, i - j);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s; 
  cout << max(solve('a'), solve('b')) << endl;
}