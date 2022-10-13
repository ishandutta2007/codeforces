#include <bits/stdc++.h>
using namespace std;

double power(double a, int b)
{
  if (!b) return 1;
  double res = power(a, b / 2);
  res = res * res;
  if (b % 2) res = res * a;
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;
  double ans = 0, totalProbability = 1;
  for (int i = n; i; i--) 
  {
    double probability = power((i - 1.0) / n, m);
    ans += (totalProbability - probability) * i;
    totalProbability = probability;
  }
  printf("%.6lf\n", ans);
}