#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long oo = 1LL << 60;

long long a[N];
int bitA[N];

// a = [low, mid], b = (mid, high] and max value is in a
long long calc(
  vector<pair<long long, int>> &a,
  vector<pair<long long, int>> &b,
  function<bool(long long, long long)> comp
) {
  int na = size(a), nb = size(b);
  pair<long long, int> maxL(-oo, 0), minL(oo, 0);
  vector<vector<pair<int, int>>> events(nb);
  long long res = 0;
  for (int i = na - 1, jMax = 0, jMin = 0; i >= 0; i--)
  {
    maxL = max(maxL, a[i]);
    minL = min(minL, a[i]);
    while (jMax < nb && comp(b[jMax].first, maxL.first))
      jMax++;
    while (jMin < nb && b[jMin] >= minL)
      jMin++;

    // min value is in a
    if (maxL.second == minL.second)
      res += min(jMin, jMax);

    // min value is in [jMin, jMax)
    if (jMin < jMax)
    {
      if (jMin)
        events[jMin - 1].push_back({maxL.second, 0});
      events[jMax - 1].push_back({maxL.second, 1});
    }
  }

  vector<int> cnt(60);
  pair<long long, int> minR(oo, 0);
  for (int i = 0; i < nb; i++)
  {
    minR = min(minR, b[i]);
    cnt[minR.second]++;
    for (auto [bit, op] : events[i])
      if (op) res += cnt[bit];
      else res -= cnt[bit];
  }

  return res;
}

long long solve(int low, int high)
{
  if (low == high)
    return 1;

  int mid = (low + high) / 2;
  vector<pair<long long, int>> leftHalf, rightHalf;
  for (int i = low; i <= mid; i++)
    leftHalf.push_back({a[i], bitA[i]});
  for (int i = mid + 1; i <= high; i++)
    rightHalf.push_back({a[i], bitA[i]});

  long long res = calc(leftHalf, rightHalf, less_equal<long long>());
  reverse(begin(leftHalf), end(leftHalf));
  reverse(begin(rightHalf), end(rightHalf));
  res += calc(rightHalf, leftHalf, less<long long>());

  res += solve(low, mid) + solve(mid + 1, high);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    bitA[i] = __builtin_popcountll(a[i]);
  }

  cout << solve(0, n - 1) << endl;
}