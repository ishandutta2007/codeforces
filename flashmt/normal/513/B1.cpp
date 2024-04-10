#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, a[55];
  long long k;
  cin >> n >> k;
  
  for (int i = 1, l = 1, r = n; i <= n; i++)
    if (k <= 1LL << (n - i - 1)) a[l++] = i;
    else
    {
      a[r--] = i;
      k -= 1LL << (n - i - 1);
    }
  
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
}