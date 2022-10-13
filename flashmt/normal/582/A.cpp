#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x;
  multiset <int> g;

  cin >> n;
  for (int i = 0; i < n * n; i++)
  {
    cin >> x;
    g.insert(-x);
  }

  vector <int> ans;
  for (int i = 0; i < n; i++)
  {
    int x = -*g.begin();
    for (auto y : ans)
      for (int j = 0; j < 2; j++)
        g.erase(g.find(-__gcd(x, y)));
    ans.push_back(x);
    g.erase(g.find(-x));
  }

  for (auto x : ans)
    cout << x << ' ';
}