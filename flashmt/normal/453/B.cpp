#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 58, oo = 27081993;;

int isPrime[100], primes[100], P, n, a[111];
int f[111][1 << 16], maskNumber[100], tr[111][1 << 16];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  for (int i = 2; i <= MAX_A; i++)
  {
    isPrime[i] = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0) isPrime[i] = 0;
      
    if (isPrime[i]) primes[P++] = i;
  }
  
  for (int i = 1; i <= MAX_A; i++)
    for (int j = 0; j < P; j++)
      if (i % primes[j] == 0)
        maskNumber[i] |= 1 << j;
        
  for (int i = 0; i <= n; i++)
    for (int mask = 0; mask < 1 << P; mask++)
      f[i][mask] = oo;
    
  f[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int mask = 0; mask < 1 << P; mask++)
      for (int x = 1; x <= MAX_A; x++)
        if (!(mask & maskNumber[x]))
        {
          int newMask = mask | maskNumber[x];
          if (f[i][newMask] > f[i - 1][mask] + abs(x - a[i]))
          {
            f[i][newMask] = f[i - 1][mask] + abs(x - a[i]);
            tr[i][newMask] = x;
          }
        }
        
  int ans = oo, maskAns = 0;
  for (int mask = 0; mask < 1 << P; mask++) 
    if (f[n][mask] < ans)
    {
      ans = f[n][mask];
      maskAns = mask;
    }
    
  vector <int> b;
  for (int i = n, mask = maskAns; i; i--)
  {
    b.push_back(tr[i][mask]);
    mask = mask ^ maskNumber[b.back()];
  }
  
  for (int i = n - 1; i >= 0; i--) cout << b[i] << ' ';
}