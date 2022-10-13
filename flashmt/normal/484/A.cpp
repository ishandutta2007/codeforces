#include <bits/stdc++.h>
using namespace std;

long long calc(long long l, long long r)
{
  long long res = 0;
  for (int i = 60; i >= 0; i--)
    if ((r >> i & 1) && (l >> i & 1 ^ 1))
    {
      int ok = 1;
      for (int j = i - 1; j >= 0; j--)
        if (r >> j & 1 ^ 1)
          ok = 0;
          
      res += (1LL << (i + ok)) - 1;
      return res;
    }
    else res += r & (1LL << i);
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  int test;
  long long l, r;
  cin >> test;
  while (test--)
  {
    cin >> l >> r;
    cout << calc(l, r) << endl;
  }
}