#include <bits/stdc++.h>
using namespace std;
const int Z = 400000;

int n, L, a[200200], b[200200], cnt[800800];

int getDist(int i, int j)
{
  return min(abs(a[i] - b[j]), L - abs(a[i] - b[j]));
}

// 0: left, 1: right
int side(int root, int dist, int x)
{
  return (root <= x && x <= root + dist) || (root <= x + L && x + L <= root + dist);
}

// 1 if x is to the left of y
int compare(int root, int dist, int x, int y)
{
  int sideX = side(root, dist, x), sideY = side(root, dist, y);
  if (sideX != sideY)
    return sideX < sideY;
  if (sideX)
    return (x - root + L) % L < (y - root + L) % L;
  return (root - x + L) % L > (root - y + L) % L;
}

int isGood(int dist)
{
  memset(cnt, 0, sizeof cnt);
  // init l, r
  int l = -1, r = -1;
  for (int j = 0; j < n; j++)
    if (getDist(0, j) <= dist)
    {
      if (l < 0 || compare(a[0], dist, b[j], b[l]))
        l = j;
      if (r < 0 || compare(a[0], dist, b[r], b[j]))
        r = j;
    }

  if (l < 0 || r < 0)
    return 0;
  if (l > r)
    l -= n;
  cnt[l + Z]++;
  cnt[r + 1 + Z]--;


  for (int i = 1; i < n; i++)
  {
    // find new l
    int iter = 0;
    while (getDist(i, (l + n) % n) > dist)
    {
      l++;
      if (++iter >= n)
        return 0;
    }
    // find new r
    while (1)
    {
      int sideR = side(a[i], dist, b[r % n]);
      if (side(a[i], dist, b[(r + 1) % n]) < sideR)
        break;
      if (getDist(i, (r + 1) % n) <= dist) r++;
      else break;
    }
    if (getDist(i, r % n) > dist)
      return 0;
    // update cnt
    cnt[l - i + Z]++;
    cnt[r - i + 1 + Z]--;
  }

  for (int i = 1; i <= Z * 2; i++)
  {
    cnt[i] += cnt[i - 1];
    if (cnt[i] == n)
      return 1;
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> L;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  sort(b, b + n);

  int low = 0, high = L / 2, ans = L / 2;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  cout << ans << endl;
}