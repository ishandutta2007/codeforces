#include <bits/stdc++.h>
using namespace std;

int n, p, press[100100];
string s;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> p >> s;
  p--;
  int ans = 0;
  
  vector <int> a;
  for (int i = 0; i < n - 1 - i; i++)
    if (s[i] != s[n - 1 - i])
    {
      int dist = abs(s[i] - s[n - 1 - i]);
      ans += min(dist, 26 - dist);
      if (p <= n - 1 - p) a.push_back(i);
      else a.push_back(n - 1 - i);
    }
  sort(a.begin(), a.end());
    
  if (!a.empty())
  {
    int minId = a[0], maxId = a.back();
    if (maxId <= p) ans += p - minId;
    else if (minId >= p) ans += maxId - p;
    else ans += maxId - minId + min(maxId - p, p - minId);
  }
  cout << ans << endl;
}