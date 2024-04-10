#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

int a[100100], minValue[100100][20], cntMin[100100][20], gcd[100100][20], n, lg2[200100];

int main()
{
  ios::sync_with_stdio(0);
  int Q, l, r;
  
  cin >> n;
  for (int i = 1; i <= n; i++) 
  {
    cin >> a[i];
    minValue[i][0] = a[i];
    cntMin[i][0] = 1;
    if (i > 1) gcd[i - 1][0] = abs(a[i] - a[i - 1]);
  }
  
  for (int j = 1; j <= 16; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
    {
      int ii = i + (1 << (j - 1));
      minValue[i][j] = min(minValue[i][j - 1], minValue[ii][j - 1]);
      if (minValue[i][j] == minValue[i][j - 1]) cntMin[i][j] += cntMin[i][j - 1];
      if (minValue[i][j] == minValue[ii][j - 1]) cntMin[i][j] += cntMin[ii][j - 1];
      if (i + (1 << j) - 1 < n) 
        gcd[i][j] = __gcd(gcd[i][j - 1], gcd[ii][j - 1]);
    }
    
  for (int i = 0, j = 1; i <= 16; i++)
    while (j < 1 << (i + 1))
      lg2[j++] = i;
    
  cin >> Q;
  while (Q--)
  {
    cin >> l >> r;
    if (l == r)
    {
      cout << 0 << '\n';
      continue;
    }
    
    int curMinValue = oo, curCntMin = 0;
    for (int lg = 16, i = l; lg >= 0; lg--)
      if (i + (1 << lg) - 1 <= r)
      {
        if (minValue[i][lg] < curMinValue)
        {
          curMinValue = minValue[i][lg];
          curCntMin = cntMin[i][lg];
        }
        else if (minValue[i][lg] == curMinValue)
          curCntMin += cntMin[i][lg];
        i += 1 << lg;
      }
    
    int lg = lg2[r - l], curGcd = __gcd(gcd[l][lg], gcd[r - (1 << lg)][lg]);
    cout << (r - l + 1) - (curGcd % curMinValue == 0 ? curCntMin : 0) << '\n';
  }
}