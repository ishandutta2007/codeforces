#include <bits/stdc++.h>
using namespace std;

int p[6], n, k, ans, total;

void att(int z)
{
  if (z == k)
  {
    total++; 
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        ans += p[i] > p[j];
    return;
  }
  
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
    {
      reverse(p + i, p + j + 1);
      att(z + 1);
      reverse(p + i, p + j + 1);      
    }
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  att(0);
  cout << fixed << setprecision(12) << 1. * ans / total << endl;
}