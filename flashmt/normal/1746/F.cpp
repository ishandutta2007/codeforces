#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int K = 30;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
map<int, vector<int>> m;

struct FenwickTree
{
  int n, mod;
  vector<long long> a;

  FenwickTree(int n): n(n)
  {
    a = vector<long long>(n + 1, 0);
  }

  void add(int x, int v)
  {
    for (int i = x; i <= n; i += i & -i)
      a[i] += v;
  }

  long long get(int x)
  {
    long long res = 0;
    for (int i = x; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

vector<int> getMapping(int x)
{
  if (!m.count(x))
  {
    vector<int> h(K);
    for (auto &x : h)
      x = rng() & ((1LL << 30) - 1);
    return m[x] = h;
  }
  return m[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<FenwickTree*> trees;
  for (int i = 0; i < K; i++)
    trees.push_back(new FenwickTree(n));
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    auto h = getMapping(a[i]);
    for (int j = 0; j < K; j++)
      trees[j]->add(i + 1, h[j]);
  }

  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int i, x;
      cin >> i >> x;
      i--;
      auto oldH = getMapping(a[i]);
      auto h = getMapping(x);
      for (int j = 0; j < K; j++)
        trees[j]->add(i + 1, h[j] - oldH[j]);
      a[i] = x;
    }
    else
    {
      int l, r, k, ans = 1;
      cin >> l >> r >> k;
      l--;
      for (int i = 0; i < K; i++)
        if ((trees[i]->get(r) - trees[i]->get(l)) % k)
        {
          ans = 0;
          break;
        }

      cout << (ans ? "YES" : "NO") << '\n';
    }
  }
}