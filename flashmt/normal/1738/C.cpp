#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int n, f[111][111][2];

int win(int even, int odd, int sum)
{
  int &res = f[even][odd][sum];
  if (res >= 0)
    return res;

  int turn = (n - even - odd) % 2;

  if (!even && !odd)
    return sum == turn;

  res = 0;
  if (even && !win(even - 1, odd, sum))
    res = 1;
  if (odd && !win(even, odd - 1, sum ^ (turn == 0)))
    res = 1;
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
    cin >> n;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      cnt[abs(x) % 2]++;
    }

    memset(f, -1, sizeof f);
    cout << (win(cnt[0], cnt[1], 0) ? "Alice" : "Bob") << endl;
  }
}