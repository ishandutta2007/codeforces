#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int N = 44;

int main()
{
  vector<long long> fib(N), sumFib(N);
  fib[0] = fib[1] = 1;
  sumFib[0] = 1;
  sumFib[1] = 2;
  for (int i = 2; i < N; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
    sumFib[i] = sumFib[i - 1] + fib[i];
  }

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<long long> c(n);
    for (auto &x : c)
      cin >> x;
    long long sum = accumulate(begin(c), end(c), 0LL);
    int m = 0;
    while (m < N && sumFib[m] != sum)
      m++;

    if (m >= N)
    {
      cout << "NO\n";
      continue;
    }

    int ans = 1;
    vector<int> last(n, m + 2);
    for (int i = m; i >= 0; i--)
    {
      int id = -1;
      for (int j = 0; j < n; j++)
        if (c[j] >= fib[i] && last[j] > i + 1 && (id < 0 || c[j] > c[id]))
          id = j;

      if (id < 0)
      {
        ans = 0;
        break;
      }
      c[id] -= fib[i];
      last[id] = i;
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}