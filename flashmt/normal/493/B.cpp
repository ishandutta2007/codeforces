#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, c[200100];
  long long sumA = 0, sumB = 0;
  vector <int> a, b;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
    
  for (int i = 0; i < n; i++)
    if (c[i] > 0) 
    {
      a.push_back(c[i]);
      sumA += c[i];
    }
    else
    {
      b.push_back(-c[i]);
      sumB -= c[i];
    }
  
  if (sumA != sumB) cout << (sumA > sumB ? "first" : "second") << endl;
  else
  {
    for (int i = 0; i < int(a.size()) && i < int(b.size()); i++)
      if (a[i] != b[i])
      {
        cout << (a[i] > b[i] ? "first" : "second") << endl;
        return 0;
      }
    
    cout << (c[n - 1] < 0 ? "second" : "first") << endl;
  }
}