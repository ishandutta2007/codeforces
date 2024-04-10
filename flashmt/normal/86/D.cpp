#include <bits/stdc++.h>
using namespace std;
const int K = 450;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<int> id(q);
  iota(begin(id), end(id), 0);
  auto cmp = [&](int u, int v) -> int
  {
    if (l[u] / K != l[v] / K)
      return l[u] < l[v];
    return (l[u] / K & 1) ^ (r[u] < r[v]);
  };
  sort(begin(id), end(id), cmp);


  vector<int> cnt(1e6 + 1);
  int curL = 0, curR = 0;
  cnt[a[0]]++;
  long long value = a[0];

  auto update = [&](int x, int v)
  {
    value -= 1LL * x * cnt[x] * cnt[x];
    cnt[x] += v;
    value += 1LL * x * cnt[x] * cnt[x];
  };

  vector<long long> ans(q);
  for (int i : id)
  {
    while (curL > l[i])
      update(a[--curL], 1);
    while (curL < l[i])
      update(a[curL++], -1);
    while (curR < r[i])
      update(a[++curR], 1);
    while (curR > r[i])
      update(a[curR--], -1);
    ans[i] = value;
  }

  for (auto x : ans)
    cout << x << '\n';
}