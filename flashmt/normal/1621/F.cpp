#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

// good0: removing this can create a new 11
// bad0: 0 at border
// start with an op 1 or op 3, greedily try to formulate each step
long long solve1(int good0, int bad0, vector<pair<int, int>> len0, int pair0, int pair1)
{
  long long res = 0, cost = 0;
  int sz = size(len0);
  while (1)
  {
    // check if we can add 1 last op 1
    if (pair0)
      res = max(res, cost + a);

    if (!pair1) // need an op 3 to create a new 11
    {
      if (!good0)
        break;
      cost -= c;
      good0--;
      pair1++;
    }
    else if (pair0) // don't need 11 yet, try op 1
    {
      cost += a;
      pair0--;
      auto [isBad, v] = len0[sz - 1];
      v--;
      if (v) len0[sz - 1].second = v;
      else
      {
        if (isBad) bad0++;
        else good0++;
        sz--;
      }
    }
    else if (good0) // must do op 3 now, try to create new 11
    {
      cost -= c;
      good0--;
      pair1++;
    }
    else if (bad0) // last choice
    {
      cost -= c;
      bad0--;
    }
    else break;

    if (!pair1)
      break;

    cost += b;
    res = max(res, cost);
    pair1--;
  }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string s;
    cin >> n >> a >> b >> c >> s;

    int pair0 = 0, pair1 = 0, good0 = 0, bad0 = 0;
    vector<pair<int, int>> len0;
    for (int i = 0; i < n;)
    {
      int ii = i + 1;
      while (ii < n && s[ii] == s[i])
        ii++;
      int len = ii - i;
      if (s[i] == '1') pair1 += len - 1;
      else
      {
        pair0 += len - 1;
        if (i && ii < n)
        {
          if (len == 1) good0++;
          else len0.push_back({0, len - 1});
        }
        else
        {
          if (len == 1) bad0++;
          else len0.push_back({1, len - 1});
        }
      }
      i = ii;
    }

    long long ans = 0;
    // no op 3
    if (pair0 < pair1) ans = pair0 * a + (pair0 + 1) * b;
    else ans = min(pair0, pair1 + 1) * a + pair1 * b;

    sort(rbegin(len0), rend(len0));
    if (pair1)
      ans = max(ans, solve1(good0, bad0, len0, pair0, pair1 - 1) + b);
    ans = max(ans, solve1(good0, bad0, len0, pair0, pair1));

    cout << ans << '\n';
  }
}