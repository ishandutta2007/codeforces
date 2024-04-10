#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s, t;
  long long k;
  cin >> n >> k >> s >> t;
  
  long long ans = 0, dif = 0;
  for (int i = 0; i < n; i++)
  {
    dif = dif * 2 + t[i] - s[i];
    ans += min(dif + 1, k);
    dif = min(dif, 1LL << 60);
  }
  cout << ans << endl;
}