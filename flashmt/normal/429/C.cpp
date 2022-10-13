#include <bits/stdc++.h>
using namespace std;

int main()
{
  int total, leaf = 0;
  cin >> total;
  vector<int> c;
  for (int i = 0; i < total; i++)
  {
    int x;
    cin >> x;
    if (x == 1) leaf++;
    else c.push_back(x);
  }
  int n = size(c);
  sort(begin(c), end(c));

  if (n >= 12)
  {
    cout << "NO" << endl;
    return 0;
  }

  if (total == 1)
  {
    cout << (leaf ? "YES" : "NO") << endl;
    return 0;
  }

  vector<int> sumMask(1 << n);
  for (int mask = 0; mask < 1 << n; mask++)
    for (int i = 0; i < n; i++)
      if (mask >> i & 1)
        sumMask[mask] += c[i];

  vector<vector<int>> f(leaf + 1, vector<int>(1 << n));
  f[leaf][(1 << n - 1) - 1] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    vector<vector<int>> newF(leaf + 1, vector<int>(1 << n));
    for (int j = 0; j <= leaf; j++)
      for (int mask = 0; mask < 1 << i; mask++)
        if (f[j][mask])
          for (int submask = mask;; submask = (submask - 1) & mask)
          {
            int cnt = __builtin_popcount(submask);
            int leafNeeded = c[i] - 1 - sumMask[submask];
            if (leafNeeded >= 0 && leafNeeded <= j && leafNeeded + cnt >= 2)
              newF[j - leafNeeded][mask ^ submask] = 1;
            if (!submask)
              break;
          }

    swap(f, newF);
  }

  cout << (f[0][0] ? "YES" : "NO") << endl;
}