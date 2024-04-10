#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test, n, a[200200];
  long long s[200200];

  cin >> test;
  while (test--)
  {
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }

    map<long long, int> sumF;
    sumF[0] = 1;
    long long sumAll = 1;
    for (int i = 1; i <= n; i++)
    {
      long long f = sumAll;
      if (sumF.count(s[i - 1]))
        f = (f - sumF[s[i - 1]] + BASE) % BASE;
      sumAll = (sumAll + f) % BASE;
      sumF[s[i] - a[i]] = (sumF[s[i] - a[i]] + f) % BASE;
    }

    cout << sumAll << endl;
  }
}