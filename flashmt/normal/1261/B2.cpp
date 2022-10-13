#include <bits/stdc++.h>
using namespace std;

int n, tree[200200], ans[200200];
vector<pair<int, int>> q[200200];

void add(int x)
{
  for (int i = x + 1; i <= n; i += i & -i)
    tree[i]++;
}

int get(int x)
{
  int res = 0;
  for (int i = x + 1; i; i -= i & -i)
    res += tree[i];
  return res;
}

void process(int k)
{
  if (q[k].empty())
    return;
  sort(q[k].begin(), q[k].end());
  int last = 0;
  for (auto [pos, id] : q[k])
  {
    int low = last, high = n - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (get(mid) >= pos)
      {
        ans[id] = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }

    last = ans[id];
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<int, int>> a;
  int original[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    original[i] = x;
    a.push_back({-x, i});
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int k, pos;
    cin >> k >> pos;
    q[k].push_back({pos, i});
  }

  sort(a.begin(), a.end());
  for (int i = 0; i < n;)
  {
    int ii = i;
    while (ii < n && a[ii].first == a[i].first)
    {
      add(a[ii++].second);
      process(ii);
    }
    i = ii;
  }

  for (int i = 0; i < m; i++)
    cout << original[ans[i]] << '\n';
}