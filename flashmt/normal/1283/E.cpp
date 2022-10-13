#include <bits/stdc++.h>
using namespace std;

int solveMin(vector<int> a)
{
  int last = -1, res = 0;
  for (int x : a)
  {
    int found = 0;
    for (int i = 1; i >= -1; i--)
      if (x + i == last)
      {
        found = 1;
        break;
      }

    if (!found)
    {
      last = x + 1;
      res++;
    }
  }
  return res;
}

int solveMax(vector<int> a)
{
  int last = -1, res = 0;
  for (int x : a)
    for (int i = -1; i <= 1; i++)
      if (x + i > last)
      {
        last = x + i;
        res++;
        break;
      }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  cout << solveMin(a) << ' ' << solveMax(a) << endl;
}