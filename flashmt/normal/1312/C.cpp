#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, k, hasAns = 1;
    cin >> n >> k;
    vector<int> flag(100, 0);
    while (n--)
    {
      long long x;
      cin >> x;
      int id = 0;
      while (x)
      {
        if (x % k == 1) flag[id]++;
        else if (x % k) hasAns = 0;
        id++;
        x /= k;
      }
    }

    for (int x : flag)
      hasAns &= x <= 1;
    cout << (hasAns ? "YES" : "NO") << endl;
  }
}