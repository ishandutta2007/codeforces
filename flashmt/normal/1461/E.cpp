#include <bits/stdc++.h>
using namespace std;

void quit(int hasAns)
{
  cout << (hasAns ? "Yes" : "No") << endl;
  exit(0);
}

int main()
{
  long long k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;

  if (k + y <= r)
    k += y;

  if (l > r - y)
    quit((k - l) / x >= t);

  if (y <= x)
  {
    if (k - x < l)
      quit(0);
    if (x == y)
      quit(1);
    quit((k - x - l) / (x - y) >= t - 1);
  }

  unordered_set<long long> seen;
  int cnt = 0;
  while (cnt < x)
  {
    cnt++;
    if (seen.count(k))
      quit(1);

    seen.insert(k);
    long long canUse = max(0LL, k - r + y);
    long long day = max(1LL, (canUse + x - 1) / x);
    if (day > t)
      quit(1);

    t -= day;
    k -= day * x;
    if (k < l)
      quit(0);
    if (!t)
      quit(1);

    k += y;
    if (k > r)
      quit(0);
  }

  quit(1);
}