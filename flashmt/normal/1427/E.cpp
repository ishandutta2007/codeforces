#include <bits/stdc++.h>
using namespace std;

struct Op
{
  long long x, y;
  char op;
};

vector<Op> ans;

int getLargestBit(long long x)
{
  for (int i = 60; i >= 0; i--)
    if (x >> i & 1)
      return i;
  return -1;
}

void write(long long x, long long p)
{
  int largestBit = getLargestBit(p);
  for (int i = 0; i < largestBit; i++)
    ans.push_back({x << i, x << i, '+'});
  long long cur = x << largestBit;
  for (int i = largestBit - 1; i >= 0; i--)
    if (p >> i & 1)
    {
      ans.push_back({cur, x << i, '+'});
      cur += x << i;
    }
}

long long gcd(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int main()
{
  long long x;
  cin >> x;
  int largestBit = getLargestBit(x);
  write(x, 1 << largestBit);

  ans.push_back({x << largestBit, x, '^'});
  long long y = (x << largestBit) ^ x; // gcd(x, y) = 1
  long long a, b;
  assert(gcd(x, y, a, b) == 1);
  if (a < 0) a = -a;
  else b = -b;

  write(x, a);
  write(y, b);
  long long xa = x * a, yb = y * b;
  if ((xa ^ yb) != 1)
  {
    ans.push_back({xa, x, '+'});
    xa += x;
    ans.push_back({yb, x, '+'});
    yb += x;
  }
  assert((xa ^ yb) == 1);
  ans.push_back({xa, yb, '^'});

  cout << ans.size() << endl;
  for (auto [x, y, op] : ans)
    cout << x << ' ' << op << ' ' << y << endl;
}