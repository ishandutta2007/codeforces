#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

long long calc(vector<long long> &a)
{
  long long minA = 0, maxA = 0, cur = 0;
  for (int x : a)
  {
    cur += x;
    minA = min(minA, cur);
    maxA = max(maxA, cur);
  }
  return maxA - minA + 1;
}

int main()
{
  int n, k;
  while (cin >> n >> k)
  {
    vector<long long> a(n);
    long long sumDist = 0;
    vector<int> ids;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i]) sumDist += a[i];
      else ids.push_back(i);
    }
    int m = size(ids);

    if (sumDist < 0)
    {
      sumDist = -sumDist;
      for (auto &x : a)
        x = -x;
    }

    long long need = (sumDist + k - 1) / k;
    if (need > m)
    {
      cout << -1 << endl;
      continue;
    }

    int remNeg = sumDist % k, remPos = 0;
    auto free = m - need;
    int numPos = free / 2, numNeg = free / 2 + need;
    if (remNeg && free % 2)
    {
      remPos = k - remNeg;
      numPos++;
      remNeg = 0;
    }

    vector<int> cand;
    for (int i = 0; i < numPos; i++)
      if (!i && remPos) cand.push_back(remPos);
      else cand.push_back(k);
    for (int i = 0; i < numNeg; i++)
      if (!i && remNeg) cand.push_back(-remNeg);
      else cand.push_back(-k);
    while (size(cand) < m)
      cand.push_back(0);

    sort(begin(cand), end(cand));
    long long ans = m ? 1 : calc(a);
    for (int turn = 0; turn < 2; turn++)
    {
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < m; j++)
          a[ids[(i + j) % m]] = cand[j];
        ans = max(ans, calc(a));
      }
      reverse(begin(cand), end(cand));
    }

    cout << ans << endl;
  }
}