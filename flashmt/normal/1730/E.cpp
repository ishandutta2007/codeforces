#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 27081993;
const int A = 1e6 + 5;

vector<int> divisors[A];
int cnt[A];

// a = [low, mid], b = (mid, high] and max value is in a
long long calc(vector<int> &a, vector<int> &b, function<bool(int, int)> comp)
{
  int na = size(a), nb = size(b);
  int maxL = 0, minL = oo;
  long long res = 0;
  vector<vector<pair<int, int>>> events(nb);
  for (int i = na - 1, jMax = 0, jMin = 0; i >= 0; i--)
  {
    maxL = max(maxL, a[i]);
    minL = min(minL, a[i]);
    while (jMax < nb && comp(b[jMax], maxL))
      jMax++;
    while (jMin < nb && b[jMin] >= minL)
      jMin++;

    // min value is in a
    if (maxL % minL == 0)
      res += min(jMin, jMax);

    // min value is in [jMinx, jMax), count number of divisors of maxL
    if (jMin < jMax)
    {
      events[jMin].push_back({maxL, 1});
      if (jMax < nb)
        events[jMax].push_back({maxL, -1});
    }
  }

  // compute offline
  int minR = oo;
  set<int> allValues;
  for (int i = 0; i < nb; i++)
  {
    minR = min(minR, b[i]);
    sort(begin(events[i]), end(events[i]));
    for (int j = 0; j < size(events[i]);)
    {
      auto [x, _] = events[i][j];
      int jj = j, sumChange = 0;
      while (jj < size(events[i]) && events[i][jj].first == x)
        sumChange += events[i][jj++].second;

      for (int d : divisors[x])
        cnt[d] += sumChange;
      allValues.insert(x);

      j = jj;
    }

    res += cnt[minR];
  }

  // reset cnt
  for (int x : allValues)
    for (int d : divisors[x])
      cnt[d] = 0;

  return res;
}

long long solve(vector<int> &a, int low, int high)
{
  if (low == high)
    return 1;

  int mid = (low + high) / 2;
  vector<int> leftHalf, rightHalf;
  for (int i = low; i <= high; i++)
    if (i <= mid) leftHalf.push_back(a[i]);
    else rightHalf.push_back(a[i]);

  long long res = calc(leftHalf, rightHalf, less_equal<int>());
  reverse(begin(leftHalf), end(leftHalf));
  reverse(begin(rightHalf), end(rightHalf));
  res += calc(rightHalf, leftHalf, less<int>());

  res += solve(a, low, mid) + solve(a, mid + 1, high);
  return res;
}

int main()
{
  for (int i = 1; i < A; i++)
    for (int j = i; j < A; j += i)
      divisors[j].push_back(i);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    cout << solve(a, 0, n - 1) << endl;
  }
}