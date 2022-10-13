#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  int n, a[100000];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n - 2; i++)
    if (a[i] + a[n - 2] > a[n - 1])
    {
      cout << "YES" << endl;
      cout << a[i] << ' ';
      for (int j = 0; j < n; j++)
        if (j != i)
          cout << a[j] << ' ';
      return 0;  
    }
    
  cout << "NO" << endl;
}