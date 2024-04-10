#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long a[100100];
  string s;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> s;

  int hasWater = 0;
  long long ans = 0, stamina = 0, grassToConvert = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'L')
    {
      stamina -= a[i];
      ans += a[i];
      if (stamina < 0)
      {
        if (hasWater) ans -= stamina * 3;
        else ans -= stamina * 5;
        stamina = 0;
      }
    }
    else if (s[i] == 'W')
    {
      stamina += a[i];
      ans += a[i] * 3;
      hasWater = 1;
    }
    else
    {
      stamina += a[i];
      ans += a[i] * 5;
      grassToConvert += a[i] * 2;
    }
    grassToConvert = min(grassToConvert, stamina);
  }

  if (stamina > 0)
    ans -= grassToConvert * 2 + stamina - grassToConvert;

  cout << ans << endl;
}