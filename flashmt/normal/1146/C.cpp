#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int test, n;
  cin >> test;
  while (test--)
  {
    cin >> n;
    
    int maxDist = 0, dist;
    for (int i = 0; i < 8; i++)
    {
      vector <int> s[2];
      for (int j = 0; j < n; j++)
        s[j >> i & 1].push_back(j + 1);
      if (s[0].empty() || s[1].empty())
        continue;

      cout << s[0].size() << ' ' << s[1].size();
      for (int j = 0; j < 2; j++)
        for (int x : s[j])
          cout << ' ' << x;
      cout << endl;
      fflush(stdout);
      cin >> dist;
      if (dist < 0)
        return 0;
      maxDist = max(maxDist, dist);
    }

    cout << "-1 " << maxDist << endl;
    fflush(stdout);
  }
}