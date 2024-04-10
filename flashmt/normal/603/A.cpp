#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> f(3, vector<int>(2, -oo));
  f[0] = {0, 0};
  for (char c : s)
  {
    auto newF = f;
    for (int i : {0, 1, 2})
      for (int j : {0, 1})
        for (int ii = i; ii <= min(i + 1, 2); ii++)
        {
          int jj = c - '0';
          if (ii == 1)
            jj ^= 1;
          if (jj != j)
            newF[ii][jj] = max(newF[ii][jj], f[i][j] + 1);
        }

    swap(f, newF);
  }

  int ans = -oo;
  for (int i : {1, 2})
    for (int j : {0, 1})
      ans = max(ans, f[i][j]);
  cout << ans << endl;
}