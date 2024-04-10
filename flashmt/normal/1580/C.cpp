// to see if mod operation is fast enough to pass

#include <bits/stdc++.h>
using namespace std;
const int K = 450;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  vector<vector<pair<int, int>>> schedules(n);
  vector<int> active(n, -1), total(m), match(m);
  vector<pair<int, int>> q;
  for (int i = 0, cntTotal = 0; i < m; i++)
  {
    int op, k;
    cin >> op >> k;
    k--;
    if (active[k] < 0)
    {
      active[k] = i;
      cntTotal++;
    }
    else
    {
      match[active[k]] = i;
      match[i] = active[k];
      schedules[k].push_back({active[k], i});
      active[k] = -1;
      cntTotal--;
    }
    total[i] = cntTotal;
    q.push_back({op, k});
  }
  for (int i = 0; i < n; i++)
    if (active[i] >= 0)
      schedules[i].push_back({active[i], m});

  vector<int> ans(m * 2);
  // long period
  for (int i = 0; i < n; i++)
    if (x[i] + y[i] >= K)
      for (auto [from, to] : schedules[i])
        while (from < to)
        {
          ans[from]++;
          ans[min(from + x[i], to)]--;
          from += x[i] + y[i];
        }

  for (int i = 1; i < m; i++)
    ans[i] += ans[i - 1];

  // short period
  vector<vector<int>> shortCnt(K + 1, vector<int>(K + 1));

  for (int i = 0; i < m; i++)
  {
    auto [op, id] = q[i];

    int period = x[id] + y[id];
    if (period < K)
    {
      if (op == 1)
      {
        int from = i % period;
        for (int j = 0; j < x[id]; j++)
        {
          shortCnt[period][from++]++;
          if (from == period)
            from = 0;
        }
      }
      else
      {
        int from = match[i] % period;
        for (int j = 0; j < x[id]; j++)
        {
          shortCnt[period][from++]--;
          if (from == period)
            from = 0;
        }
      }
    }

    int curAns = ans[i];
    for (int j = 2; j < K; j++)
      curAns += shortCnt[j][i % j];

    cout << total[i] - curAns << '\n';
  }
}