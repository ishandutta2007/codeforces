#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a, int b, vector<int> &p, vector<int> &q)
{
  p.clear();
  q.clear();
  for (int i = n; i; i--)
    if (a >= i)
    {
      p.push_back(i);
      a -= i;
    }
    else if (b >= i)
    {
      q.push_back(i);
      b -= i;
    }
    else return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  int low = 0, high = 7e5, ans = 0;
  vector<int> p, q;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (solve(mid, a, b, p, q))
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  solve(ans, a, b, p, q);
  cout << p.size() << '\n';
  for (int x : p)
    cout << x << ' ';
  cout << '\n' << q.size() << '\n';
  for (int x : q)
    cout << x << ' ';
}