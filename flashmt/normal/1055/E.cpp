#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, m, k, a[1515];
vector<pair<int, int>> segments;

int isGood(int x)
{
  int sumA[1515] = {0}, f[1515][1515] = {0}, maxF[1515][1515] = {0};
  for (int i = 1; i <= n; i++)
    sumA[i] = sumA[i - 1] + (a[i] <= x);

  int lastR = 0;
  for (int i = 0; i < segments.size(); i++)
  {
    auto [l, r] = segments[i];
    int ii = -1;
    for (int j = 0; j < i; j++)
      if (segments[j].second >= l)
        if (ii < 0 || segments[j].first < segments[ii].first)
          ii = j;

    for (int j = 1; j <= m; j++)
    {
      if (ii >= 0)
        f[i][j] = max(f[i][j], f[ii][j - 1] + sumA[r] - sumA[segments[ii].second]);
      f[i][j] = max(f[i][j], maxF[l - 1][j - 1] + sumA[r] - sumA[l - 1]);

      for (int p = lastR + 1; p <= r; p++)
      {
        maxF[p][j] = maxF[p - 1][j];
        if (p == r)
          maxF[p][j] = max(maxF[p][j], f[i][j]);
      }
    }

    lastR = r;
  }

  for (int i = 1; i <= m; i++)
    if (maxF[lastR][i] >= k)
      return 1;

  return 0;
}

int main()
{
  int s;
  cin >> n >> s >> m >> k;
  vector<int> allA;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    allA.push_back(a[i]);
  }
  while (s--)
  {
    int l, r;
    cin >> l >> r;
    segments.push_back({l, r});
  }

  sort(allA.begin(), allA.end());
  int numA = unique(allA.begin(), allA.end()) - allA.begin();
  allA.resize(numA);

  sort(segments.begin(), segments.end());
  int numSeg = 1;
  for (int i = 1; i < segments.size(); i++)
    if (segments[i].first == segments[numSeg - 1].first) segments[numSeg - 1] = segments[i];
    else if (segments[i].second > segments[numSeg - 1].second) segments[numSeg++] = segments[i];
  segments.resize(numSeg);

  int low = 0, high = numA - 1, ans = numA;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(allA[mid]))
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << (ans < numA ? allA[ans] : -1) << endl;
}