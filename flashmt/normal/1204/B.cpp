#include <bits/stdc++.h>
using namespace std;

int solveMin(int n, int k)
{
  int res = 0;
  for (int i = 0; i < k; i++)
    res += 1 << i;
  res += n - k;
  return res;
}

int solveMax(int n, int k)
{
  int res = 0;
  for (int i = 0; i < k; i++)
    res += 1 << i;
  res += n - k << k - 1;
  return res;
}

int main()
{
  int n, l, r;
  cin >> n >> l >> r;
  cout << solveMin(n, l) << ' ' << solveMax(n, r) << endl;
}