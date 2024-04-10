#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    long long a, b;
    cin >> a >> b;
    if (a > b + 1) cout << "NO" << endl;
    else
    {
      int isPrime = 1;
      for (int i = 2; 1LL * i * i <= a + b; i++)
        if ((a + b) % i == 0)
          isPrime = 0;
      cout << (isPrime ? "YES" : "NO") << endl;
    }
  }
}