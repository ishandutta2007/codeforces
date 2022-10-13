#include <bits/stdc++.h>
using namespace std;
const int A = 100100;

int main()
{
  vector<vector<int>> d(A);
  for (int i = 1; i < A; i++)
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0)
      {
        d[i].push_back(j);
        if (j * j < i)
          d[i].push_back(i / j);
      }

  vector<tuple<int, int, int>> triples;
  for (int i = 1; i < 8; i++)
    for (int j = i; j < 8; j++)
      for (int k = j; k < 8; k++)
      {
        vector<int> id = {i, j, k};
        int found = 0;
        do
        {
          int isGood = 1;
          for (int p = 0; p < 3; p++)
            isGood &= id[p] >> p & 1;
          found |= isGood;
        } while (next_permutation(begin(id), end(id)));
        if (found)
          triples.push_back({i, j, k});
      }

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  vector<int> mask(A);
  while (test--)
  {
    vector<int> a(3), allD;
    for (int i = 0; i < 3; i++)
    {
      cin >> a[i];
      for (int x : d[a[i]])
      {
        if (!mask[x])
          allD.push_back(x);
        mask[x] |= 1 << i;
      }
    }

    vector<long long> cnt(8);
    for (int x : allD)
      cnt[mask[x]]++;

    long long ans = 0;
    for (auto [i, j, k] : triples)
    {
      ans += cnt[i] * cnt[j] * cnt[k];
      if (i == j && j == k)
      {
        ans -= cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6 * 5;
        ans -= cnt[i] * (cnt[i] - 1) * 2;
      }
      else if (i == j) ans -= cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
      else if (j == k) ans -= cnt[j] * (cnt[j] - 1) / 2 * cnt[i];
      else if (i == k) ans -= cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
    }

    cout << ans << '\n';
    for (int x : allD)
      mask[x] = 0;
  }
}