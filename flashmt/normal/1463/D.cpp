#include <bits/stdc++.h>
using namespace std;

int n, has[400400];

int getMax()
{
  int res = 0;
  for (int i = n * 2 - 1, cnt = 0; i >= 0; i--)
    if (has[i]) cnt++;
    else if (cnt)
    {
      res++;
      cnt--;
    }
  return res;
}

int getMin()
{
  int res = 0;
  for (int i = 0, cnt = 0; i < n * 2; i++)
    if (has[i]) cnt++;
    else if (cnt)
    {
      res++;
      cnt--;
    }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n * 2; i++)
      has[i] = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      has[--x] = 1;
    }
    cout << getMin() - (n - getMax()) + 1 << endl;
  }
}