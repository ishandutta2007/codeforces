#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a[2020];

int main()
{
  ios::sync_with_stdio(0);
  int x;
  cin >> n;
  for (int i = 1; i <= n; i++) 
  {
    cin >> x;
    a[x].push_back(i);
  }
  
  vector <int> size2;
  for (int i = 1; i <= 2000; i++)
    if (a[i].size() >= 3)
    {
      cout << "YES" << endl;
      for (int k = 0; k < 3; k++)
      {
        for (int j = 0; j <= 2000; j++)
          for (int p = 0; p < int(a[j].size()); p++)
            cout << a[j][p] << ' ';
        cout << endl;
        next_permutation(a[i].begin(), a[i].end());
      }
      return 0;
    }
    else 
      if (a[i].size() == 2)
        size2.push_back(i);
        
  if (size2.size() < 2)
  {
    cout << "NO" << endl;
    return 0;
  }
  
  cout << "YES" << endl;
  for (int k = 0; k < 3; k++)
  {
    for (int j = 0; j <= 2000; j++)
      for (int p = 0; p < int(a[j].size()); p++)
        cout << a[j][p] << ' ';
    cout << endl;
    
    if (!k) swap(a[size2[0]][0], a[size2[0]][1]);
    if (k == 1) swap(a[size2[1]][0], a[size2[1]][1]);
  }
}