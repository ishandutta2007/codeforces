#include <bits/stdc++.h>
using namespace std;

long long f[100100];

int main()
{
  ios::sync_with_stdio(0);
  int n, cnt[100100] = {0}, x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    cnt[x]++;
  }
  
  f[1] = cnt[1];
  
  for (int i = 2; i <= 100000; i++)
  {
    f[i] = f[i - 1];
    f[i] = max(f[i], f[i - 2] + 1LL * i * cnt[i]);
  }
  
  cout << f[100000] << endl;
}