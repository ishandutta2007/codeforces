#include <bits/stdc++.h>
using namespace std;

int n, p[100100], can[100100][2];
string f[100100], s[100100];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> f[i] >> s[i];
  for (int i = 1; i <= n; i++) cin >> p[i];
  
  can[1][0] = can[1][1] = 1;
  for (int i = 2; i <= n; i++)
  {
    if (f[p[i]] > f[p[i - 1]]) can[i][0] |= can[i - 1][0];
    if (f[p[i]] > s[p[i - 1]]) can[i][0] |= can[i - 1][1];
    if (s[p[i]] > f[p[i - 1]]) can[i][1] |= can[i - 1][0];
    if (s[p[i]] > s[p[i - 1]]) can[i][1] |= can[i - 1][1];
  }
  
  cout << (can[n][0] || can[n][1] ? "YES" : "NO") << endl;
}