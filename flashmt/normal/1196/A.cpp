#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long c)
{
  if (a + c < b || b + c < a)
    return min(a, b) + c;
  return (a + b + c) / 2;
}

int main()
{
  int q;
  cin >> q;
  while (q--)
  {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << max(max(solve(a, b, c), solve(b, c, a)), solve(c, a, b)) << endl;
  }
}