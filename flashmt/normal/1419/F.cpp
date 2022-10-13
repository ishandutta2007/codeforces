#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n, X, Y;
vector<int> a, b, allX, allY, ds;
vector<pair<int, int>> row[N], col[N];
vector<vector<int>> l, r, u, d;

void init()
{
  allX = a;
  sort(begin(allX), end(allX));
  allY = b;
  sort(begin(allY), end(allY));
  X = unique(begin(allX), end(allX)) - begin(allX);
  allX.resize(X);
  Y = unique(begin(allY), end(allY)) - begin(allY);
  allY.resize(Y);

  for (int i = 0; i < n; i++)
  {
    a[i] = lower_bound(begin(allX), end(allX), a[i]) - begin(allX);
    b[i] = lower_bound(begin(allY), end(allY), b[i]) - begin(allY);
    row[b[i]].push_back({a[i], i});
    col[a[i]].push_back({b[i], i});
  }

  l = r = u = d = vector<vector<int>>(X, vector<int>(Y, -1));
  for (int i = 0; i < X; i++)
  {
    sort(begin(col[i]), end(col[i]));
    for (auto [j, id] : col[i])
      u[i][j] = d[i][j] = id;
    for (int j = 1; j < Y; j++)
      if (d[i][j] < 0)
        d[i][j] = d[i][j - 1];
    for (int j = Y - 2; j >= 0; j--)
      if (u[i][j] < 0)
        u[i][j] = u[i][j + 1];
  }
  for (int i = 0; i < Y; i++)
  {
    sort(begin(row[i]), end(row[i]));
    for (auto [j, id] : row[i])
      l[j][i] = r[j][i] = id;
    for (int j = 1; j < X; j++)
      if (l[j][i] < 0)
        l[j][i] = l[j - 1][i];
    for (int j = X - 2; j >= 0; j--)
      if (r[j][i] < 0)
        r[j][i] = r[j + 1][i];
  }
}

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int isGood(int mid)
{
  iota(begin(ds), end(ds), 0);
  for (int i = 0; i < Y; i++)
    for (int j = 1; j < size(row[i]); j++)
    {
      int u = row[i][j - 1].second, v = row[i][j].second;
      if (allX[a[v]] - allX[a[u]] <= mid)
        ds[get(u)] = get(v);
    }

  for (int i = 0; i < X; i++)
    for (int j = 1; j < size(col[i]); j++)
    {
      int u = col[i][j - 1].second, v = col[i][j].second;
      if (allY[b[v]] - allY[b[u]] <= mid)
        ds[get(u)] = get(v);
    }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += get(i) == i;

  if (cnt == 1)
    return 1;

  if (cnt == 2)
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (get(i) != get(j))
        {
          if (a[i] == a[j] && abs(allY[b[i]] - allY[b[j]]) <= mid * 2LL)
            return 1;
          if (b[i] == b[j] && abs(allX[a[i]] - allX[a[j]]) <= mid * 2LL)
            return 1;
        }

  for (int x = 0; x < X; x++)
    for (int y = 0; y < Y; y++)
    {
      set<int> s;
      int i = l[x][y];
      if (i >= 0 && allX[x] - allX[a[i]] <= mid)
        s.insert(get(i));

      i = r[x][y];
      if (i >= 0 && allX[a[i]] - allX[x] <= mid)
        s.insert(get(i));

      i = u[x][y];
      if (i >= 0 && allY[b[i]] - allY[y] <= mid)
        s.insert(get(i));

      i = d[x][y];
      if (i >= 0 && allY[y] - allY[b[i]]<= mid)
        s.insert(get(i));

      if (size(s) == cnt)
        return 1;
    }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
  }

  init();
  ds.resize(n);

  int low = 1, high = 2e9, ans = high + 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (isGood(mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << (ans > 2e9 ? -1 : ans) << endl;
}