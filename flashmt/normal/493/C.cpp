#include <bits/stdc++.h>
using namespace std;
const int oo = 2000111000;

int m, n, a[200200], b[200200];

pair <int,int> calc(int D)
{
  int i = upper_bound(a, a + n, D) - a;
  int j = upper_bound(b, b + m, D) - b;
  return make_pair((n * 3 - i) - (m * 3 - j), n * 3 - i);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  
  sort(a, a + n);
  sort(b, b + m);
  
  pair <int,int> ans(-oo, -oo);
  for (int i = 0; i < n; i++) ans = max(ans, calc(a[i]));
  for (int i = 0; i < m; i++) ans = max(ans, calc(b[i]));
  ans = max(ans, calc(0));
  ans = max(ans, calc(oo));
  
  cout << ans.second << ':' << ans.second - ans.first << endl;
}