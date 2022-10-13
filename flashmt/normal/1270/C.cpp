#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long sum = 0, sumXor = 0;
    while (n--)
    {
      int x;
      cin >> x;
      sum += x;
      sumXor ^= x;
    }
    cout << "2\n" << sumXor << ' ' << sum + sumXor << '\n';
  }
}