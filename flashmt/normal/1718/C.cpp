#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    cin >> n >> q;
    vector<int> divisors = {1};
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0)
      {
        divisors.push_back(i);
        if (i * i < n)
          divisors.push_back(n / i);
      }

    int numD = 1;
    sort(rbegin(divisors), rend(divisors));
    for (int i = 1; i < size(divisors); i++)
    {
      int isGood = 1;
      for (int j = 0; j < numD; j++)
        if (divisors[j] % divisors[i] == 0)
          isGood = 0;
      if (isGood)
        divisors[numD++] = divisors[i];
    }
    divisors.resize(numD);

    vector<vector<long long>> sum(numD);
    set<pair<long long, int>> s;
    for (int i = 0; i < numD; i++)
    {
      sum[i].assign(divisors[i], 0);
      for (int j = 0; j < divisors[i]; j++)
        s.insert({0, i * N + j});
    }

    vector<int> a(n);
    auto update = [&](int p, int x)
    {
      for (int i = 0; i < numD; i++)
      {
        int d = divisors[i], j = p % d;
        s.erase({sum[i][j], i * N + j});
        sum[i][j] += 1LL * (x - a[p]) * d;
        s.insert({sum[i][j], i * N + j});
      }
      a[p] = x;
    };

    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      update(i, x);
    }

    for (int i = 0; i <= q; i++)
    {
      cout << rbegin(s)->first << '\n';
      if (i < q)
      {
        int p, x;
        cin >> p >> x;
        update(p - 1, x);
      }
    }
  }
}