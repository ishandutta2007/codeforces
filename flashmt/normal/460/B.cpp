#include <bits/stdc++.h>
using namespace std;

int sumDigit(long long x)
{
  return x < 10 ? x : sumDigit(x / 10) + x % 10;
}

int main()
{
  ios::sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  
  vector <long long> ans;
  for (int s = 1; s <= 81; s++)
  {
    long long x = b;
    for (int i = 0; i < a; i++) x *= s;
    x += c;
    
    if (x > 0 && x < 1000000000 && sumDigit(x) == s)
      ans.push_back(x);
  }
  
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < int(ans.size()); i++) cout << ans[i] << ' ';
}