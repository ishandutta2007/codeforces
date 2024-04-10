#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, m, s[5050], f[5050], l[5050], r[5050];
vector<int> id[5050];

// all cows are on right side
pair<int, int> solveOnlyRight(int firstCow)
{
  int res = 1;
  vector<int> cnt(n);
  for (int i = 0; i < m; i++)
    if (f[i] != f[firstCow] && r[i] >= 0 && r[i] > r[firstCow])
      cnt[f[i]]++;

  long long ways = 1;
  for (int x : cnt)
    if (x)
    {
      res++;
      ways = ways * x % BASE;
    }

  return {res, ways};
}

// firstCow is on left side, there may or may not be cows on right side
pair<int, int> solveLeft(int firstCow)
{
  int res = 1;
  vector<int> cntL(n), cntR(n), cntLR(n);
  for (int i = 0; i < m; i++)
    if (f[i] == f[firstCow])
    {
      if (i != firstCow && r[i] > l[firstCow])
        cntR[f[i]]++;
    }
    else
    {
      int canL = l[i] >= 0 && l[i] < l[firstCow];
      int canR = r[i] >= 0 && r[i] > l[firstCow];
      if (canL && canR) cntLR[f[i]]++;
      else if (canL) cntL[f[i]]++;
      else if (canR) cntR[f[i]]++;
    }

  long long ways = 1;
  for (int i = 0; i < n; i++)
  {
    if (!cntL[i] && !cntR[i] && !cntLR[i])
      continue;

    int pairWays = cntLR[i] * (cntL[i] + cntR[i] + cntLR[i] - 1) + cntL[i] * cntR[i];
    if (pairWays)
    {
      res += 2;
      ways = ways * pairWays % BASE;
    }
    else
    {
      res++;
      ways = ways * (cntL[i] + cntR[i] + cntLR[i] * 2) % BASE;
    }
  }

  return {res, ways};
}

void updateAns(pair<int, int> &ans, pair<int, int> u)
{
  if (u.first > ans.first) ans = u;
  else if (u.first == ans.first) ans.second = (ans.second + u.second) % BASE;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    id[--s[i]].push_back(i);
  }

  for (int i = 0; i < m; i++)
  {
    int h;
    cin >> f[i] >> h;
    f[i]--;
    if (id[f[i]].size() >= h)
    {
      l[i] = id[f[i]][h - 1];
      r[i] = id[f[i]][id[f[i]].size() - h];
    }
    else l[i] = r[i] = -1;
  }

  pair<int, int> ans(0, 1);

  // no left cows
  for (int i = 0; i < m; i++)
    if (r[i] >= 0)
      updateAns(ans, solveOnlyRight(i));

  // pick first left cow
  for (int i = 0; i < m; i++)
    if (l[i] >= 0)
      updateAns(ans, solveLeft(i));

  cout << ans.first << ' ' << ans.second << endl;
}