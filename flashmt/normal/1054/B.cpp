#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, last = -1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x > last + 1)
    {
      cout << i + 1 << endl;
      return 0;
    }
    last = max(last, x);
  }
  cout << -1 << endl;
}