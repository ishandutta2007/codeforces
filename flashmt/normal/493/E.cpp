#include <bits/stdc++.h>
using namespace std;

vector <long long> convert(long long a, long long b)
{
  vector <long long> coefficients;
  while (b > 0)
  {
    coefficients.push_back(b % a);
    b /= a;
  }
  return coefficients;
}

int main()
{
  ios::sync_with_stdio(0);
  long long t, a, b;
  cin >> t >> a >> b;
  
  if (t != 1)
  {
    int ans = (b == a);
    if (a != 1) ans += convert(a, b) == convert(t, a);
    cout << ans << endl;
  }
  else
  {
    if (a == 1) cout << (b == 1 ? "inf" : "0") << endl;
    else
    {
      vector <long long> coefficients = convert(a, b);
      long long sumCoefficient = 0;
      for (int i = 0; i < int(coefficients.size()); i++)
        sumCoefficient += coefficients[i];
      if (sumCoefficient == 1 && coefficients.size() > 2) sumCoefficient *= a;
      cout << (sumCoefficient == a) + (a == b) << endl;
    }
  }
}