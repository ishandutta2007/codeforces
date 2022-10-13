#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  vector<int> id[111];
  cin >> n >> k;
  vector<int> a(n * k);
  for (int i = 0; i < n * k; i++)
  {
    cin >> a[i];
    id[--a[i]].push_back(i);
  }

  vector<int> curL(n);
  for (int i = 0; i < n; i += k - 1)
  {
    vector<int> cand;
    for (int j = 0; j < k - 1; j++)
      if (i + j < n)
        cand.push_back(i + j);

    vector<int> active = {cand[0]};
    for (int j = 1; j < size(cand); j++)
    {
      int color = cand[j];
      active.push_back(color);
      while (1)
      {
        int found = -1;
        for (int other : active)
          if (other != color)
          {
            int l = id[color][curL[color]], r = id[color][curL[color] + 1];
            int ll = id[other][curL[other]], rr = id[other][curL[other] + 1];
            if (max(l, ll) < min(r, rr))
            {
              if (r > rr) found = color;
              else found = other;
              curL[found]++;
              assert(curL[found] + 1 < k);
              break;
            }
          }

        if (found < 0)
          break;

        color = found;
        sort(begin(active), end(active), [&](int u, int v) { return id[u][curL[u]] < id[v][curL[v]]; });
      }

      sort(begin(active), end(active), [&](int u, int v) { return id[u][curL[u]] < id[v][curL[v]]; });
      for (int p = 0; p + 1 < size(active); p++)
      {
        int u = active[p], v = active[p + 1];
        assert(id[u][curL[u] + 1] < id[v][curL[v]]);
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << id[i][curL[i]] + 1 << ' ' << id[i][curL[i] + 1] + 1 << endl;
}