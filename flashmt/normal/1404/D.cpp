#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0)
  {
    cout << "First" << endl;
    for (int i = 0; i < n * 2; i++)
      cout << i % n + 1 << " \n"[i == n * 2 - 1];
    cout.flush();
  }
  else
  {
    cout << "Second" << endl;
    vector<vector<int>> pairs(n), idPairs(n);
    for (int i = 1; i <= n * 2; i++)
    {
      int p;
      cin >> p;
      pairs[--p].push_back(i);
      idPairs[i % n].push_back(p);
    }

    vector<int> flagValue(n), flagPair(n), ans(n);
    // Find a way to get a multiple of n
    for (int i = 0; i < n; i++)
      if (!flagValue[i])
      {
        int x = i;
        vector<int> cycle;
        while (!flagValue[x])
        {
          flagValue[x] = 1;
          int curPair = -1;
          for (int p : idPairs[x])
            if (!flagPair[p])
              curPair = p;
          assert(curPair >= 0);

          flagPair[curPair] = 1;
          if (pairs[curPair][0] % n != x)
            ans[curPair] = 1;
          x = pairs[curPair][ans[curPair] ^ 1] % n;
        }
      }

    long long sum = 0;
    for (int i = 0; i < n; i++)
      sum += pairs[i][ans[i]];
    if (sum % (n * 2) == n) // just flip it all
      for (int &x : ans)
        x ^= 1;

    for (int i = 0; i < n; i++)
      cout << pairs[i][ans[i]] << " \n"[i == n - 1];
    cout.flush();
  }

  int resp;
  cin >> resp;
}