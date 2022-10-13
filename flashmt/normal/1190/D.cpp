#include <bits/stdc++.h>
using namespace std;

int n, tree[200200];

void add(int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i] += v;
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cnt[200200];
  pair <int, int> a[200200];
  map <int, int> allX;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].second >> a[i].first;
    allX[a[i].second] = 0;
  }

  int id = 0;
  for (auto u : allX)
  {
    allX[u.first] = ++id;
    add(id, 1);
  }
  for (int i = 0; i < n; i++)
  {
    a[i].second = allX[a[i].second];
    cnt[a[i].second]++;
  }

  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n;)
  {
    int ii = i + 1;
    while (ii < n && a[ii].first == a[i].first)
      ii++;
    int lastX = 0;
    for (int j = i; j < ii; j++)
    {
      int cntLeft = get(a[j].second) - get(lastX);
      int cntRight = get(n) - get(a[j].second - 1);
      ans += 1LL * cntLeft * cntRight;
      lastX = a[j].second;
    }
    for (int j = i; j < ii; j++)
    {
      cnt[a[j].second]--;
      if (!cnt[a[j].second])
        add(a[j].second, -1);
    }

    i = ii;
  }

  cout << ans << endl;
}