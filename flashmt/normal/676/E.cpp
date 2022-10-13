#include <bits/stdc++.h>
using namespace std;
const long long oo = (long long)1e14;

int n, k, unknown[100100], cntKnown, cntUnknown;
long long a[100100];

int checkDivisible()
{
  for (int i = n; i; i--)
  {
    a[i - 1] += 1LL * k * a[i];
    if (llabs(a[i - 1]) > oo)
      return 0;
  }
  return !a[0];
}

int checkNonZero()
{
  for (int i = 1; i <= n; i++)
    if (!unknown[i] && a[i])
      return 1;
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> n >> k;
  for (int i = 0; i <= n; i++)
  {
    cin >> s;
    if (s == "?") 
    {
      unknown[i] = 1;
      cntUnknown++;
    }
    else
    {
      int isNegative = 0;
      if (s[0] == '-')
      {
        s.erase(0, 1);
        isNegative = 1;
      }
      for (auto c : s)
        a[i] = a[i] * 10 + c - '0';
      if (isNegative)
        a[i] = -a[i];
      cntKnown++;
    }
  }

  int ans;
  if (!k)
  {
    if (unknown[0]) 
      ans = (cntKnown % 2) && (checkNonZero() || cntUnknown >= 3);
    else 
      ans = !a[0] && (checkNonZero() || (cntKnown % 2 && cntUnknown));
  }
  else if (!cntUnknown)
    ans = checkDivisible();
  else
    ans = n % 2; 

  cout << (ans ? "Yes" : "No") << endl;
}