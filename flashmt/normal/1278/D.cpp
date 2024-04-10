#include <bits/stdc++.h>
using namespace std;

int ds[500500];

int get(int x)
{
  return ds[x] == x ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  pair<int, int> a[500500];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
    ds[i] = i;
  }

  sort(a, a + n);
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++)
  {
    auto [l, r] = a[i];
    auto it = s.lower_bound(make_pair(l, 0));
    while (it != s.end() && it->first < r)
    {
      int curDs = get(it->second);
      it++;
      if (curDs == i)
      {
        cout << "NO" << endl;
        return 0;
      }
      ds[curDs] = i;
    }
    s.insert({r, i});
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += get(i) == i;
  cout << (cnt == 1 ? "YES" : "NO") << endl;
}