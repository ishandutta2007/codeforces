#include <bits/stdc++.h>
using namespace std;
const int TURN = 30;

int original[333];

void solve(int id, int turn, int n, int t, int prefixT)
{
  if (id == n)
  {
    original[n] = t - prefixT;
    cout << "! ";
    for (int i = 1; i <= n; i++)
      cout << original[i];
    cout.flush();
    exit(0);
  }

  int t0 = (n - id) - (t - prefixT) + prefixT;
  int t1 = (n - id) - (t - prefixT - 1) + prefixT + 1;
  int found = -1, flipAll = 0;
  // if t0 or t1 happens to be equal to n - t
  int fallback = -1;
  if (t0 == n - t)
    fallback = 0;
  if (t1 == n - t)
    fallback = 1;

  for (int i = 0; i < TURN; i++)
  {
    cout << "? " << id + 1 << ' ' << n << '\n';
    cout.flush();
    int tt;
    cin >> tt;
    if (tt == n - t)
    {
      prefixT = id - 1 - prefixT;
      flipAll ^= 1;
    }
    else if (found < 0)
    {
      assert(tt == t0 || tt == t1);
      if (tt == t0) found = turn;
      else found = turn ^ 1;
    }
    t = tt;
    t0 = (n - id) - (t - prefixT) + prefixT;
    t1 = (n - id) - (t - prefixT - 1) + prefixT + 1;
    turn ^= 1;
  }

  if (found < 0)
  {
    found = fallback;
    prefixT += found;
  }
  else prefixT += found ^ flipAll;
  assert(found >= 0);
  original[id] = found;

  solve(id + 1, turn, n, t, prefixT);
}

int main()
{
  int n, t;
  cin >> n >> t;
  solve(1, 0, n, t, 0);
}