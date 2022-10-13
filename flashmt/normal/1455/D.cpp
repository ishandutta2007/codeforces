#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n;

int solve(vector<int> a, vector<int> b)
{
  int res = 0;
  while (1)
  {
    int found = -1;
    for (int i = 0; i < n; i++)
      if (b[i] != a[i] && b[i] == a[n])
      {
        found = i;
        break;
      }

    if (found < 0)
    {
      for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
          return oo;
      return res;
    }

    if (a[found] < a[n])
      return oo;

    swap(a[found], a[n]);
    res++;
  }

  return oo;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    a[n] = x;

    int ans = oo;
    for (int i = 0; i <= n; i++)
    {
      vector<int> b = a;
      swap(b[n], b[i]);
      sort(b.begin(), b.begin() + n);
      ans = min(ans, solve(a, b));
    }

    cout << (ans == oo ? -1 : ans) << endl;
  }
}