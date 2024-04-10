#include <bits/stdc++.h>
using namespace std;

struct Contestant
{
  int s, a, b;

  bool operator <(Contestant u)
  {
    return b - a > u.b - u.a;
  }
} c[100100];

int n, S;

long long calcB(long long pizzaA, long long pizzaB, long long sumSlices)
{
  if (pizzaA < 0 || pizzaB < 0)
    return 0;
  long long res = 0, sliceA = pizzaA * S, sliceB = pizzaB * S, useB = 0;
  for (int i = 0; i < n; i++)
    if (c[i].b > c[i].a)
    {
      long long canUse = min(sliceB - useB, 1LL * c[i].s);
      res += canUse * c[i].b;
      useB += canUse;
      if (useB == sliceB)
        res += (c[i].s - canUse) * c[i].a;
    }
    else
    {
      long long canUse = min(max(0LL, sumSlices - useB - sliceA), 1LL * c[i].s);
      res += canUse * c[i].b;
      useB += canUse;
      if (useB == sliceB || useB + sliceA >= sumSlices)
        res += (c[i].s - canUse) * c[i].a;
    }

  return res;
}

long long calcA(long long pizzaA, long long pizzaB, long long sumSlices)
{
  if (pizzaA < 0 || pizzaB < 0)
    return 0;
  long long res = 0, sliceA = pizzaA * S, sliceB = pizzaB * S, useA = 0;
  for (int i = n - 1; i >= 0; i--)
    if (c[i].a > c[i].b)
    {
      long long canUse = min(sliceA - useA, 1LL * c[i].s);
      res += canUse * c[i].a;
      useA += canUse;
      if (useA == sliceA)
        res += (c[i].s - canUse) * c[i].b;
    }
    else
    {
      long long canUse = min(max(0LL, sumSlices - useA - sliceB), 1LL * c[i].s);
      res += canUse * c[i].a;
      useA += canUse;
      if (useA == sliceA || useA + sliceB >= sumSlices)
        res += (c[i].s - canUse) * c[i].b;
    }

  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> S;
  long long sumSlices = 0, goodA = 0, goodB = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> c[i].s >> c[i].a >> c[i].b;
    sumSlices += c[i].s;
    if (c[i].b > c[i].a)
      goodB += c[i].s;
    if (c[i].a > c[i].b)
      goodA += c[i].s;
  }

  sort(c, c + n);
  long long pizza = (sumSlices + S - 1) / S;
  long long pizzaA = goodA / S;
  long long ans = calcA(pizzaA, pizza - pizzaA, sumSlices);
  ans = max(ans, calcA(pizzaA + 1, pizza - pizzaA - 1, sumSlices));
  long long pizzaB = goodB / S;
  ans = max(ans, calcB(pizza - pizzaB, pizzaB, sumSlices));
  ans = max(ans, calcB(pizza - pizzaB - 1, pizzaB + 1, sumSlices));
  cout << ans << endl;
}