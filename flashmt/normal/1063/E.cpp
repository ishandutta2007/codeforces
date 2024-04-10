#include <bits/stdc++.h>
using namespace std;

int n, a[1010];
string ans[1010];

vector<vector<int>> findAllCycles()
{
  int flag[1010] = {0};
  vector<vector<int>> cycles;
  for (int i = 0; i < n; i++)
    if (!flag[i])
    {
      int x = i;
      vector<int> cycle;
      while (!flag[x])
      {
        flag[x] = 1;
        cycle.push_back(x);
        x = a[x];
      }
      if (cycle.size() > 1)
        cycles.push_back(cycle);
    }

  return cycles;
}

void solveFirstCycle(vector<int> cycle, int &row)
{
  for (int i = int(cycle.size()) - 1; i; i--)
  {
    int x = cycle[i - 1], y = cycle[i];
    ans[row][x] = ans[row][y] = (x < y ? '/' : '\\');
    row--;
  }
}

void solveCycle(vector<int> cycle, int spareCol, int &row)
{
  rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
  ans[row][spareCol] = '\\';
  for (int i = int(cycle.size()) - 1; i; i--)
  {
    int x = cycle[i - 1], y = cycle[i];
    ans[row][x] = ans[row][y] = (x < y ? '/' : '\\');
    row--;
  }
  // cycle.back() -> spareCol -> cycle[0]
  ans[row][spareCol] = ans[row][cycle[0]] = '/';
  row--;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    ans[i] = string(n, '.');
  }
  auto cycles = findAllCycles();

  if (cycles.empty()) cout << n << endl;
  else
  {
    int row = n - 1, spareCol = cycles[0][0];
    solveFirstCycle(cycles[0], row);
    for (int i = 1; i < cycles.size(); i++)
      solveCycle(cycles[i], spareCol, row);
    cout << n - 1 << endl;
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << endl;
}