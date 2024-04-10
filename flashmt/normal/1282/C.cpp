#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, T, cnt[2] = {0};
    long long timeSolve[2];
    cin >> n >> T >> timeSolve[0] >> timeSolve[1];
    vector<pair<int, int>> p(n, {0, 0});
    for (auto &u : p)
    {
      cin >> u.second;
      cnt[u.second]++;
    }
    for (auto &u : p)
      cin >> u.first;
    sort(p.begin(), p.end());

    int ans = 0, mustSolve[2] = {0};
    for (int i = 0; i < n;)
    {
      int j = i, maySolve[2] = {0};
      while (j < n && p[j].first == p[i].first)
        maySolve[p[j++].second]++;

      long long remain = p[i].first - 1 - mustSolve[0] * timeSolve[0] - mustSolve[1] * timeSolve[1];
      if (remain >= 0)
      {
        int canSolve = mustSolve[0] + mustSolve[1];
        for (int k = 0; k < 2; k++)
        {
          int solve = min(int(remain / timeSolve[k]), cnt[k] - mustSolve[k]);
          remain -= solve * timeSolve[k];
          canSolve += solve;
        }
        ans = max(ans, canSolve);
      }

      mustSolve[0] += maySolve[0];
      mustSolve[1] += maySolve[1];
      i = j;
    }

    if (mustSolve[0] * timeSolve[0] + mustSolve[1] * timeSolve[1] <= T)
      ans = n;

    cout << ans << '\n';
  }
}