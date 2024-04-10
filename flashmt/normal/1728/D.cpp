#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const string ANS[] = {"Bob", "Draw", "Alice"};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s;
    cin >> s;
    int n = size(s);
    vector<vector<int>> f(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= n; i++)
      f[i][i] = 0;

    auto get = [&](int u, int v, int nextF)
    {
      if (nextF) return nextF;
      if (s[u] == s[v]) return 0;
      return s[u] < s[v] ? 1 : -1;
    };

    for (int len = 2; len <= n; len += 2)
      for (int i = 0; i + len <= n; i++)
      {
        int j = i + len;
        f[i][j] = min(get(i, i + 1, f[i + 2][j]), get(i, j - 1, f[i + 1][j - 1]));
        f[i][j] = max(f[i][j], min(get(j - 1, i, f[i + 1][j - 1]), get(j - 1, j - 2, f[i][j - 2])));
      }

    cout << ANS[f[0][n] + 1] << endl;
  }
}