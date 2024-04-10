#include <bits/stdc++.h>
using namespace std;
const int K = 330;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for (int i = 0; i < n; i++)
    cin >> t[i];
  vector<long long> a(n + 1);
  map<long long, int> allA;
  allA[0] = allA[k] = allA[-k] = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (t[i] == 1) a[i + 1] = a[i] + x;
    else a[i + 1] = a[i] - x;
    allA[a[i + 1]] = allA[a[i + 1] + k] = allA[a[i + 1] - k] = 0;
  }

  int numA = 0;
  for (auto [k, _] : allA)
    allA[k] = numA++;
  vector<int> leftA(n + 1), rightA(n + 1);
  for (int i = 0; i <= n; i++)
  {
    leftA[i] = allA[a[i] + k];
    rightA[i] = allA[a[i] - k];
    a[i] = allA[a[i]];
  }

  int q;
  cin >> q;
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--;
  }

  vector<int> id(q);
  iota(begin(id), end(id), 0);
  auto cmp = [&](int u, int v) -> int
  {
    if (l[u] / K != l[v] / K)
      return l[u] < l[v];
    return l[u] / K & 1 ? r[u] < r[v] : r[u] > r[v];
  };
  sort(begin(id), end(id), cmp);

  vector<int> cnt(numA);
  int curL = 0, curR = 1;
  cnt[a[0]]++;
  cnt[a[1]]++;
  long long value = a[0] == rightA[1];
  vector<long long> ans(q);
  for (int i : id)
  {
    while (curL > l[i])
    {
      value += cnt[leftA[--curL]];
      cnt[a[curL]]++;
    }
    while (curL < l[i])
    {
      cnt[a[curL]]--;
      value -= cnt[leftA[curL++]];
    }
    while (curR < r[i])
    {
      value += cnt[rightA[++curR]];
      cnt[a[curR]]++;
    }
    while (curR > r[i])
    {
      cnt[a[curR]]--;
      value -= cnt[rightA[curR--]];
    }

    ans[i] = value;
  }

  for (auto x : ans)
    cout << x << '\n';
}