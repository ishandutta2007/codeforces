#include <bits/stdc++.h>
using namespace std;
const int K = 20;

long long n;
int k;

int ask(long long l, long long r)
{
  cout << l << ' ' << r << endl;
  cout.flush();
  string s;
  cin >> s;
  if (s == "Bad")
    exit(0);
  return s == "Yes";
}

void shrink(long long &l, long long &r)
{
  // shrink [l, r] as much as possible
  while (r - l + 1 > K * 2 + 1)
  {
    long long m = (l + r) / 2;
    if (ask(l, m))
    {
      l = max(1LL, l - k);
      r = min(n, m + k);
    }
    else
    {
      l = max(1LL, m + 1 - k);
      r = min(n, r + k);
    }
  }
}

int main()
{
  cin >> n >> k;
  long long l = 1, r = n;
  shrink(l, r);

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (1)
  {
    // try a random guess in [l, r], r - l <= 2k
    long long i = l + rng() % (r - l + 1);
    if (ask(i, i))
      return 0;

    // have to shrink again
    l = max(1LL, l - k);
    r = min(n, r + k);
    shrink(l, r);
  }
}