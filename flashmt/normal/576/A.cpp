#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  vector <int> ans;
  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    int isPrime = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
        isPrime = 0;
    if (isPrime)
    {
      int x = i;
      while (x <= n)
      {
        ans.push_back(x);
        x *= i;
      }
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans) 
    cout << x << ' ';
}