#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  pair <int, int> a[5050];
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  
  sort(a, a + n);
  int day = 0;
  for (int i = 0; i < n; i++)
    if (a[i].second >= day) day = a[i].second;
    else if (a[i].first >= day) day = a[i].first;
    else 
    {
      cout << a[n - 1].first << endl;
      return 0;
    }
    
  cout << day << endl;
}