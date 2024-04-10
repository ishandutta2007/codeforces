#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  string a;
  cin >> n >> a;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] == '*' && a[j] == '*')
      {
        int ok = 1;
        for (int k = 1; k <= 3; k++)
          if (j + k * (j - i) >= n || a[j + k * (j - i)] != '*')
            ok = 0;
        if (ok) 
        {
          cout << "yes";
          return 0;
        }
      }
  cout << "no";
}