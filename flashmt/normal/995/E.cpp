#include <bits/stdc++.h>
using namespace std;
const int K = 40000;
const int REV[] = {1, 0, 2};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long x, long long y, int base)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1, base);
  res = res * res % base;
  if (y & 1)
    res = res * x % base;
  return res;
}

void go(int x, int p, unordered_map<int, int> &tr)
{
  int lastOp = -1;
  for (int step = 0; step < 95; step++)
  {
    int op = rng() % 3;
    if (op == REV[lastOp])
      op = (op + 1) % 3;
    if (!op) x = (x + 1) % p;
    else if (op == 1) x = (x + p - 1) % p;
    else x = power(x, p - 2, p);
    if (!tr.count(x))
      tr[x] = op;
    lastOp = op;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int u, v, p;
  cin >> u >> v >> p;
  unordered_map<int, int> trU;
  trU[u] = -1;
  for (int i = 0; i < K; i++)
    go(u, p, trU);

  unordered_map<int, int> trV;
  trV[v] = -1;
  for (int i = 0; i < K; i++)
    go(v, p, trV);

  for (auto [x, _] : trU)
    if (trV.count(x))
    {
      vector<int> ans;
      int y = x;
      while (y != u)
      {
        ans.push_back(trU[y]);
        if (!ans.back()) y = (y + p - 1) % p;
        else if (ans.back() == 1) y = (y + 1) % p;
        else y = power(y, p - 2, p);
      }
      reverse(begin(ans), end(ans));
      y = x;
      while (y != v)
      {
        int tr = trV[y];
        ans.push_back(REV[tr]);
        if (!tr) y = (y + p - 1) % p;
        else if (tr == 1) y = (y + 1) % p;
        else y = power(y, p - 2, p);
      }

      cout << size(ans) << '\n';
      for (int u : ans)
        cout << u + 1 << ' ';
      return 0;
    }

  assert(0);
}