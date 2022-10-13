#include <bits/stdc++.h>
using namespace std;
const int A = 1e6 + 5;
const int oo = 1 << 30;

int sieve[A];

vector<pair<int, int>> factorize(int x)
{
  vector<pair<int, int>> res;
  while (sieve[x])
  {
    int p = sieve[x], deg = 0;
    for (; x % p == 0; x /= p)
      deg++;
    res.push_back({p, deg});
  }
  if (x > 1)
    res.push_back({x, 1});
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  string b;
  cin >> b;
  b = " " + b;

  for (int i = 2; i * i < A; i++)
    if (!sieve[i])
      for (int j = i * i; j < A; j += i)
        sieve[j] = i;

  vector<vector<pair<int, int>>> v(A, vector<pair<int, int>>(1, {0, 0}));
  vector<vector<pair<int, int>>> factors(n + 1);
  vector<int> curV(A, 0);
  for (int i = 1; i <= n; i++)
  {
    auto curFactors = factorize(a[i]);
    for (auto [p, deg] : curFactors)
    {
      if (b[i] == '*') curV[p] += deg;
      else curV[p] -= deg;
      v[p].push_back({i, curV[p]});
      factors[i].push_back({p, curV[p]});
    }
  }

  auto getV = [&](int i, int p)
  {
    int id = upper_bound(begin(v[p]), end(v[p]), make_pair(i, oo)) - begin(v[p]);
    return v[p][id - 1].second;
  };

  vector<int> st = {0};
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (b[i] == '*')
    {
      ans += size(st);
      st.push_back(i);
    }
    else
    {
      for (auto [p, curV] : factors[i])
        while (!empty(st) && getV(st.back(), p) > curV)
          st.pop_back();
      ans += size(st);
      st.push_back(i);
    }

  cout << ans << endl;
}