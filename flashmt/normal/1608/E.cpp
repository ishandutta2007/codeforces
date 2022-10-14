#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
typedef pair<int, int> Point;

int n;
// a[0]: sort by x
// a[1]: sort by y
vector<Point> a[2][3];

bool cmpY(Point u, Point v)
{
  return u.second < v.second || (u.second == v.second && u.first < v.first);
}

pair<int, int> findKth(vector<pair<int, int>> &arr, int k, function<bool(int, int)> cond)
{
  for (auto [x, y] : arr)
  {
    k -= cond(x, y);
    if (!k)
      return {x, y};
  }
  return {oo, oo};
}

int isGood(vector<int> c, int k)
{
  // minX maxX
  {
    auto low = a[0][c[0]][k - 1];
    auto high = a[0][c[2]][n / 3 - k];
    int cnt;
    if (low.first == high.first)
    {
      cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.first == low.first && low.second < u.second && u.second < high.second; });
    }
    else
    {
      cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return low.first < u.first && u.first < high.first; });
    }
    if (cnt >= k)
      return 1;
  }

  // minX minY
  {
    int minX = a[0][c[0]][k - 1].first;
    auto [_, minY] = findKth(a[1][c[2]], k, [&](int x, int y) { return x > minX; });
    if (minY != oo)
    {
      int cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.first > minX && u.second > minY; });
      if (cnt >= k)
        return 1;
    }
  }

  // maxX minY
  {
    int maxX = a[0][c[0]][n / 3 - k].first;
    auto [_, minY] = findKth(a[1][c[2]], k, [&](int x, int y) { return x < maxX; });
    if (minY != oo)
    {
      int cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.first < maxX && u.second > minY; });
      if (cnt >= k)
        return 1;
    }
  }

  // minY maxY
  {
    auto low = a[1][c[0]][k - 1];
    auto high = a[1][c[2]][n / 3 - k];
    int cnt;
    if (low.second == high.second)
    {
      cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.second == low.second && low.first < u.first && u.first < high.first; });
    }
    else
    {
      cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return low.second < u.second && u.second < high.second; });
    }
    if (cnt >= k)
      return 1;
  }

  // minY minX
  {
    int minY = a[1][c[0]][k - 1].second;
    auto [minX, _] = findKth(a[0][c[2]], k, [&](int x, int y) { return y > minY; });
    if (minX != oo)
    {
      int cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.first > minX && u.second > minY; });
      if (cnt >= k)
        return 1;
    }
  }

  // maxY minX
  {
    int maxY = a[1][c[0]][n / 3 - k].second;
    auto [minX, _] = findKth(a[0][c[2]], k, [&](int x, int y) { return y < maxY; });
    if (minX != oo)
    {
      int cnt = count_if(begin(a[0][c[1]]), end(a[0][c[1]]), [&](Point u) { return u.first > minX && u.second < maxY; });
      if (cnt >= k)
        return 1;
    }
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    a[0][--c].push_back({x, y});
    a[1][c].push_back({x, y});
  }

  for (int c = 0; c < 3; c++)
  {
    sort(begin(a[0][c]), end(a[0][c]));
    sort(begin(a[1][c]), end(a[1][c]), cmpY);
  }

  int low = 1, high = n / 3, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    vector<int> colors = {0, 1, 2};
    int good = 0;
    do
    {
      if (isGood(colors, mid))
      {
        good = 1;
        break;
      }
    } while (next_permutation(begin(colors), end(colors)));

    if (good)
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  cout << ans * 3 << endl;
}