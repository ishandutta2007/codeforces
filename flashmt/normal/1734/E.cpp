#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int &x : b)
    cin >> x;

  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    vector<int> a(n);
    for (int j = 0; j < n; j++)
      a[j] = (i * j + b[0]) % n;
    for (int j = 0; j < n; j++)
      if (a[j] == b[i])
      {
        rotate(begin(a), begin(a) + (j - i + n) % n, end(a));
        break;
      }
    ans.push_back(a);
  }
  
  for (auto a : ans)
    for (int i = 0; i < n; i++)
      cout << a[i] << " \n"[i == n - 1];
}