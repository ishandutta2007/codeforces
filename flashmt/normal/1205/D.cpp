#include <bits/stdc++.h>
using namespace std;

int n, sz[1010], par[1010], ans[1010][1010];
vector<int> a[1010];

void visit(int x)
{
  sz[x] = 1;
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      visit(y);
      sz[x] += sz[y];
    }
}

// find a root and a way to partition its children into 2 group in [n/3, 2n/3]
tuple<int, vector<int>, vector<int>> findRoot()
{
  for (int x = 1; x <= n; x++)
  {
    vector<pair<int, int>> children;
    for (int y : a[x])
      if (y != par[x])
        children.push_back({sz[y], y});
    if (par[x])
      children.push_back({n - sz[x], par[x]});
    sort(children.begin(), children.end(), greater<pair<int, int>>());
    if (children[0].first * 3 > n * 2)
      continue;

    int firstHalfSize = 0;
    vector<int> firstHalf, secondHalf;
    for (int i = children.size() - 1; i >= 0; i--)
      secondHalf.push_back(children[i].second);
    for (auto u : children)
    {
      firstHalfSize += u.first;
      firstHalf.push_back(u.second);
      secondHalf.pop_back();
      if (firstHalfSize * 3 >= n && firstHalfSize * 3 <= n * 2)
        return {x, firstHalf, secondHalf};
    }
  }
  // we shouldn't be here
  assert(0);
  return {0, {}, {}};
}

// assign values for subtree x and return max value covered
int assign(int x, int prev, int coef)
{
  int maxValue = 0;
  for (int y : a[x])
    if (y != prev)
    {
      ans[x][y] = ans[y][x] = min(int(1e6), ++maxValue * coef);
      maxValue += assign(y, x, coef);
    }
  return maxValue;
}

int main()
{
  int x, y;
  cin >> n;
  if (n == 1)
    return 0;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1);
  auto p = findRoot();
  int root = get<0>(p);
  vector<int> firstHalf = get<1>(p), secondHalf = get<2>(p);

  int firstHalfValue = 0;
  for (auto x : firstHalf)
  {
    ans[root][x] = ans[x][root] = ++firstHalfValue;
    firstHalfValue += assign(x, root, 1);
  }
  firstHalfValue++;

  int secondHalfValue = 0;
  for (auto x : secondHalf)
  {
    ans[root][x] = ans[x][root] = min(int(1e6), ++secondHalfValue * firstHalfValue);
    secondHalfValue += assign(x, root, firstHalfValue);
  }

  for (int x = 1; x < n; x++)
    for (int y : a[x])
      if (y > x)
        cout << x << ' ' << y << ' ' << ans[x][y] << endl;
}