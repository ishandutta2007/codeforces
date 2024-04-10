#include <bits/stdc++.h>
using namespace std;

int n, num[22], f[1 << 15], tr[1 << 15][15];
long long a[22][5555], sum[22], sumAll;
map<long long, int> m;

void updateTr(int mask, int submask)
{
  for (int i = 0; i < n; i++)
    if (submask >> i & 1)
      tr[mask][i] = tr[submask][i];
}

int solve(int mask)
{
  if (!mask)
    return 1;
  if (f[mask] >= 0)
    return f[mask];
  f[mask] = 0;

  int id = -1;
  for (int i = 0; i < n; i++)
    if (mask >> i & 1)
    {
      id = i;
      break;
    }

  // put in the same box
  if (sum[id] * n == sumAll)
  {
    int submask = mask ^ 1 << id;
    tr[mask][id] = a[id][0];
    if (solve(submask))
    {
      updateTr(mask, submask);
      return f[mask] = 1;
    }
    return f[mask] = 0;
  }

  // find a cycle of boxes
  for (int j = 0; j < num[id]; j++)
  {
    vector<int> flag(n, 0);
    int i = id, isGood = 1;
    long long value = a[i][j];
    while (!flag[i])
    {
      tr[mask][i] = value;
      flag[i] = 1;
      value += sumAll / n - sum[i];
      // no box has this value
      if (!m.count(value))
      {
        isGood = 0;
        break;
      }
      i = m[value];
      // found a box that has already been used
      if (mask >> i & 1 ^ 1)
      {
        isGood = 0;
        break;
      }
      // found a cycle
      if (flag[i])
      {
        if (i != id || value != a[id][j])
          isGood = 0;
        break;
      }
    }

    if (!isGood)
      continue;

    int submask = 0;
    for (int i = 0; i < n; i++)
      if ((mask >> i & 1) && !flag[i])
        submask |= 1 << i;

    if (solve(submask))
    {
      updateTr(mask, submask);
      return f[mask] = 1;
    }
  }

  return f[mask] = 0;
}

void trace(int mask)
{
  vector<int> putTo(n, -1);
  for (int i = 0; i < n; i++)
  {
    long long need = sumAll / n - (sum[i] - tr[mask][i]);
    for (int j = 0; j < n; j++)
      if (tr[mask][j] == need)
        putTo[j] = i;
  }
  for (int i = 0; i < n; i++)
  {
    assert(putTo[i] >= 0);
    cout << tr[mask][i] << ' ' << putTo[i] + 1 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num[i];
    for (int j = 0; j < num[i]; j++)
    {
      cin >> a[i][j];
      sum[i] += a[i][j];
      m[a[i][j]] = i;
    }
    sumAll += sum[i];
  }

  if (llabs(sumAll) % n)
  {
    cout << "No" << endl;
    return 0;
  }

  memset(f, -1, sizeof f);
  if (solve((1 << n) - 1))
  {
    cout << "Yes" << endl;
    trace((1 << n) - 1);
  }
  else cout << "No" << endl;
}