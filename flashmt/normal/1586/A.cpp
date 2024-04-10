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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    auto isPrime = [&](int x)
    {
      for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
          return 0;
      return 1;
    };

    int sum = accumulate(begin(a), end(a), 0);
    int bad = -1;
    if (isPrime(sum))
      for (int i = 0; i < n; i++)
        if (!isPrime(sum - a[i]))
        {
          bad = i;
          break;
        }

    cout << n - (bad >= 0) << '\n';
    for (int i = 0; i < n; i++)
      if (i != bad)
        cout << i + 1 << ' ';
    cout << endl;
  }
}